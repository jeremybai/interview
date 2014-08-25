/****************************************************************************
 * @file     递归求全排列.c
 * @brief    使用递归求解字符串全排列
 * @version  V1.00
 * @date     2014.7.25
 * @note     
****************************************************************************/
#include <stdio.h>

void Swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

/** 
 * @brief     使用递归求解字符串全排列。
 * @param[in] 输入的字符串
 * @retval    无
 * @see       无
 * @note      每次首先固定一个字母，然后让其余的字母全排列；然后换一个字母固
			  定，再全排列其余的字母，碰到结束符'\0'，递归结束。
 */
void PermutationRecursive(char * str, char *begin)
{
	if(NULL == str || NULL == 	begin)
	{
		printf("param error!\r\n");
		return ;
	}
	char *p = begin;
	if('\0' == *begin)
	{
		printf("%s\r\n",str);
		return ;
	}
	while('\0' != *p)
	{
		Swap(begin,p);
		PermutationRecursive(str,begin+1);
		Swap(begin,p);
		p++;
	}
}

int main()
{	
	char a[] = "123";
	PermutationRecursive(a,a);
}
