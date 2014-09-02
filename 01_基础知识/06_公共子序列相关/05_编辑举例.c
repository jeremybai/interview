/****************************************************************************
 * @file     EditDistance_bx.c
 * @brief    求解两个字符串的编辑距离
 * @version  V1.00
 * @date     2014年5月30日
 * @note     编辑距离定义：计算两个字符串的距离，完全相同的字符串距离为0，可
			 以通过修改一个字符、增加一个字符或删除一个字符三种方式来使两个字
			 符串相同，但这些方式会使得距离加1。
             思路： 2维的动态规划。
****************************************************************************/
#include <stdio.h>
#include <malloc.h>

/**		求最小值   
 *     
 *		求三个数中最小的一个。    
 */
int min(int a, int b, int c)
{
    return (a = a < b ? a : b) < c ? a : c;
}


/** 
 * @brief     计算字符串的编辑距离。
 * @param[in] str1      字符串1的起始地址
 * @param[in] str1len   字符串1的长度
 * @param[in] str2      字符串2的起始地址
 * @param[in] str2len   字符串2的长度
 * @retval    成功：两个字符串之间的编辑距离，失败：-1
 * @see       None
 * @note      		  
 */
int CalEditDist(char* str1, int str1len, char* str2, int str2len)
{
	if(NULL == str1 || NULL == str2 || 0 == str1len || 0 == str2len)
	{
		printf("参数有误\n");
		return -1;
	}
	int i,j,re;
	int *array = (int*)malloc(((str1len+1)*(str2len+1))*sizeof(int));
	
	for(i = 0; i <= str1len; i++)
		*(array + i*(str2len + 1)) = i;           //array[i][0]
	for(j = 0; j <= str2len; j++)
	    *(array + j) = j;                   //array[0][j]
	for(i = 1; i <= str1len; i++)
	{
		for(j = 1; j <= str2len; j++)
		{
			*(array+i*(str2len+1)+j) = min(*(array+i*(str2len+1)+j-1)+1,*(array+(i-1)*(str2len+1)+j)+1,*(array+(i-1)*(str2len+1)+j-1) + (str1[i-1] == str2[j-1] ? 0 : 1));
		}
	}
	re =  *(array+(str1len)*(str2len+1)+(str2len));
	free(array);
	array=NULL;
	return re;
}
 
int main()
{
	char a[]="David_and_Sophia";
	char b[]="Dadiudiu_and_Xiaodiugirl";
	printf("%d",CalEditDist(a,sizeof(a)/sizeof(char)-1,b,sizeof(b)/sizeof(char)-1));
}