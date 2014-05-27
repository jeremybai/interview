#include <stdio.h>
#include <stdint.h>
//#include <stdlib.h>

int main()
{
	char *ptr;
	uint32_t i;
	if (NULL == (ptr = (char *)malloc(10*sizeof (char)))) 
	{
		perror("error...");
		exit(1);
	}
	for(i = 0; i < 9;i++)
	{
		ptr[i] = '0'+i;
	}
	ptr[9] = '\0';
	printf("%s\n",ptr);
	free(ptr);
	ptr = NULL;
	return 0;
}


