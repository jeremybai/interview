/****************************************************************************
 * @file     answer.c
 * @brief    题目参考description
 * @version  V1.00
 * @date     2014年4月14日
 * @note     思路1：由n个0和m个1组成的最大最小数，从最小的开始，判断每一个
                    包含1的个数， 不等于m就跳，直到第k个，在转为0、1表示
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
/** 
 * @brief     计算元素在HASH表中的位置。
 * @param[in] n:0的个数  m:1的个数 k:序号
 * @retval    元素在HASH表中的位置，如果不在范围之内，返回-1
 * @see       无
 * @note      无
 */
int  foo(int n,int m,int k)
{
	
}

int main(void) {
    int num = 0, num_zero = 0, num_one = 0, ordinal = 0;
	
    while(scanf("%d", &num) != EOF) {
		while(num--)
		{
			scanf("%d%d%d", &num_zero, &num_one, &ordinal);
			printf("%d %d %d", num_zero, num_one, ordinal);
			//foo(num_zero,num_one,ordinal);
			
		}

    }
    return 0;
}
