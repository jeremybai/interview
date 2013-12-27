/****************************************************************************
 * @file     删除重复字符.c
 * @brief    输入一个长度不超过 100 的字符串，删除串中的重复字符。
 * @version  V1.00
 * @date     2013.12.27
 * @note     时间复杂度O(n) 空间复杂度O(1)
 ****************************************************************************/
# include <stdio.h>
# include <string.h>
# include <malloc.h>
# include <stdint.h>
# include <stdlib.h>
//输入字符的最大长度
# define N 100

int HashTable[255]={0};   // contains A-F and a-z character
/**
 * 构造Hash表
 */
int Hash(char c) 
{
	return (int)c;
}
/** 
 * 将字符串放入Hash表 
 */
void LoadHashTable(const char *str) 
{
    int i;
    int pos;   // the hash address 
    for(i = 0;i < strlen(str);i++) 
	{
		pos = Hash(str[i]); //找到对应的位置
		HashTable[pos] += 1;//对于的键值加1
    }
}

int main() 
{
	char *Old_ptr,* New_ptr;
	int Old_Length,i,j = 0, pos,val;
	char Test_char;
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
	//初始化哈希表
	LoadHashTable(Old_ptr);
	for(i = 0; i < Old_Length; i++)
	{
		pos = Hash(Old_ptr[i]);
		val = HashTable[pos];
		if(val > 1) 
		{
			Old_ptr[j++] = Old_ptr[i];
			HashTable[pos] = 0;
		}
		else if(val == 1)
		{
			Old_ptr[j++] = Old_ptr[i];
		}
		else if(val == 0)
		{
			i++;
		}
	}
	Old_ptr[j] = '\0';
	printf("删除重复字符后的字符串为：\n%s\n", Old_ptr);
	//释放申请的空间
	free(Old_ptr);
	return 0;
}
