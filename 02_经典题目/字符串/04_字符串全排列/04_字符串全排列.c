/****************************************************************************
 * @file     04_字符串全排列.c
 * @brief    输出字符串的全排列
 * @version  V1.00
 * @date     2014.9.15
 * @note     字典序求全排列和递归求全排列
 ****************************************************************************/
#include <stdio.h>


/**		内部函数  
*     
*		用于两个数进行交换。    
*/ 
static void Swap(char *a, char *b)
{
	if(a == b)
		return;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}


/** 
 * @brief     反转字符串。
 * @param[in] array    字符串的起始地址
 * @param[in] begin    反转字符串的起始
 * @param[in] end      反转字符串的结束
 * @retval    None
 * @see       None
 * @note      将字符串1和n交换，2和n-1交换，依次交换...
 */
void Reverse(char* array, int begin, int end)
{
	if(NULL == array)
	{
		printf("参数错误!\n");
		return ;
	}
	while(begin < end)
	{
		array[begin] ^= array[end];
		array[end] ^= array[begin];
		array[begin++] ^= array[end--];
	}
}

/** 
 * @brief     求字符串的下一个全排列。
 * @param[in] array    字符串的起始地址
 * @param[in] length   字符串的长度
 * @retval    None
 * @see       None
 * @note      字典序求字符串的下一个排列
 */
int Permutation(char* array, int length)
{
	if(NULL == array || 0 == length)
	{
		printf("参数错误！\r\n");
		return 2;	
	}
	int i, j, k, left, right, min;
	for(i = length - 1; i > 0; i--)
	{
		if(array[i-1] < array[i])
		{
			left = i - 1;
			right = i;
			min = array[i];
			for(k = i; k < length; k++)
			{
				if(array[k] > array[left] && array[k] < min)
				{
					min = array[k];
					right = k;
				}
			}
			Swap(&array[left], &array[right]);
			Reverse(array, left+1, length - 1);
			return 1;
		}
	}
	return 0;
}

/** 
 * @brief     求字符串的下一个全排列。
 * @param[in] array    字符串的起始地址
 * @param[in] length   字符串的长度
 * @retval    -1：参数错误
 * @see       None
 * @note      字典序求字符串的下一个排列
 */
int Permutation_Recursion(char* array, char* begin)
{
	if(NULL == array)
	{
		printf("参数错误！\r\n");	
		return -1;
	}
	char* temp;
	if(*begin == '\0')
	{
		printf("%s\n",array);
		return 0;
	}	
	for(temp = begin; *temp != '\0'; temp++)
	{
		Swap(begin, temp);
		Permutation_Recursion(array, begin + 1);
		Swap(begin, temp);
	}
}

int main()
{
	char array[] = "123";
	int i = 1;
	//printf("%s\n",array);
	// while(1 == Permutation(array, strlen(array)))
	// {
		// i++;
		// printf("%s\n",array);
	// }
	Permutation_Recursion(array, array);
	//printf("总数 = %d\n",i);	
}


