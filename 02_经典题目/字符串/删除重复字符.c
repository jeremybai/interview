/****************************************************************************
 * @file     删除重复字符.c
 * @brief    输入一个长度不超过 100 的字符串，删除串中的重复字符。
 * @version  V1.00
 * @date     2013.12.27
 * @note     无
 ****************************************************************************/
# include <stdio.h>
# include <string.h>
# include <malloc.h>
# include <stdint.h>
# include <stdlib.h>
//输入字符的最大长度
# define N 100

//判断参数是否错误
#define ASSERT(expr) \
	  ((expr) ? (void)0 : assert_failed((char *)__FILE__, __LINE__))

#define IS_POINTER(POINTER)      (POINTER != NULL)
#define IS_LENGTH(LENGTH)      (LENGTH > 0 && LENGTH <= N)

/**		参数错误时执行的函数\n  
 *     
 *		当使用ASSERT判断参数错误时，显示错误出现的位置。    
 */
void assert_failed(char* file, uint32_t line)
{
	printf("%s 第 %d 行错误！\n",file,line);
	while(1);
} 

/** 
 * @brief     删除重复出现的字符。
 * @param[in] Old_ptr     指向输入字符串的指针
 * @param[in] New_ptr     指向输出字符串的指针
 * @param[in] Old_Length  输入字符串的长度
 * @retval    None
 * @see       None
 * @note      扫描原来的字符串，判断当前字符是否在新字符串出现，出现则直接
			  break,没出现则加到新字符串末尾
 */
void delrepechar(char *Old_ptr, char *New_ptr, int Old_Length) 
{
	ASSERT(IS_POINTER(Old_ptr));
	ASSERT(IS_POINTER(New_ptr));
	ASSERT(IS_LENGTH(Old_Length));
	int i,j,k = 0;
	char Test_char;
	for (i = 0; i < Old_Length; i++) 
	{
		Test_char = Old_ptr[i];
		for (j = 0; j < k; j++) 
		{
			if (New_ptr[j] == Test_char) 
			{
				break;
			}
		}
		if (j == k) 
		{
			New_ptr[k++] = Test_char;
		}
	}
	//字符串末尾加上结束符
	New_ptr[k] = '\0';
}

int main() 
{
	char * Old_ptr,* New_ptr;
	int Old_Length;
	//申请输入字符串大小的空间
	if (NULL == (Old_ptr = (char * )malloc(N * sizeof(char)))) 
	{
		perror("error...");
		return 1;
	}
	printf("请输入待删除字符串,并以回车结束！\n");
	gets(Old_ptr);
	if(NULL == Old_ptr)
	{
		printf("输入字符串为空!\n");
		free(Old_ptr);
		return 1;
	}
	//获得输入字符串的长度
	Old_Length = strlen(Old_ptr);
	printf("字符串长度为%d\n",Old_Length);
	//申请新空间存放新字符串
	if (NULL == (New_ptr = (char * )malloc(Old_Length * sizeof(char)))) 
	{
		perror("error...");
		free(Old_ptr);
		return 1;
	}
	//删除重复的字符串
	delrepechar(Old_ptr,New_ptr,Old_Length);

	printf("删除重复字符后的字符串为：\n%s\n", New_ptr);
	//释放申请的空间
	free(Old_ptr);
	free(New_ptr);
	return 0;
}


