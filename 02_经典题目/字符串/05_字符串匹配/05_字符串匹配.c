/****************************************************************************
* @file     04_字符串匹配.c
* @brief    
* @version  V1.00
* @date     2014.9.4
* @note     
****************************************************************************/
#include <stdio.h>
#include <string.h>

int ViolentMatch(char* text, char* pattern)  
{  
	int text_len = strlen(text);  
	int pattern_len = strlen(pattern);  

	int i = 0;  
	int j = 0;  
	while (i < text_len && j < pattern_len)  
	{  
		if (text[i] == pattern[j])  
		{  
			//如果当前字符匹配成功，则i++，j++      
			i++;  
			j++;  
		}  
		else  
		{  
			//如果匹配失败，令i = i - (j - 1)，j = 0 ，回到当前匹配的第一个字符的下一个     
			i = i - j + 1;  
			j = 0;  
		}  
	}  
	//匹配成功，返回模式串p在文本串s中的位置，否则返回-1  
	if (j == pattern_len)  
		return i - j;  
	else  
		return -1;  
} 

//直接对t进行自我匹配，遍历进行计算next数组
//还可以用递推法进行计算：GetNext_R
//笨方法，好理解
void GetNext_D(char *t,int *next)
{
	unsigned int i=0,j=0,k=0;
	int equal = 1;

	for(i=0;i<strlen(t);i++)
	{
		if(i==0)
		next[i] = -1;
		else if(i==1)
		next[i] = 0;
		else
		{
			for(j=i-1;j>0;j--)
			{
				equal = 1;
				//t[0到j]从最大的前缀和后缀进行比较判断，不断缩短
				//匹配到就break，得到目前所能匹配的最大前缀和后缀
				//例如ababa  next[4]=2,说明t[0...2] match t[2...4]
				for(k=0;k<j;k++)
				{
					//注意索引别搞错了
					if(t[k]!=t[i-j+k])
					equal = 0;
				}

				if(equal)
				{
					next[i] = j;
					break;
				}
			}
			if(j == 0)
			next[i]=0;

		}
	}

}

//递推的关系来求next
//好好理解下递推关系
void GetNext_R(char *t,int *next)
{
	unsigned int j=0;
	int k = -1;
	next[0]=-1;

	while(j<strlen(t)-1)
	{

		if(k==-1||t[j]==t[k])
		{
			j++;
			k++;
			next[j]=k;
		}
		else
		k=next[k];
	}

}

int KMP(char *s, char *t)
{
	unsigned int i;
	int j = 0;
	int *next = (int*)calloc(strlen(t),sizeof(int));

	//GetNext_D(t,next);
	GetNext_R(t,next);

	printf("next[] = ");
	for(i=0;i<strlen(t);i++)
	printf("%d ",next[i]);

	i=0;
	while(i<strlen(s))
	{
		if(j==-1||s[i]==t[j])
		{
			i++;
			j++;
		}
		else
		j = next[j];

		if(j==strlen(t))
		return (i-strlen(t));
	}

	free(next);

	return -1;
}

int main()
{
	char text[] = "ABCDEFGHIJKLMN";
	char pattern[] = "KLM";
	int result = ViolentMatch(text, pattern);
	if(-1 == result)
	{
		printf("匹配不成功\r\n");
	}
	else
	{
		printf("匹配成功，匹配位置：%d\r\n",result);
	}
}


