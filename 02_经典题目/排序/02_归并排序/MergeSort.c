/****************************************************************************
 * @file     MergeSort.c
 * @brief    归并序算法实现。
 * @version  V1.00
 * @date     2014.5.25
 * @note      
****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
/**		内部函数  
 *     
 *		用于两个数进行交换。    
 */ 

/** 
 * @brief     归并排序函数实现从小到大排序。
 * @param[in] a  数组起始地址
 * @param[in] n  数组大小
 * @retval    None
 * @see       None
 * @note      		  
 */
int _mergeSort(int *arr, int *temp, int left, int right)
{
	int mid;
	if (right > left)
	{
		/* Divide the array into two parts and call _mergeSortAndCountInv()
	for each of the parts */
		mid = (right + left)/2;

		/* Inversion count will be sum of inversions in left-part, right-part
	and number of inversions in merging */
		_mergeSort(arr, temp, left, mid);
		_mergeSort(arr, temp, mid+1, right);

		/*Merge the two parts*/
		Merge(arr, temp, left, mid+1, right);
	}
	return 0;
}

int Merge(int *arr, int *temp, int left, int mid, int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left; /* i is index for left subarray*/
	j = mid;  /* i is index for right subarray*/
	k = left; /* i is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right))
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}

	/* Copy the remaining elements of left subarray
(if there are any) to temp*/
	while (i <= mid - 1)
	temp[k++] = arr[i++];

	/* Copy the remaining elements of right subarray
(if there are any) to temp*/
	while (j <= right)
	temp[k++] = arr[j++];

	/*Copy back the merged elements to original array*/
	for (i=left; i <= right; i++)
	arr[i] = temp[i];
}

int main()
{
	int ForSort[10] = {9,8,7,6,5,4,3,2,1,0},i;
	int ForSort1[10] = {0,1,2,3,4,5,6,7,8,9};
	int ForSort2[10] = {3,2,1,0,4,5,6,7,8,9};
	int *p = (int*)malloc(10*sizeof(int));
	_mergeSort(ForSort2,p,0,9);
	for(i = 0; i < 10; i++)
	{
		printf("%d   ",ForSort2[i]);
	}
	printf("\n");
}

