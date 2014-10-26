#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include "myspinlock.h"

// 是否使用spinlock包含全局变量，默认是不使用，改为1则为使用
#define USE_SPINLOCK 0
sem_t beginSemaArr[500];

sem_t endSema;

int global_count;
int add_loops = 10000;

spinlock slock = 0;

void *threadAddFunc(void *param)
{
	long thread_id = (long)param;

	for (;;)
	{
		sem_wait(&beginSemaArr[thread_id]);  // Wait for signal
		
		for (int i = 0; i < add_loops; i++)
		{
#if USE_SPINLOCK
			spin_lock(&slock);
			global_count++;
			spin_unlock(&slock);
#else
			global_count++;
#endif
		}

		sem_post(&endSema);  // Notify transaction complete
	}
	return NULL;  // Never returns
};

int main()
{
	// Initialize the semaphores
	for (int i = 0; i < 500; i++)
		sem_init(&beginSemaArr[i], 0, 0);
	
	sem_init(&endSema, 0, 0);

	// Spawn the threads
	pthread_t threadArr[500];
	for (int i = 0; i < 500; i++)
		pthread_create(&threadArr[i], NULL, threadAddFunc, (void *)i);

	// Repeat the experiment ad infinitum
	for (int iterations = 1; ; iterations++)
	{
		// 重设 global_count
		global_count = 0;
		
		// Signal threads
		for (int j = 0; j < 500; j++)
		sem_post(&beginSemaArr[j]);
		
		// Wait for threads
		for (int j = 0; j < 500; j++)
		sem_wait(&endSema);
		
		// threads all finish, print global_count
		if (global_count != 5000000)
			printf("iter %d: global_count = %d\n", iterations, global_count);
	}
	return 0;  // Never returns
}