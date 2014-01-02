#include <stdio.h>
#include <stdlib.h>


int strlen_a(const char * str) 
{
	if(str == NULL)
	{
		printf("ÊäÈë×Ö·û´®Îª¿Õ\n");
		exit(0);
	}
	int length = 0 ;
	while (*str++ )
	 ++ length;
	return  length;
 }
 
 int strlen_b(const char * str) 
 {
	if(str == NULL)
	{
		printf("ÊäÈë×Ö·û´®Îª¿Õ\n");
		exit(0);
	}
	const char *cp =  str;
	while (*cp++ );
	return (cp - str - 1 );
 }

int strcmp(const char * src,const char * dst)
{
	if(src == NULL || dst == NULL)
	{
		printf("ÊäÈë×Ö·û´®Îª¿Õ\n");
		exit(0);
	}
	int ret = 0 ;
	while(!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst) 
	{
		++src, ++dst; 		
	}
	if ( ret < 0 )
		ret = -1 ;        
	else if ( ret > 0 )  
		ret = 1 ;
	return ret;
}

char* strcpy(char * dst,const char * src)
{
	char *sr = dst;
	if(src == NULL || dst == NULL)
	{
		printf("ÊäÈë×Ö·û´®Îª¿Õ\n");
		exit(0);	
	}
	while(*dst++ = *src++);
	return sr;
}

char* strcat(char * dst,const char * src)
{
	char *sr = dst;
	if(src == NULL || dst == NULL)
	{
		printf("ÊäÈë×Ö·û´®Îª¿Õ\n");
		exit(0);	
	}
	while(*dst++ = *src++);
	return sr;
}

int main()
{
	char a[10] = "123456789"; 
	char b[10]; 
	printf("%s",strcpy(b,a));
}