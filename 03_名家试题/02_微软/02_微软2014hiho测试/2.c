#include <stdio.h>

void Reverse(char* begin,char* end)
{
	if(NULL == begin ||  NULL == end)
	{
		printf("²ÎÊı´íÎó!\n");
		return ;
	}
	while(begin < end)
	{
		*begin ^= *end;
		*end ^= *begin;
		*begin++ ^= *end--;
	}
}
	
void fun1(char* str, int begin, int end, char c)
{
	int i;
	for(i = begin; i <= end; i++)
		str[i-1] = c;
}	

void fun2(char* str, int begin, int end, int num)
{
	int i,j;
	for(i = begin; i <= end; i++)
	{
		for(j = 0; j < num; j++)
		{
			if(str[i-1] >= 'Z')
				str[i-1] = 'A';
			else
				str[i-1] += 1;
		}
	}
}

void fun3(char* str, int num, int length)
{
	Reverse(str, str+num-1);
	Reverse(str+num, str+length-1);
	Reverse(str, str+length-1);
}
	
void fun4(char* str, int i, int j)
{
	if(i <= j)
	{
		fun4(str, i+1, j);
		fun2(str, i, j, 1);
	}
}

int main(void) {
    int N, M,i ,j ,k , m , n;
	char *str;
	//char a[8] = "ABCDEFG";
	//printf("%s\r\n", a);
	//fun4(a,2,3);
	//printf("%s\r\n", a);
	int a,b,c;
    while(scanf("%d", &N) != EOF) 
	{
    	if(scanf("%d", &M) != EOF) 
		{
			if(NULL == (str = (char*)malloc(sizeof(char)*(N+1))))
			{
				return 0;
			}
			scanf("%s", str);
			printf("%s\r\n", str);
			char **array = (char**)malloc(sizeof(char*)*M);
			for(i = 0; i < M; i++)
			{
				array[i] = (char*)malloc(sizeof(char)*20);
				gets(array[i]);
				gets(array[i]);
				printf("%s\r\n", array[i]);
				k = 0;
				while(array[i][k] != ' ')
					k++;
				printf("k = %d \r\n", k);
				while(array[i][k] == ' ')
					k++;
				printf("k = %d \r\n", k);
				if(array[i][k] == '1')
				{
					while(array[i][k] != ' ')
						k++;
					while(array[i][k] == ' ')
						k++;
					a = array[i][k] -'0';
					while(array[i][k] != ' ')
						k++;
					while(array[i][k] == ' ')
						k++;
					b = array[i][k]-'0';	
					while(array[i][k] != ' ')
						k++;
					while(array[i][k] == ' ')
						k++;
					c = array[i][k];
					printf("%d  %d  %c\r\n",a,b,c);
					fun1(str,a,b,c);					
				}
				else if(array[i][k] == '2')
				{
					while(array[i][k] != ' ')
						k++;
					while(array[i][k] == ' ')
						k++;
					a = array[i][k]-'0';
					while(array[i][k] != ' ')
						k++;
					while(array[i][k] == ' ')
						k++;
					b = array[i][k]-'0';	
					while(array[i][k] != ' ')
						k++;
					while(array[i][k] == ' ')
						k++;
					c = array[i][k]-'0';
					fun2(str,a,b,c);					
				}
				else if(array[i][k] == '3')
				{
					while(array[i][k] != ' ')
						k++;
					while(array[i][k] == ' ')
						k++;
					a = array[i][k]-'0';
					fun3(str,a,N);						
				}
				else if(array[i][k] == '4')
				{
					while(array[i][k] != ' ')
						k++;
					while(array[i][k] == ' ')
						k++;
					a = array[i][k]-'0';
					while(array[i][k] != ' ')
						k++;
					while(array[i][k] == ' ')
						k++;
					b = array[i][k]-'0';	
					fun4(str,a,b);								
				}				
			}
			printf("%s",str);
		}
    }
    return 0;
}