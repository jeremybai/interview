/****************************************************************************
 * @file     MergeSort.c
 * @brief    归并序算法实现。
 * @version  V1.00
 * @date     2014.5.25
 * @note     最好最坏时间复杂度都是O(nlgn)，空间复杂度O(n)，赋值操作的次
			 数是(2nlogn)，平均比较次数O(nlgn)，最好比较次数O(？？)：最坏
			比较次数O(nlgn/2)
****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/** 
 * @brief     归并排序函数实现从小到大排序。
 * @param[in] array  原始数组指针
 * @param[in] temp   用于存放排序的数组
 * @param[in] begin  数组起始位置
 * @param[in] end    数组结束位置
 * @retval    错误码 0代表成功 1代表参数错误
 * @see       None
 * @note      		  
 */
int MergeSort(int *array, int *temp, int begin, int end)
{
	if(NULL == array || NULL == temp )
	{
		printf("参数错误!\n");
		return 1;
	}
	int mid;
	if(begin < end)
	{
		//将数组分成两部分，分别进行归并排序，再将两个排好序的数组进行合并
		mid = (begin + end)/2;
		MergeSort(array, temp, begin, mid);
		MergeSort(array, temp, mid + 1, end);
		Merge(array, temp, begin, mid + 1, end);
	}
	return 0;
}
/** 
 * @brief     归并排序函数实现从小到大排序。
 * @param[in] array  原始数组指针
 * @param[in] temp   用于存放排序的数组
 * @param[in] begin  数组起始位置
 * @param[in] mid    第二个数组起始位置
 * @param[in] end    数组结束位置
 * @retval    错误码 0代表成功 1代表参数错误
 * @see       None
 * @note      		  
 */
int Merge(int *array, int *temp, int begin, int mid, int end)
{
	if(NULL == array || NULL == temp )
	{
		printf("参数错误!\n");
		return 1;
	}
	int i = begin;
	int j= mid;
	int k = begin;
	//将两个数组依次进行比较，把小的存放至temp数组，再将temp数组拷贝至array
	while((i <= mid - 1) && (j <= end))
	{
		if(array[i] <= array[j])
		{
			temp[k++] = array[i++];
		}
		else
		{
			temp[k++] = array[j++];
		}
	}
	while(i <= mid-1)
	{
		temp[k++] = array[i++];
	}
	while(j <= end)
	{
		temp[k++] = array[j++];
	}
	for(i = begin; i <= end; i++)
	{
		array[i] = temp[i];
	}
	return 0;
}

int main()
{
	int ForSort2[10] = {3,2,1,0,4,5,6,7,8,9},i;
	int *p = (int*)malloc(10*sizeof(int));
	MergeSort(ForSort2,p,0,9);
	for(i = 0; i < 10; i++)
	{
		printf("%d   ",ForSort2[i]);
	}
	printf("\n");
}
