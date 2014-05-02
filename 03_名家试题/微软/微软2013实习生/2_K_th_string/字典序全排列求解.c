/****************************************************************************
 * @file     answer.c
 * @brief    题目参考description
 * @version  V1.00
 * @date     2014年4月14日
 * @note     思路1：全排列的字典序生成算法
					设P是[1,n]的一个全排列。
					P=P1P2…Pn=P1P2…Pj-1PjPj+1…Pk-1PkPk+1…Pn
					从右向左扫描找到第一个比它右边小的数A，再从A向右扫描，
					找到最后一个大于它的数B，交换A和B，再将此时B右边的字符串倒序
					就得到了当前全排列的下一个全排列。
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/** 
 * @brief     计算组合数C(n,r)。
 * @param[in] n:总数  r:取出的数
 * @retval    0：出错  其他：组合数
 * @see       无
 * @note      无
 */
long long com(int n,int r)
{
	if(n <= 0 || r < 0)
	{
		perror("function com para error!\n");
		return 0;
	}
	if(r == 0)
		return 1;
	if(n - r < r) 
		r = n-r;  //减少计算量
	long long s = 1;
	int i,j;
	for(i=0,j=1;i < r;++i)
	{
		s*=(n-i);
		for(;j <= r && s%j == 0; ++j) 
			s/=j;  // 这个循环就是除以r!,防止溢出
	}	
	return s;
}
/** 
 * @brief     反转字符串。
 * @param[in] begin:字符串起始地址  end:字符串结束地址 len:字符串长度
 * @retval    错误码，0:反转成功 其他:反转失败
 * @see       无
 * @note      无
 */
int reverse(char *begin, char *end,int len)
{
	if(NULL == begin || NULL == end)
	{
		perror("function reverse para error!\n");
		return 1;
	}
	if(len == 1)
		return 0;
	int length = len/2;
	while(length--)
	{
		*begin ^= *end;
		*end ^= *begin;
		*begin++ ^= *end--;
	}
	return 0;
}


int main(void) 
{
    long long num = 0, ordinal = 0;
	int num_zero, num_one,i,j,k,left,right,sum;
    while(scanf("%d", &num) != EOF) {
		while(num--)
		{
			scanf("%d%d%d", &num_zero, &num_one, &ordinal);
			sum = num_zero + num_one;			
			if(num_zero < 0 || num_one < 0 || sum < 2 || sum > 33 || ordinal < 0 || ordinal > 1000000000)
			{
				continue;
			}
			char *p = (char *)malloc(sizeof(char)*(num_zero+num_one)+1);
			//数组从0开始
			i = 0;
			//构造最小的组合数
			j = num_zero;
			while(j--)
			{
				p[i++] = '0';
			}
			j = num_one;
			while(j--)
			{
				p[i++] = '1';
			}
			p[i] = '\0';
			// printf("%s\n",p);
			//判断参数是否越界
			if( (0 == ordinal) || (ordinal > com(sum,num_zero)) ) 
			{
				printf("Impossible\n");
			}
			else
			{
				for(i = ordinal ;i > 1 ;i--)
				{
					for(j = sum-1; j > 0; j--)
					{
						if( (p[j-1] == '0') && (p[j] == '1') )
						{
							left = j-1;
							for(k = j; k < sum; k++)
							{	
								right = k;
								if(p[k] != '1')
								{
									right = k -1;
									break;
								}
							}
							//交换找到的0和1
							p[left] ^= p[right];
							p[right] ^= p[left];
							p[left] ^= p[right];
							//反转left之后字符串
							reverse(p+left+1,p+sum-1,sum-1-left);
							break;					
						}
						
					}
				}
				printf("%s\n",p);
				free(p);
				p = NULL;
			}
		}

    }
    return 0;
}