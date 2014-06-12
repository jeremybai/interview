/****************************************************************************
 * @file     answer.c
 * @brief    题目参考description
 * @version  V1.00
 * @date     2014年4月12日
 * @note     
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 36

int HashChar[NUM] = {0};   // contains0-9 and a-z character
int Size = 0;
/** 
 * @brief     计算元素在HASH表中的位置。
 * @param[in] c  需要计算位置的元素
 * @retval    元素在HASH表中的位置，如果不在范围之内，返回-1
 * @see       无
 * @note      无
 */
int Hash(char c) {
	if(c >='0' && c <= '9')
	{
		return c-'0';
	}
	else if(c >='a' && c <= 'z')
	{
		return c-'a' + 10;
	}
	else
	{
		return -1;
	}
}
/** 
 * @brief     初始化HASH表。
 * @param[in] c  需要计算位置的元素
 * @retval    元素在HASH表中的位置，如果不在范围之内，返回-1
 * @see       无
 * @note      无
 */
int InitialHash(char *B) {
	int i;
	int pos;
	for(i = 0;B[i];i++) {
		pos = Hash(B[i]);
		if(pos == -1) {
			
			return -1;
		}
		else 
			HashChar[pos] ++;
		Size++;
	}
	return 0;
}
 /**	字符串出现排序   
 *     
 *		将字符串按照指定要求重新排序，并且打印。。    
 */ 
void ReOrder(){
	int i;
	for(i = 0; i < NUM;i++)
	{
		if(HashChar[i])
		{
			if(i <= 9)
			{
				printf("%c",i+'0');
			}
			else
			{
				printf("%c",i - 10 + 'a');
			}
			HashChar[i]--;
			Size--;
		}
		
	}
}

int main(void) {
    char unorder[500];
    while(scanf("%s", unorder) != EOF) {
		if(-1 == InitialHash(unorder))
		{
			printf("<invalid input string>");
			Size = 0;
		}
		while(Size)
		{
			ReOrder();
		}
    	printf("\n");
		Size = 0;
		memset(HashChar,0,36);
    }
    return 0;
}
