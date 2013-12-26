/**************************************************************************
 * @file     输入函数区别.c
 * @brief    了解scanf()/getchar()和gets()等函数
 * @version  V1.00
 * @date     2013.12.25
 * @note     
****************************************************************************/
#include <stdio.h>

#define SCANF
int main()
{
#ifdef SCANF
	printf("SCANF TEST\n");
	char ch1, ch2;
	scanf("%c", &ch1); 
	scanf("%c", &ch2);
	printf("%d %d\n", ch1, ch2);
	return 0;
#elif defined GETCHAR   
	printf("GETCHAR TEST\n")
	char ch1, ch2;
	ch1 = getchar();
	ch2 = getchar();
	printf("%d %d\n", ch1, ch2);
	return 0;
#endif	
}

    
	