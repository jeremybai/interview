/****************************************************************************
* @file     04_最长公共子序列.c
* @brief    求最长公共子序列 
* @version  V1.00
* @date     2014.9.1
* @note     
****************************************************************************/
#include <stdio.h> 
#include <string.h>

#define MAXNUM 200

int LCSPro[MAXNUM][MAXNUM];
int LCSPath[MAXNUM][MAXNUM];
/**        求最大值   
 *     
 *     求两个数中最大的一个。    
 */
int Max(int a, int b)
{
    return a > b ? a : b;
}

/** 
 * @brief   求text和query两个字符串的最长公共子子序列。
 * @param   query      query的首指针 
 * @param   query_len  query的长度 
 * @param   text       text的首指针     
 * @param   text_len   text的长度 
 * @retval  错误码     0：成功	-1：输入参数有误	-2：申请空间失败。
 * @see     None;
 * @note    
 */
int LCS(char* query, int query_len, char* text, int text_len)
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
 * @brief   打印出query和text两个字符串的最长公共子子序列。
 * @param   query      query的首指针 
 * @param   query_len  query的长度  
 * @param   text_len   text的长度 
 * @retval  None
 * @see     None
 * @note    
 */
void PrintPath(char* query, int query_len, int text_len)
{
	if(query_len == 0 || text_len == 0)
		return;//递归终止条件
	if(LCSPath[query_len][text_len] == 0)
	{	
		PrintPath(query, query_len - 1, text_len - 1);
		printf("%c", query[query_len - 1]);
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



int main()
{
	char *query = (char*)malloc(sizeof(char)*MAXNUM);
	char *text = (char*)malloc(sizeof(char)*MAXNUM);
	printf("请输入query：");
	gets(query);
	printf("请输入text：");
	gets(text);
	//char query[] = "ABCBDAB";
	//char text[] = "BDCABA";
	int query_len = 0, text_len = 0, i, j;
	while(query[query_len] != '\0'){query_len++;};
	while(text[text_len] != '\0'){text_len++;};
	LCS(query, query_len, text, text_len);
	printf("LCS长度为%d\r\n",LCSPro[query_len][text_len]);
	printf("LCS为");
	PrintPath(query, query_len, text_len);
	free(query);
	free(text);
}
