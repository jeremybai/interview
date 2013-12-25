#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
#if(0)
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
	ptr =NULL;
	return 0;
#endif
	int array[20] = {1};
	int *ptr;
	ptr = (int *)array;
	printf("\narray size:%d  pointer size:%d\n",sizeof(array),sizeof(ptr));
	printf("array name:%d  array name+1:%d   narray pointer:%d narray pointer+1:%d\n",array,array+1,&array,&array+1);
	ptr =NULL;
}


