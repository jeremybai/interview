#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void strRev1(char *s)
{
    char temp, *end = s + strlen(s) - 1;
    while( end > s)
    {
        temp = *s;
        *s++ = *end;
        *end-- = temp;
    }
}
void strRev2(char *s)
{
    char temp;
    for(char *end = s + strlen(s) - 1; end > s ; --end, ++s)
    {
        temp = *s;
        *s = *end;
        *end = temp;
    }
}

void strRev3(char *s)
{
    for(char *end = s + strlen(s) - 1; end > s ; --end, ++s)
    {
        *s ^= *end;
        *end ^= *s;
        *s ^= *end;
    }
} 
int main()
{
	char *p;
	if(NULL == (p = (char*)malloc(10*sizeof(int))))
	{
		printf("Error\n");
		return 1;
	}
	memcpy(p,"123456789",10);
	strRev1(p);
	printf("%s",p);
}
