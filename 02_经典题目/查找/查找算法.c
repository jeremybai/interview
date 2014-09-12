/****************************************************************************
* @file     Search.c
* @brief    5种查找算法实现及复杂度稳定性。
* @version  V1.00
* @date     2014.9.10
* @note     
****************************************************************************/
#include<stdio.h>


/**		二分查找   
 *     
 *		采用迭代求解。    
 */ 
int BinarySearch_Iteration(int* array, int length, int data)
{
	if(NULL == array || 0 == length)
	{
		printf("参数错误！\r\n");
		return 1;
	}
	int low = 0, high = length - 1;
	int middle = length>>2;
	while(low <= high)
	{
		//left与right的值比较大的时候，其和可能溢出
		middle = low + ((high - low)>>1);
		if(array[middle] > data)
		{
			high = middle - 1;
		}
		else if(array[middle] < data)
		{
			low = middle + 1;
		}
		else
		{
			printf("找到data，位置：%d\r\n",middle);
			return 0;
		}
	}
		
}
/**		二分查找   
 *     
 *		采用递归求解。    
 */ 
int BinarySearch_Recursion(int* array, int low, int high, int data)
{
	if(NULL == array)
	{
		printf("参数错误！\r\n");
		return 1;
	}
	int middle;
	if(low <= high)
	{
		//left与right的值比较大的时候，其和可能溢出
		middle = low + ((high - low)>>1);
		if(array[middle] > data)
		{
			BinarySearch_Recursion(array, low, middle - 1, data);
		}
		else if(array[middle] < data)
		{
			BinarySearch_Recursion(array, middle + 1, high, data);
		}
		else
		{
			printf("找到data，位置：%d\r\n",middle);
			return 0;
		}
	}
		
}
/**		二分查找   
 *     
 *		连续相同的数字，返回第一个匹配位置还是最后一个匹配位置，由函数传入参数决定。    
 */ 
int BinarySearch(int* array, int length, int data, int flag)
{
	if(NULL == array || 0 == length)
	{
		printf("参数错误！\r\n");
		return 1;
	}
	int low = 0, high = length - 1, middle;
	while(low + 1 < high)
	{
		//left与right的值比较大的时候，其和可能溢出
		middle = low + ((high - low)>>1);
		if(array[middle] > data)
		{
			high = middle - 1;
		}
		else if(array[middle] < data)
		{
			low = middle + 1;
		}
		else
		{
			//flag = 1找出重复的最后一个位置
			if(flag == 1)
				low = middle;
			else
			//flag = 0找出重复的第一个位置
				high = middle;
		}
	}
	if(flag == 1)
	{
		if(array[high] == data)
			return high;
		else if(array[low] == data)
			return low;
	}
	else
	{
		if(array[low] == data)
			return low;
		else if(array[high] == data)
			return high;
	}
	return -1;	
}

int main()
{
	int array[] = {1,2,2,3,4,4,5,6,7,7};
	printf("%d",BinarySearch(array, sizeof(array)/sizeof(array[0]),5,1));
}