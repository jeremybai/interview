#include <stdio.h>


int main()
{
	char s[100];
	while(gets(s))  //返回NULL
	{
		if(strlen(s) == 0);
		{
			break;
		}
	}
		printf("length: %d\n", strlen(s));   
		printf("%s\n", s);
}