/****************************************************************************
 * @file     Sort.c
 * @brief    基本排序算法实现。
 * @version  V1.00
 * @date     2014.2.24
 * @note      
****************************************************************************/
#include <stdio.h>
#include <stdint.h>

/**		内部函数  
 *     
 *		用于两个数进行交换。    
 */ 
static void Swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
/** 
 * @brief     冒泡排序函数实现从小到大排序。
 * @param[in] a  数组起始地址
 * @param[in] n  数组大小
 * @retval    None
 * @see       None
 * @note      时间复杂度O(n^2)；最好情况O(n)；最坏情况O(n^2)；
			  空间复杂度O(1)；稳定。
			  改进1：设置一个标志，如果这一趟发生了交换，则为true，否则为false。
			         明显如果有一趟没有发生交换，说明排序已经完成。
			  改进2：如果有100个数的数组，仅前面10个无序，后面90个都已排好序且
			         都大于前面10个数字，那么在第一趟遍历后，最后发生交换的位置
					 必定小于10，且这个位置之后的数据必定已经有序了，记录下这位
					 置，第二次只要从数组头部遍历到这个位置就可以了。			  
 */
int BubleSort(int *array, int length)
{
	if((NULL == array) || length < 1)
	{
		printf("输入参数有误\n");
		return 1;
	}
	int i=0,j=0,count = 0;
	for(i = 0; i < length-1; i++)
	{
		for(j = 0; j < length-1-i; j++)
		{
			if(array[j] > array[j+1])
			{
				Swap(&array[j],&array[j+1]);
			}
			count++;
		}
	}
	printf("比较次数为%d次\n",count);
	return 0;
}
/** 
 * @brief     冒泡排序函数实现从小到大排序。
 * @param[in] a  数组起始地址
 * @param[in] n  数组大小
 * @retval    None
 * @see       None
 * @note      时间复杂度O(n^2)；最好情况O(n)；最坏情况O(n^2)；
			  空间复杂度O(1)；稳定。
			  改进1：设置一个标志，如果这一趟发生了交换，则为true，否则为false。
			         明显如果有一趟没有发生交换，说明排序已经完成。		  
 */
int BubleSort1(int *array, int length)
{
	if((NULL == array) || length < 1)
	{
		printf("输入参数有误\n");
		return 1;
	}
	int i=0,j=0,flag = 0,count = 0;
	for(i = 0; i < length-1; i++)
	{
	    flag = 0;
		for(j = 0; j < length-1-i; j++)
		{
			if(array[j] > array[j+1])
			{
				Swap(&array[j],&array[j+1]);
				flag = 1;
			}
			count++;
		}
		if(flag == 0)
		{
			break;
		}
	}
	printf("比较次数为%d次\n",count);
	return 0;
}


/** 
 * @brief     冒泡排序函数实现从小到大排序。
 * @param[in] a  数组起始地址
 * @param[in] n  数组大小
 * @retval    None
 * @see       None
 * @note      时间复杂度O(n^2)；最好情况O(n)；最坏情况O(n^2)；
			  空间复杂度O(1)；稳定。
			  改进2：如果有100个数的数组，仅前面10个无序，后面90个都已排好序且
			         都大于前面10个数字，那么在第一趟遍历后，最后发生交换的位置
					 必定小于10，且这个位置之后的数据必定已经有序了，记录下这位
					 置，第二次只要从数组头部遍历到这个位置就可以了。			  
 */
int BubleSort2(int *array, int length)
{
	if((NULL == array) || length < 1)
	{
		printf("输入参数有误\n");
		return 1;
	}
	int i=0,j=0,k=0,flag = length-1-i,count = 0;
	for(i = 0; i < length-1; i++)
	{
		k = flag;
		flag = 0;
		for(j = 0; j < k; j++)
		{
			if(array[j] > array[j+1])
			{
				Swap(&array[j],&array[j+1]);
				flag = j;        //j和j+1已经交换过，j向后的数据都是有序的
			}
			count++;
		}
		if(flag == 0)
		{
			break;
		}
	}
	printf("比较次数为%d次\n",count);
	return 0;
}
int main()
{
	int ForSort[10] = {9,8,7,6,5,4,3,2,1,0},i;
	int ForSort1[10] = {0,1,2,3,4,5,6,7,8,9};
	int ForSort2[10] = {3,2,1,0,4,5,6,7,8,9};
	if(0 == BubleSort2(ForSort2,10))
	{	
		for(i = 0; i < 10; i++)
		{
			printf("%d   ",ForSort2[i]);
		}
	}
	printf("\n");
}
