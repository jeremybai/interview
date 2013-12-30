/****************************************************************************
 * @file     01_Fibonacci.c
 * @brief    递归求解斐波那契数列。
 * @version  V1.00
 * @date     2013.12.28
 * @note     时间复杂度O(n)
****************************************************************************/
#include <stdio.h>
#include <stdint.h>

long long Fibonacci(uint32_t n)
{
	if(n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		uint32_t i = 2;
		long long fibn,first = 0,last = 1;
		while(i++ <= n)
		{
			fibn = first + last;
			first = last;
			last = fibn;
		}
		return fibn;
	}
}

int main()
{
	uint32_t n; 
	printf("请输入N:\n");
	
	scanf("%d",&n);
	while(1)
	{
		printf("Fibnacci数列的第%d项为：%d\n",n,Fibonacci(n));
		scanf("%d",&n);
	}
}

