/****************************************************************************
* @file     02_求text在query中的最长子串.c
* @brief    给定一个query和一个text，均由小写字母组成。要求在text中找出以同
			样的顺序连续出现在query中的最长连续字母序列的长度。例如， query为“acbac”，text为“acaccbabb”，那么text中的“cba”为最长的连续
			出现在query中的字母序列，因此，返回结果应该为其长度3。 
* @version  V1.00
* @date     2014.8.29
* @note     
****************************************************************************/
#include <stdio.h>

#define MAXNUM 200
/** 
 * @brief   求text和query两个字符串的最长公共子串。
 * @param   query      query的首指针 
 * @param   query_len  query的长度 
 * @param   text       text的首指针     
 * @param   text_len   text的长度 
 * @retval  错误码     0：成功	-1：输入参数有误	-2：申请空间失败。
 * @see     None;
 * @note    
 */
int MaxCommonSubString(char* query, int query_len, char* text, int text_len)
{
	if(NULL == query || NULL == text || 0 == query_len || 0 == text_len)
	{
		printf("输入参数有误\r\n");
		return -1;
	}
	int *p, max = 0, postion = 0;
	int i,j;
	if(NULL == (p = (int*)malloc(sizeof(int)*(text_len + 1))))
	{
		printf("申请空间失败!\r\n");
		return -2;
	}
	memset(p, 0, sizeof(int)*(text_len + 1));
	for(i = 0; i < query_len; i++)
	{
		for(j = text_len - 1; j >= 0; j--)
		{
			//从后向前遍历query，若从前向后遍历，需要额外的一个数组存放数组p上一次的值
			if(text[j] == query[i])
			{
				p[j+1] = p[j] + 1;
				if(p[j+1] > max)
				{
					max = p[j+1];         //替换当前最大子串长度
					postion = j - max + 1;//子串初始位置
				}
			}
			else
			{
				p[j+1] = 0;
			}
		}
	}
	//申请并复制最长公共子串到substring
	char *substring;
	if(NULL == (substring = (char*)malloc(sizeof(char)*(max + 1))))
	{
		printf("申请空间失败!\r\n");
		return -1;
	}	
	memcpy(substring, text + postion, max);
	substring[max] = '\0';
	printf("最长公共子串为：%s，长度：%d\r\n", substring, max);
	free(p);
	free(substring);
	return 0;
}

int main()
{
	char *query = (char*)malloc(sizeof(char)*MAXNUM);
	char *text = (char*)malloc(sizeof(char)*MAXNUM);
	printf("请输入query：");
	gets(query);
	printf("请输入text：");
	gets(text);
	int i = 0, j = 0;
	while(query[i] != '\0'){i++;};
	while(text[j] != '\0'){j++;};
	MaxCommonSubString(query, i, text, j);
	free(query);
	free(text);
}
