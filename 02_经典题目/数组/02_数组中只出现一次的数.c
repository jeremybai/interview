/****************************************************************************
 * @file     02_数组中只出现一次的数.c
 * @brief    一个整型数组里除了两数字之外，其他的数字都出现了两次。请写程序找
			 出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)
 * @version  V1.00
 * @date     2014.9.2
 * @note     
****************************************************************************/
#include <stdio.h>
#include <malloc.h>


/** 
 * @brief     数组中只出现一次的一个数
 * @param[in] array       数组的起始地址
 * @param[in] array_len   数组的长度
 * @retval    0：成功	-1：参数有误
 * @see       None
 * @note      		  
 */
int FindNumAppearOnce(int* array, int array_len, int* Num)
{
	if(NULL == array || 0 == array_len)
	{
		printf("参数有误\n");
		return -1;
	}
	int i;
	*Num = 0;
	for(i = 0; i < array_len; i++)
	{
		*Num ^= array[i];
	}
	return 0;
}

/** 
 * @brief     数组中只出现一次的两个数
 * @param[in] array       数组的起始地址
 * @param[in] array_len   数组的长度
 * @retval    0：成功	-1：参数有误	-2：不存在只出现一次的两个数
 * @see       None
 * @note      		  
 */
int FindNumsAppearOnce(int* array, int array_len, int* Num1, int* Num2)
{
	if(NULL == array || 0 == array_len)
	{
		printf("参数有误\n");
		return -1;
	}
	int i;
	int xor = 0,flag,xor1 = 0,xor2 = 0;
	for(i = 0; i < array_len; i++)
	{
		xor ^= array[i];
	}
	i = 0;
	//找出所有数的异或值中不为0的一位
	while(!(xor & (1<<i)) && i < 8*sizeof(int))
	{
		i++;
	}
	if(8*sizeof(int) == i)
	{
		printf("数组中不存在只出现一次的两个数");
		return -2;
	}
	flag = 1<<i;
	//根据不为0的一位将数组分为两部分，此时2个不同的数分别存在于这两个数组中
	for(i = 0; i < array_len; i++)
	{
		if(array[i] & flag)
			xor1 ^= array[i];
		else
			xor2 ^= array[i];
	}
	*Num1 = xor1;
	*Num2 = xor2;
	return 0;
}
 
int main()
{
	int test[] = {1,2,3,4,5,6,7,3,7,6,1,2,4};
	int test1[] = {1,2,3,4,5,6,5,3,7,6,1,2};
	int num = 0,num1,num2;
	FindNumAppearOnce(test,sizeof(test)/sizeof(int), &num);
	FindNumsAppearOnce(test1,sizeof(test1)/sizeof(int), &num1, &num2);	
	printf("%d\r\n",num);
	printf("%d	%d\r\n",num1,num2);
}