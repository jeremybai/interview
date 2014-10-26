/****************************************************************************
 * @file     02_打印小于n的所有素数.c
 * @brief    
 * @version  V1.00
 * @date     2014.9.28
 * @note     
 * @note     
 ****************************************************************************/
#include <stdio.h>
#include <math.h>
/** 
 * @brief     打印小于n的所有素数
 * @param[in] n     输入的参数
 * @retval    
 * @see       None
 * @note      
 */
int IsPrime(int n)
{
	if(1 == n)
		return n;
	int i,k = (int)sqrt(n);
	for(i = 2; i <= k; i++)
	{
		if(n % i == 0)
			return 0;
	}
	return 1;
} 

int main()
{	
	int n = 10, i;
	for(i = 1; i < n; i++)
	{
		if(IsPrime(i))
			printf("%d  ",i);
	}
}