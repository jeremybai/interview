/****************************************************************************
* @file     01_创建多个线程.c
* @brief    创建两个线程，分别打印hello和world
* @version  V1.00
* @date     2014.10.24
* @note     （1）两个线程的执行顺序无法保证
			（2）主函数创建完两个线程就会结束，所有的线程也都会结束，打印数据
			可能来不及执行。在任何一个 thread （不论 parent or child）
			里呼叫 exit 都将导致 process 结束，而所有的 thread 也跟着一起结
			束了。所以如果要结束一个 thread ，我们必须使用 pthread_exit 
			这个函数。
****************************************************************************/
#include <stdio.h> 
#include <pthread.h> 
#include <windows.h>

void* PrintMsg(void *threadid) 
{
	char* tid; 
	tid = (char*)threadid; 
	printf("thread id= #%s!\n", tid); 
	pthread_exit(NULL); 
} 

main()
{
	pthread_t thread1, thread2;
	char message1[] = "hello";
	char message2[] = "world";
	void*status;
	
	pthread_create( &thread1, NULL,	PrintMsg, (void*) &message1);
	pthread_create( &thread2, NULL, PrintMsg, (void*) &message2);
	
	pthread_join(thread1, &status);
	pthread_join(thread2, &status);
	//Sleep(1000);
	exit(0);
}

