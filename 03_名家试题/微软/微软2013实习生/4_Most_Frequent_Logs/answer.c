/****************************************************************************
 * @file     answer.c
 * @brief    见description
 * @version  V2.00
 * @date     2014年6月5日
 * @note     V1 采用计算编辑距离的方法,模板采用二维数组存放。
			 V2 模板采用指针数组存放。
****************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX_NUM 100
/**		求最小值   
 *     
 *		求三个数中最小的一个。    
 */
int min(int a, int b, int c)
{
    return (a = a < b ? a : b) < c ? a : c;
}


/** 
 * @brief     二维动态规划计算字符串的编辑距离。
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
	    *(array + j) = j;                         //array[0][j]
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
	char *temp = (char*)malloc(256*sizeof(char)),*ptr;
	char *template[MAX_NUM];
	int count[MAX_NUM],i;
	int len[MAX_NUM] = {0},length,flag,max;
	memset(count,-1,sizeof(int)*MAX_NUM);
	while(gets(temp) != NULL)
	{
		if(strlen(temp) == 0)
			break;
		//初始化第一个模板，否则无法进行下一步
		if(count[0] == -1)
		{
			template[0] = temp;
			count[0] = 1;
			len[0] = strlen(temp);
			continue;
		}
		length = strlen(temp);
		flag = 0;
		for(i = 0; i < MAX_NUM && count[i] != -1; i++)
		{
			if(CalEditDist(temp,length,template[i],len[i]) <= 5)
			{
				count[i]++;
				flag = 1;
				break;
			}
		}
		//如果在模板列表中没有找到对应的模板
		if(!flag)
		{
			template[i] = temp;
			count[i] = 1;
			len[i] = length;
		}
	}
	i = 0;
	max = 0;
	while(count[i] != -1)
	{
		if(count[i] > max)
			max = count[i];
		i++;
	}
	printf("%d ",max);
	free(temp);
	temp = NULL;
	//printf("%d",CalEditDist(a,sizeof(a)/sizeof(char)-1,b,sizeof(b)/sizeof(char)-1));	
}