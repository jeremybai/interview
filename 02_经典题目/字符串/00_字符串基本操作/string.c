#include <stdio.h>
#include <stdlib.h>


int strlen( char* const old_ptr)
{
	if(old_ptr == NULL)
	{
		printf("ÊäÈë×Ö·û´®Îª¿Õ\n");
		exit(0);
	}
	char *ptr = old_ptr;
	int count = 0;
	while(*ptr++ != '\0')
	{
		count++;
	}
	return count;
}

int strcmp(char* const old_ptr,char* const new_ptr)
{
	if(old_ptr == NULL || new_ptr == NULL)
	{
		printf("ÊäÈë×Ö·û´®Îª¿Õ\n");
		exit(0);
	}
	char *Old_ptr = old_ptr;
	char *New_ptr = new_ptr;
	while(*Old_ptr++ == *New_ptr++ || *Old_ptr == '\0' || *New_ptr == '\0');
	if(*Old_ptr > *New_ptr)
		return 1;
	else if(*Old_ptr < *New_ptr)
		return -1;
	else 
		return 0;
}
int main()
{
	printf("%d\n",strcmp("123","1234"));
}