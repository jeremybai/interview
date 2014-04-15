/****************************************************************************
 * @file     answer.c
 * @brief    题目参考description
 * @version  V1.00
 * @date     2014年4月14日
 * @note     思路2：使用algorithm库里面的next_permutation函数求全排列
****************************************************************************/
#include <iostream>
#include <algorithm>
#include <string>
 
using namespace std;

/** 
 * @brief     计算组合数C(n,r)。
 * @param[in] n:元素个数  r:组合数
 * @retval    C(n,r)
 * @see       无
 * @note      无
 */
long long com(int n,int r)
{
    if(n-r < r) r= n-r;  //减少计算量
    int i,j,s=1;
    for(i=0;i<r;++i)
    {
        s*=(n-i);
		for(j=1;j<=r && s%j==0; ++j) 
			s/=j;    
    }
    return s;
}
/** 
 * @brief     求出全排列中的从小到大的第k个数。
 * @param[in] str:字符串  n:0的个数  m:1的个数 k:序数
 * @retval    错误码
 * @see       无
 * @note      无
 */
int KthString(string str,int n,int m,int k)
{
	int i;
	str.clear();
	for(i = 0; i < n; i++)
	{
		str += "0";
	}
	for(i=0;i<m;i++)
	{
		str += "1";
	}
	sort(str.begin(), str.end());
	if(1 == k)
		cout << str << endl;
	else
	{
		while (next_permutation(str.begin(), str.end()) )
		{
			k--;
			if((k-1) == 0)
			{
				cout << str << endl;
				return 0;
			}
		}
	}	
}


int main()
{
    string str;
    int num = 0, num_zero = 0, num_one = 0, ordinal = 0;
	long int t;
	while(scanf("%d",&t) != EOF){
		//判断参数合法性
		if(t < 1 ||  t > 1000000000)
		{
			printf("Impossible\n");
			return 1;
		}
		while(t--)
		{
			cin>>num_zero>>num_one>>ordinal;
			if(num_zero < 0 || num_one < 0 || (num_zero + num_one) < 2 || (num_zero + num_one) > 33)
			{
				printf("Impossible\n");
				return 1;		
			}
			if(ordinal > com(num_zero+num_one,num_one))
			{
				printf("Impossible\n");
			}
			else
				KthString(str,num_zero,num_one,ordinal);
		}
	}
	return 0;
}