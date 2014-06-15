#include<iostream>
using namespace std;
#define null 0
#define MAXN 51
 
//大数相乘
char *big_cheng(char line1[], char line2[])
{
short s1[MAXN], s2[MAXN], s[MAXN];//s1，s2：两个乘数；s：乘积的结果
int i, j, k, c;
int len1, len2, len;
len1 = strlen(line1);
len2 = strlen(line2);
len = len1 + len2;//初步确定乘积的长度
for(i = len1 - 1; i >= 0; i--)
{
s1[i] = line1[len1 - i -1] - '0';//将字符串转化为整型，并反着存放
}
for(i = len2 - 1; i >= 0; i--)
{
s2[i] = line2[len2 - i - 1] - '0'; 
}
 
memset(s, 0, sizeof(short) * (MAXN - 1));//s数组初始化
 
for(i = 0; i <= len1 -1; i++)
for(j = 0; j <= len2 -1; j++)
s[i + j] = s[i + j] + s1[i] * s2[j];//逐位相乘
 
for(i = 0, c = 0; i <= len - 1;i++)//处理进位
{
k = s[i] + c;
s[i] = k % 10;
c = k / 10;
}
 
for(i = len - 1; i >= 0; i--)
if(s[i] != 0)break;//处理多余的零
len = i + 1;
char *line;//注意只有指针才可以返回去，不能定义成数组
line = new char[len + 1];
if(len == 0)
{
line[0] = 0 + '0';
line[1] = '\0';//字符串的结束标志
}
else
{
for(i = 0; i <= len - 1; i++)
line[i] = s[len - i - 1] + '0';
line[len] = '\0';//字符串的结束标志 
} 
return line;
}
 
int main()
{
char line1[MAXN], line2[MAXN];
while(cin >> line1 >>line2)
{
cout << big_cheng(line1, line2) << endl;
}
return 0;
}