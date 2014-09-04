/****************************************************************************
 * @file     01_两个集合的公共元素.c
 * @brief    A、B两个整数集合，设计一个算法求他们的交集，尽可能的高效。
 * @version  V1.00
 * @date     2014.9.4
 * @note     法1：HASH表（因为是集合，所以元素满足互异性）
			 法2：压缩集合，求出两集合上下界，重合的即为公共元素，再除去不在
				  这个范围内的元素，循环操作，直到没有重合
             法2：最长公共子序列
             法3：bitmap
****************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXNUM 200

int LCSPro[MAXNUM][MAXNUM]; //LCD数组，存放当前公共元素个数
int LCSPath[MAXNUM][MAXNUM];//用于打印公共元素
/**
 * 构造Hash表
 */
int Hash(int* hashtable, int hash_len, int* array, int array_len, int min) 
{
	int i;
	memset(hashtable, '0', sizeof(int)*hash_len);
	for(i = 0; i < array_len; i++)
	{
		hashtable[array[i] - min] = 1;
	}
}

/** 
 * 将元素放入Hash表，并比较是否存在 
*/
int LoadHashTable(int* hashtable, int hash_len, int* array, int array_len, int min) 
{
	int i;
	for(i = 0; i < array_len; i++)
	{
		if(1 == hashtable[array[i] - min])
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
void CommonElements_Hash(int* array1, int array1_len, int* array2, int array2_len) 
{
    int i, min = array1[0], max = array1[0];
    //求出arra1的最大值
    for(i = 0; i < array1_len; i++)
    {
        if(array1[i] > max)
            max = array1[i];
		else if(array1[i] < min)
			min = array1[i];
    }
    for(i = 0; i < array2_len; i++)
    {
        if(array2[i] > max)
            max = array2[i];
		else if(array2[i] < min)
			min = array2[i];
    }
	printf("max = %d, min = %d\r\n", max, min);
    int*hashtable;
	if(NULL == (hashtable = (int*)malloc(sizeof(int)*(max - min))))
	{
		printf("申请空间失败!\r\n");
		return;
	}
	Hash(hashtable, max-min, array1, array1_len, min);
	LoadHashTable(hashtable,  max-min, array2, array2_len, min);
	free(hashtable);
}

/** 
 * @brief   求text和query两个集合的公共元素。
 * @param   query      query的首指针 
 * @param   query_len  query的长度 
 * @param   text       text的首指针     
 * @param   text_len   text的长度 
 * @retval  错误码     0：成功	-1：输入参数有误	-2：申请空间失败。
 * @see     None;
 * @note    
 */
int LCS(int* query, int query_len, int* text, int text_len)
{
	if(NULL == query || NULL == text || 0 == query_len || 0 == text_len)
	{
		printf("输入参数有误\r\n");
		return -1;
	}
	int *p;
	int i,j;
	if(NULL == (p = (int*)malloc(sizeof(int)*(text_len + 1))))
	{
		printf("申请空间失败!\r\n");
		return -2;
	}	
	for(i = 0; i < query_len; i++){ LCSPro[i][0] = 0; }
	for(j = 0; j < text_len; j++){ LCSPro[0][j] = 0; }

	for(i = 0; i < query_len; i++)
	{
		for(j = 0; j < text_len; j++)
		{
			if(query[i] == text[j])
			{
				LCSPro[i+1][j+1] = LCSPro[i][j] + 1;
				LCSPath[i+1][j+1] = 0;
			}
			else if(LCSPro[i+1][j] <= LCSPro[i][j+1])
			{
				LCSPro[i+1][j+1] = LCSPro[i][j+1];
				LCSPath[i+1][j+1] = 1;
			}
			else
			{
				LCSPro[i+1][j+1] = LCSPro[i+1][j];
				LCSPath[i+1][j+1] = 2;
			}
		}
	}
}

/** 
 * @brief   打印出两个集合的公共元素。
 * @param   query      query的首指针 
 * @param   query_len  query的长度  
 * @param   text_len   text的长度 
 * @retval  None
 * @see     None
 * @note    
 */
void PrintPath(int* query, int query_len, int text_len)
{
	if(query_len == 0 || text_len == 0)
		return;//递归终止条件
	if(LCSPath[query_len][text_len] == 0)
	{	
		PrintPath(query, query_len - 1, text_len - 1);
		printf("%d   ", query[query_len - 1]);
	}
	else if(LCSPath[query_len][text_len] == 1)
	{
		PrintPath(query, query_len - 1, text_len);
	}
	else
	{
		PrintPath(query, query_len, text_len - 1);
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
void CommonElements_LCS(int* array1, int array1_len, int* array2, int array2_len) 
{
    LCS(array1, array1_len, array2, array2_len);
	PrintPath(array1, array1_len, array2_len);
}

int main()
{
	int a[] = {1,3,-4,7,9,20};
	int b[] = {3,7,12,4,9,-4,14};
	//CommonElements_Hash(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int));
	CommonElements_LCS(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int));

}