/****************************************************************************
 * @file     03_和为s的两个数.c
 * @brief    输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它
			 们的和正好是s。如果有多对数字的和等于s，输出任意一对即可。
 * @version  V1.00
 * @date     2014.9.2
 * @note     
****************************************************************************/
#include <stdio.h>
#include <malloc.h>

/** 
 * @brief     找出数组中的两个数使得它们的和正好是s
 * @param[in] array       数组的起始地址
 * @param[in] array_len   数组的长度
 * @param[in] s           需要相加所得的和
 * @retval    0：成功	-1：参数有误
 * @see       None
 * @note      		  
 */
int Find2NumsWithSum(int* array, int array_len, int s)
{
	if(NULL == array || 0 == array_len)
	{
		printf("参数有误\n");
		return -1;
	}

}

/** 
 * @brief     数组中只出现一次的两个数
 * @param[in] array       数组的起始地址
 * @param[in] array_len   数组的长度
 * @retval    0：成功	-1：参数有误	-2：不存在只出现一次的两个数
 * @see       None
 * @note      		  
 */
int FindNumsWithSum(int* array, int array_len, int s)
{
	if(NULL == array || 0 == array_len)
	{
		printf("参数有误\n");
		return -1;
	}

}
 
int main()
{
	int test[] = {1,2,3,4,5,6,7,3,7,6,1,2,4};
	int test1[] = {1,2,3,4,5,6,5,3,7,6,1,2};
	int num = 0,num1,num2;
	FindNumAppearOnce(test,sizeof(test)/sizeof(int), &num);
	FindNumsAppearOnce(test1,sizeof(test1)/sizeof(int), &num1, &num2);	
	printf("%d\r\n",num);
	printf("%d	%d\r\n",num1,num2);
}