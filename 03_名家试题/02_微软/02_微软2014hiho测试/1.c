#include <stdio.h>
#include <malloc.h>	
#include <string.h>	
int main(void) {
    int num, i, j, k,m,n,l, length, len1,len2,len3;
	char *str;
	char temp;
    while(scanf("%d", &num) != EOF) 
	{
		for(i = 0; i < num; i++)
		{
			if(scanf("%d", &length) != EOF) 
			{
				if(NULL == (str = (char*)malloc(sizeof(char)*length)))
				{
					return 0;
				}
				scanf("%s", str);

				for(j = 0; j <= length - 3; j++)
				{
					if(str[j] < 'a' || str[j] > 'z')
					{
						printf("NO\r\n");
						break;
					}
					k = j+1;
					while(str[j] == str[k])
					{
						k++;
					}
					len1 = k-j;
					if(str[k] == str[j]+1)
					{
						l = k+1;
						while(str[l] == str[k])
						{
							l++;
						}
						len2 = l-k;
						if(len2 == len1)
						{
							if(str[l] == str[j]+2)
							{
								m = l+1;
								while(str[m] == str[l])
								{
									m++;
								}
								len3 = m-l;
								if(len3 == len2)
								{
									printf("YES\r\n");
									break;									
								}
								else
								{
									printf("NO\r\n");
									break;									
								}
							}
							else
							{
								printf("NO\r\n");
								break;
							}
						}
						else
						{
							printf("NO\r\n");
							break;
						}
					}
					else
					{
						printf("NO\r\n");
						break;
					}
				}
				free(str);
				str = NULL;
			}			
		}
    }
    return 0;
}