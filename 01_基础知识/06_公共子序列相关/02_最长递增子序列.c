/****************************************************************************
* @file     03_最长递增子序列.c
* @brief    求最长递增子序列
* @version  V1.00
* @date     2014.9.1
* @note     法1：最长公共子序列法，原数组为A，我们对A进行排序，排序后的数组为
			A'。我们有了这样的两个数组后，如果想求数组A的最长递增子序列，其实
			就是求数组A与它的排序数组A'的最长公共子序列。
			法2：动态规划 时间复杂度O(n^2)
****************************************************************************/
#include <stdio.h> 
#include <string.h>

/**        求数组中最大值   
 *     
 *     求数组中最大的一个元素。    
 */
int Max(int* array, int array_len)
{
	int i,max = array[0];
	for(i = 1; i < array_len; i++)
	{
		if(array[i] > max)
			max = array[i];
	}
	return max;
}

/** 
 * @brief   求array的连续子数组的最大个数。
 * @param   array       array的首指针 
 * @param   array_len   array的长度 
 * @retval  连续子数组的最大个数	-1：输入参数有误	-2：申请空间失败。
 * @see     None
 * @note    动态规划
 */
int LongestIncreaseSequence(int* array, int array_len)
{
	if(NULL == query || NULL == text || 0 == query_len || 0 == text_len)
	{
		printf("输入参数有误\r\n");
		return -1;
	}
	int *LIS;
	if(NULL == (LIS = (int*)malloc(sizeof(int)*array_len)))
	{
		printf("申请空间失败!\r\n");
		return -2;
	}
	int i,j;
	for(i = 0; i < array_len; i++)
	{
		LIS[i] = 1;
		for(j = 0; j < i; j++)
		{
			if(array[i] > array[j] && LIS[j] + 1 > LIS[i])
			{
				LIS[i] = LIS[j] + 1;
			}
		}
	}	
	return Max(LIS, array_len);
} 


int main()
{
	int max,array[] = {1,-1,2,-3,4,-5,6,-7};
	max = LongestIncreaseSequence(array, sizeof(array)/sizeof(int));
	printf("%d\r\n", max);
}
