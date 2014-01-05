#include <stdio.h>
#include <stdlib.h>

typedef struct stu
{
	int id;
	int age;
} Stu,*Stu_ptr;


int main()
{  
	Stu a = {10,20};
	
	a.id = 20;
	a.age = 30;
	printf("%d,%d",a.id,a.age);
}  