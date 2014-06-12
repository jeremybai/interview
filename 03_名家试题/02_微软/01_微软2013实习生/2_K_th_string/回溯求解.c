#include <stdio.h>
#define MAX_N 33

int n,m=2;
long long Count=0,times; // 共有n个数，其中互不相同的有m个 
int rcd[MAX_N];   //记录每个位置填的数字
int used[MAX_N]; //标记m个数可以使用的次数
int num[MAX_N]; // 存放互不相同的m个数 0，1

long long com(int n, int r)
{
    if(n-r < r) r= n-r;   // 减少计算量
    int i,j,s=1;
    for(i=0;i<r;++i)
    {
       s*=(n-i);
       for(j=1;j<=r && s%j==0; ++j) s/=j;  // 尽量避免越界
     }
    return s;
}

void unrepeat_permutation(int l)
{
     int i;
     if(l==n)
     {
             Count++;
             if(Count==times)   //查找到所需的数字
             {
                 for(i=0;i<n;i++)
                 {
                                 printf("%d",rcd[i]);
                                 if(i<n-1) printf(" ");
                 } 
                 printf("\n");    
                 
             }
             return;
     } 
     for(i=0;i<m;i++) //回溯求解
     {
       if(used[i]>0)
       {
                   used[i]--;
                   rcd[l] = num[i];
                   unrepeat_permutation(l+1);
                   used[i]++;
       }
     }
} 



int main()
{
    int a,b,i,T;
    scanf("%d",&T);
    while(T--)
    {
          scanf("%d%d%lld",&a,&b,&times);
          n=a+b;
          if(times>com(n,a))  // 判断是否超出组合范围
          {
             printf("Impossible\n");
             continue;
          }
          used[0]=a;  used[1]=b;  //记录0,1的个数
          num[0]=0;   num[1]=1;   //记录可能出现的数字
          Count=0; 
          unrepeat_permutation(0);
    }
    return 0;
}