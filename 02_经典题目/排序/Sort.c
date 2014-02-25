/****************************************************************************
 * @file     Sort.c
 * @brief    基本排序算法实现。
 * @version  V1.00
 * @date     2014.2.24
 * @note      
****************************************************************************/
#include <stdio.h>
#include <stdint.h>
/** 
 * @brief     冒泡排序函数实现从小到大排序。
 * @param[in] a  数组起始地址
 * @param[in] n  数组大小
 * @retval    None
 * @see       None
 * @note      None
 */
int BubleSort(int *array, int length)
{
	if((NULL == array) || length < 1)
	{
		printf("输入参数有误\n");
		return 1;
	}
	int i,j;
	for(i = 0; i < length-1; i++)
	{
		for(j = 0; j < length-1-i; j++)
		{
			if(array[j] > array[j+1])
			{
				array[j] ^= array[j+1];
				array[j+1] ^= array[j];
				array[j] ^= array[j+1];
			}
		}
	}
	return 0;
}


int main()
{
	int ForSort[10] = {9,1,8,2,7,3,4,6,5,0},i;
	if(0 == BubleSort(ForSort,10))
	{	
		for(i = 0; i < 10; i++)
		{
			printf("%d   ",ForSort[i]);
		}
	}
}
