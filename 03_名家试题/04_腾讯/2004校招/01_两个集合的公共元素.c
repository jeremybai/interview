/****************************************************************************
 * @file     01_两个集合的公共元素.c
 * @brief    A、B两个整数集合，设计一个算法求他们的交集，尽可能的高效。
 * @version  V1.00
 * @date     2014.9.4
 * @note     法1：HASH表（因为是集合，所以元素满足互异性）
             法2：最长公共子序列
             法3：bitmap
****************************************************************************/
#include <stdio.h>
#include <stdbool.h>

/**
 * 构造Hash表
 */
int Hash(int* hashtable, int hash_len, int* array, int array_len) 
{
	int i;
	memset(hashtable, '0', sizeof(int)*hash_len);
	for(i = 0; i < array_len; i++)
	{
		hashtable[array[i]] = 1;
	}
}

/** 
 * 将元素放入Hash表 
*/
int LoadHashTable(int* hashtable, int hash_len, int* array, int array_len) 
{
	int i;
	for(i = 0; i < array_len; i++)
	{
		if(1 == hashtable[array[i]])
		{
			printf("%d   ",array[i]);
		}	
	}	
}

/** 
* @brief     两个集合的公共元素，集合以数组表示
* @param[in] array1       集合1的指针
* @param[in] array1_len   集合1的大小
* @param[in] array2       集合2的指针
* @param[in] array2_len   集合2的大小
* @retval    
* @see       None
* @note            
*/
void CommonElements(int* array1, int array1_len, int* array2, int array2_len) 
{
    int i, max = array1[0];
    //求出arra1的最大值
    for(i = 0; i < array1_len; i++)
    {
        if(array1[i] > max)
            max = array1[i];
    }
    for(i = 0; i < array2_len; i++)
    {
        if(array2[i] > max)
            max = array2[i];
    }
    int*hashtable;
	if(NULL == (hashtable = (int*)malloc(sizeof(int)*max)))
	{
		printf("申请空间失败!\r\n");
		return;
	}
	Hash(hashtable, max, array1, array1_len);
	LoadHashTable(hashtable, max, array2, array2_len);
	free(hashtable);
}



int main()
{
	int a[] = {1,3,4,7,9,20};
	int b[] = {3,7,12,4,9,5,14};
	CommonElements(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int));
}