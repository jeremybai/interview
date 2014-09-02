/****************************************************************************
 * @file     03_反转句子中单词的顺序.c
 * @brief    输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
			 句子中单词以空格符隔开。为简单起见，标点符号和普通字母一样处理。
			 例如输入“I am a student.”，则输出“student. a am I”。
 * @version  V1.00
 * @date     2014.8.25
 * @note     
 ****************************************************************************/
#include <stdio.h>

void Reverse(char* begin,char* end)
{
	if(NULL == begin ||  NULL == end)
	{
		printf("参数错误!\n");
		return ;
	}
	while(begin < end)
	{
		*begin ^= *end;
		*end ^= *begin;
		*begin++ ^= *end--;
	}
}

int ReverseWordOrder(char* data_ptr)
{
	if(NULL == data_ptr)
	{
		printf("参数错误!\n");
		return 1;
	}
	char *begin,*end;
	begin = end  = data_ptr;
	while('\0' != *++end){}
	end--;
	//反转整个字符串
	Reverse(begin, end);
	//反转逐个单词
	begin = end  = data_ptr;
	while('\0' != *begin)
	{
		if(*begin == ' ')
		{
			begin++;
			end++;
		}
		else if(*end == ' ' || *end == '\0')
		{
			Reverse(begin, --end);
			begin = ++end;
		}
		else
		{
			end++;
		}
	}
}

int main()
{
	char p[16] = " I am a  tudent";
	ReverseWordOrder(p);
	printf("%s",p);
}


