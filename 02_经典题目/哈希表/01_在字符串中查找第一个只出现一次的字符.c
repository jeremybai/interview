/**
 * @brief  在字符串中查找第一个只出现一次的字符(Google笔试题)。
 * @note   在一个字符串中找到第一个只出现一次的字符。如输入AbAssvfFCCBbhV，则输出v。
 * @method 1 两层循环遍历 O(n * n)
 * @method 2 构造HashTable
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int HashTable[52]={0};   // contains A-F and a-z character
/**
 * 构造Hash表
 */
int Hash(char c) 
{
    if(isupper(c)) 
	{
		return c - 'A';
    }
    else if(islower(c)) 
	{
		return 26 + c - 'a';
    }
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
/**
 * 查找第一个只出现一次的字符
 */
int Locate(const char *str, char &X) 
{
    int i;
    int pos;
    int val;
	int find = 0;   
    for(i = 0;i < strlen(str);i++) 
	{
		pos = Hash(str[i]);
		val = HashTable[pos];
		if(val == 1) 
		{
			switch(pos/26) 
			{
				case 0:
					X = 'A' + pos%26;
					break;
				case 1:
					X = 'a' + pos%26;
					break;
			}
			find = 1;
			return find; //如果要找最后一个出现一次的字符，就把这句去掉
		}
    }
	return find;
}
int main() 
{
    char buf[1024];
    char c;
    int i;
	printf("请输入字符串：\n");
    gets(buf);
    for(i = 0;i < strlen(buf);i++) 
	{
		if(!isupper(buf[i]) && !islower(buf[i])) 
		{
			perror("字符串只可以包含大小写字母!\n");
			exit(1);
		}
    }
    LoadHashTable(buf);
    if(Locate(buf, c)) 
	{
		printf("第一个只出现一次的字符为：");
		putchar(c);
	}
	else 
		perror("没有出现一次的字母!");
    printf("\n");
	return 0;
}

