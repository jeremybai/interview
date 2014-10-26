/****************************************************************************
* @file     04_闹钟问题.c
* @brief     
* @version  V1.00
* @date     2014.10.26
* @note     使用互斥达到交替访问的目的
****************************************************************************/
#include <stdio.h> 
#include <pthread.h> 
#include <windows.h>
#include <semaphore.h> 
void reader_function(void);
void writer_function(void);
struct timespec delay;
sem_t writers_turn;
sem_t readers_turn;


main()
{
	pthread_t reader;
	delay.tv_sec = 2;
	delay.tv_nsec = 0;
	
	sem_init( &readers_turn , 0, 1);
	sem_init( &writers_turn , 0, 1);

	//使reader任务阻塞，writer任务先执行
	sem_wait( &readers_turn );

	pthread_create( &reader, NULL, (void *)&reader_function, NULL);
	writer_function();
}

void writer_function(void)
{
	while(1)
	{
		sem_wait( &writers_turn );
		printf("make_new_item\n");
		pthread_delay_np( &delay );
		sem_post( &readers_turn );
	}
}

void reader_function(void)
{
	while(1)
	{
		sem_wait( &readers_turn );
		printf("consume_item\n");
		pthread_delay_np( &delay );
		sem_post( &writers_turn );
	}
}


