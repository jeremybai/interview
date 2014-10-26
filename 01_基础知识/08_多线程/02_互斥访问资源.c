/****************************************************************************
 * @file     02_互斥访问资源.c
 * @brief    单个读写者对一块资源读写
 * @version  V1.00
 * @date     2014.10.24
 * @note     使用互斥达到交替访问的目的
****************************************************************************/
#include <stdio.h> 
#include <pthread.h> 
#include <windows.h>

void reader_function(void);
void writer_function(void);

int buffer_has_item = 0;
pthread_mutex_t mutex;

main()
{
	pthread_t reader;
	//pthread_t writer;
	pthread_mutex_init(&mutex, NULL);
	pthread_create( &reader, NULL, (void*)&reader_function,	NULL);
	//pthread_create( &writer, NULL, (void*)&writer_function,	NULL);
	writer_function();
	//不需要使用mutex可以使用pthread_mutex_destroy(&mutex)释放 mutex。
}

void writer_function(void)
{
	while(1)
	{
		pthread_mutex_lock( &mutex );
		if ( buffer_has_item == 0 )
		{
			printf("make_new_item\n");
			buffer_has_item = 1;
		}
		pthread_mutex_unlock( &mutex );
	}
}

void reader_function(void)
{
	while(1)
	{
		pthread_mutex_lock( &mutex );
		if ( buffer_has_item == 1)
		{
			printf("consume_item\n");
			buffer_has_item = 0;
		}
		pthread_mutex_unlock( &mutex );
	}
}


