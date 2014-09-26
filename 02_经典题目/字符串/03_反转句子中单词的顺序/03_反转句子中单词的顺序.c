/****************************************************************************
 * @file     03_反转句子中单词的顺序.c
 * @brief    输入"I am a  student"，输出"student a am I"
 * @version  V1.00
 * @date     2014.9.15
 * @note     
 ****************************************************************************/
#include <stdio.h>

/** 
 * @brief     反转字符串。
 * @param[in] begin    字符串的头指针
 * @param[in] end      字符串的尾指针
 * @retval    None
 * @see       None
 * @note      将字符串1和n交换，2和n-1交换，依次交换...
 */
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


