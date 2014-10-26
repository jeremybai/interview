/****************************************************************************
 * @file     FindNumsAppearOnce.c
 * @brief    一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
			找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
 * @version  V1.00
 * @date     2014年6月12日
 * @note     位运算
****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** 
 * @brief     找出数组中只出现1次的两个数。
 * @param[in] Array      数组的起始地址
 * @param[in] ArrayNum   数组的长度
 * @param[in] temp1      出现1次的数1
 * @param[in] temp2      出现1次的数2
 * @retval    成功：0，失败：1
 * @see       None
 * @note      		  
 */
int FindNumsAppearOnce(int *Array, int ArrayNum,int *temp1, int *temp2)
{
	if(Array == NULL || ArrayNum <= 0)
		return 1;
	int i,ExclusiveOr,index;
	for(i = 0; i < ArrayNum; i++)
	{
		ExclusiveOr ^= Array[i];
	}
	index = 0;
	while(ExclusiveOr & 0x01 != 0x01 && index <=31)
	{
		ExclusiveOr>>1;
		index++;
	}
	for(i = 0; i < ArrayNum; i++)
	{
		if(Array[i]>>index & 0x01)
			*temp1 ^= Array[i];
		else	
			*temp2 ^= Array[i];
	}
	return 0;
}

int main()
{
	int a[10] = {1,2,3,5,7,8,5,1,2,3};
	int temp1 = 0, temp2 = 0;
	if(!FindNumsAppearOnce(a,sizeof(a)/sizeof(int),&temp1,&temp2))
		printf("Numbers appear once are:%d and %d.",temp1,temp2);
}