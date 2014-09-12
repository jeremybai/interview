/****************************************************************************
 * @file     01_Fibonacci.c
 * @brief    递归求解斐波那契数列。
 * @version  V1.00
 * @date     2013.12.28
 * @note     时间复杂度O(n)
****************************************************************************/
#include <stdio.h>
#include <stdint.h>

/**		求斐波那契数列的第n项   
 *     
 *		采用迭代求解。    
 */ 
long long Fibonacci_Iteration(uint32_t n)
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

/**		求斐波那契数列的第n项   
 *     
 *		采用递归求解。    
 */ 
long long Fibonacci_Recursion(uint32_t n)
{
	if(n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		return Fibonacci_Recursion(n-1) + Fibonacci_Recursion(n-2);
	}
}

/**		求斐波那契数列的第n项   
 *     
 *		采用尾递归求解。    
 */ 
int factorial_tail(int n,int acc1,int acc2)
{
    if (n == 0)
    {
        return acc1;
    }
    else
    {
        return factorial_tail(n-1,acc2,acc1+acc2);
    }
}
int main()
{
	uint32_t n; 
	printf("请输入N:\n");
	
	while(EOF != scanf("%d",&n))
	{
		printf("Fibnacci数列的第%d项为：%d\n",n,factorial_tail(n, 0, 1));
	}
}

