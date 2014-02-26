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
 * @param[in] array  数组起始地址
 * @param[in] length  数组大小
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
	int i,j;
	for(i = 0; i < length-1; i++)
	{
		for(j = 0; j < length-1-i; j++)
		{
			if(array[j] > array[j+1])
			{
				Swap(&array[j],&array[j+1]);
			}
		}
	}
	return 0;
}

/** 
 * @brief     插入排序函数实现从小到大排序。
 * @param[in] array  数组起始地址
 * @param[in] length  数组大小
 * @retval    None
 * @see       None
 * @note      时间复杂度O(n^2)；最好情况O(n)；最坏情况O(n^2)；
			  空间复杂度O(1)；稳定。			  
 */
int InsertSort(int *array, int length)
{
	if((NULL == array) || length < 1)
	{
		printf("输入参数有误\n");
		return 1;
	}
	int i = 0, j = 0, temp = 0;  
	for(i = 1; i < length; i++)
	{
		if(array[i] < array[i-1])
		{
			temp = array[i];
			for(j = i-1; j >= 0 && array[j] > temp; j--)
			{
				array[j+1] = array[j];
			}
			array[j+1] = temp;
		}
	}	
	return 0;
}

/** 
 * @brief     快速排序函数实现从小到大排序。
 * @param[in] array  数组起始地址
 * @param[in] length  数组大小
 * @retval    None
 * @see       None
 * @note      时间复杂度O(n^)；最好情况O()；最坏情况O(n^)；
			  空间复杂度O()；稳定。			  
 */
void QuickSort(int *array, int low,int high)
{
	if((NULL == array) || low < 0 || high < 0)
	{
		printf("输入参数有误\n");
		return 1;
	}
	if ( low < high ) 
	{
		int i = low, j = high, temp = array[low];
		while ( i < j ) 
		{
			//从右往左扫描，如果数组元素大于temp，则继续，直至找到第一个小于temp的元素
			while ( i < j && array[j] >= temp ) {
				--j;
			}
			if ( i < j ) {
				array[i++] = array[j];
			}
			while ( i < j && array[i] <= temp ) {
				++i;
			}
			if ( i < j ) {
				array[j--] = array[i];
			}
		}
		array[i] = temp;
		QuickSort(array, low, i - 1);
		QuickSort(array, i + 1, high);
	}
}




int main()
{
	int ForSort[10] = {9,1,8,2,7,3,4,6,5,0},i;
	int ForSort1[10] = {0,1,2,3,4,5,6,7,8,9};
	int ForSort2[10] = {9,8,7,6,5,4,3,2,1,0};
	QuickSort(ForSort2,0,9);
	for(i = 0; i < 10; i++)
	{
		printf("%d   ",ForSort2[i]);
	}
}
