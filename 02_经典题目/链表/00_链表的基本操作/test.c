#include <stdio.h>
#include <stdlib.h>
int main()
{  
	int i = 0,j;
	i = ({
			j = 9;
	});
	printf("%d\n",i);
}  