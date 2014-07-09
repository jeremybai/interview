/****************************************************************************
 * @file     01_打印1到最大的n位数.c
 * @brief    输入数字n，按顺序打印出1到最大的n位十进制数。比如输入3，则打印出
 *           1、2、3一直到最大的3位数即999。
 * @version  V1.00
 * @date     2014.7.9
 * @note     （1）字符串模拟加法（2）递归   时间复杂度 空间复杂度
 * @note     陷阱：输入的n过大会溢出。
 ****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/** 
 * @brief     模拟加法将字符串加1操作。
 * @param[in] ptr     指向需要加1的字符串指针
 * @retval    0：未溢出,1：最高位溢出,2: 参数错误，返回值作为是否结束计算的标志
 * @see       None
 * @note      
 */
int Increase(char *ptr)
{
	if(NULL == ptr)
	{
		printf("Increase param error!\r\n");
		return 2;
	}
	int length = strlen(ptr);
	int num = 0,CarryBit = 0,i;
	for(i = length-1; i >= 0; i--)
	{
		ptr[i] = ptr[i] + CarryBit;
		if(i == length-1)
		{
			ptr[i] = ptr[i] + 1;
		}
		if(ptr[i] >= '0'+10)
		{
			if(i == 0)
			{
				return 1;
			}
			else
			{
				CarryBit = 1;
				ptr[i] = '0';
				continue;
			}
		}
		else
		{
			break;
		}
	}
	return 0;
} 

/**		打印字符串\n  
 *     
 *		字符串前面的0不打印    
 */
int PrintNum(char *ptr)
{
	char *p = ptr;
	while(*p == '0')
	{
		p++;
	}
	printf("%s    ",p);
}

/**		打印1到最大的n位数\n  
 *     
 *		根据输入的n输出1到最大的n位数 ，0：正常返回,1：参数错误，   
 */
int Print1toMaxN(int n)
{
	if(n < 1)
	{
		printf("Print1toMaxN param error!\r\n");
		return 1;
	}
	char *ptr = (char*)malloc(sizeof(char)*n);
	memset(ptr,'0',sizeof(char)*n);
	ptr[n] = '\0';

	
	while(Increase(ptr) == 0)
	{
		PrintNum(ptr);
	}
	return 0;
}

/**		递归输出的函数\n  
 *     
 *		  
 */
void Print1toMaxNRecursionFunc(char *ptr,int n,int index)
{
	if(index == n-1)
		PrintNum(ptr);
	else
	{
		for(int i = 0; i < 10; i++)
		{
			ptr[index+1] = i + '0';
			Print1toMaxNRecursionFunc(ptr,n,index+1);
		}
	}
}

/**		递归打印1到最大的n位数\n  
 *     
 *		根据输入的n输出1到最大的n位数 ，0：正常返回,1：参数错误，   
 */
int Print1toMaxNRecursion(int n)
{
	if(n < 1)
	{
		printf("param error!\r\n");
		return 1;
	}
	char *ptr = (char*)malloc(sizeof(char)*n);
	int i;
	memset(ptr,'0',sizeof(char)*n);
	ptr[n] = '\0';

	for(i = 0; i < 10; i++)
	{
		ptr[0] = i + '0';
		Print1toMaxNRecursionFunc(ptr,n,0);
	}
	return 0;
}



int main()
{
	int length;
	while(scanf("%d",&length) != EOF)
		Print1toMaxNRecursion(length);
	return 0;
}