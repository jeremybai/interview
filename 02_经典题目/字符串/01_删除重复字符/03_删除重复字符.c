/****************************************************************************
 * @file     删除重复字符.c
 * @brief    输入一个长度不超过 100 的字符串，删除串中的重复字符。
 * @version  V1.00
 * @date     2013.12.27
 * @note     时间复杂度O(1) 空间复杂度O(1)
 ****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>
//输入字符的最大长度
#define N 100
#define DEBUG

int HashTable[255]={0};   // contains A-F and a-z character

/**   将字符串放入Hash表 
 * 
 *	  判断字符是否出现过，没有出现过就按照新的索引向前赋值（因为前面字符已经
 *    判断过，可以被覆盖），原来的索引继续向后，移动不受影响。遍历完字符串后
 *    将新索引加上'\0'结束。这样在创建Hash表的同时将字符串完成处理。
 */
void LoadHashTable(char *str) 
{
    if(0 == strlen(str))
	{
		printf("输入字符串为空！\n\n");
		return ;
	}
    int i,j = 0;
    for(i = 0;i < strlen(str);i++) 
	{
		if(HashTable[(int)str[i]] == 0)
		{
			str[j++] = str[i];
			HashTable[(int)str[i]] += 1;//对于的键值加1		
		}

    }
	str[j] = '\0';
	printf("删除重复字符后的字符串为：\n%s\n\n", str);
}

int main() 
{
#ifdef USERMODE
	char *Old_ptr,* New_ptr;
	int Old_Length,i,j = 0,val;
	char Test_char;
	// 申请输入字符串大小的空间
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
	// 获得输入字符串的长度
	Old_Length = strlen(Old_ptr);
	printf("字符串长度为%d\n",Old_Length);	
	// 初始化哈希表并且完成处理
	LoadHashTable(Old_ptr);
	// 释放申请的空间
	free(Old_ptr);
#endif	
#ifdef DEBUG
	//=======================================================================
	//测试
	printf("==============================================================\n");
	char a[100] = "aabbccdd";
	printf("输入字符串为：\n%s\n",a);
	LoadHashTable(a);
	memset(HashTable,0,255*sizeof(int));
	printf("==============================================================\n");
	char b[100] = "";	
	printf("输入字符串为：%s\n",b);
	LoadHashTable(b);
	memset(HashTable,0,255*sizeof(int));
	printf("==============================================================\n");
	char c[100] = "123562356 abca deef";
	printf("输入字符串为：%s\n",c);
	LoadHashTable(c);
	memset(HashTable,0,255*sizeof(int));
	printf("==============================================================\n");
	return 0;
#endif	
}
