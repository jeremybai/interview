#include <stdio.h>
#include <stdlib.h>

typedef struct stu
{
	int id;
	int age;
} Stu,*Stu_ptr;


int main()
{
	Stu a;
	stu *b = &a;
	a.id = 2;
	(&a)->age = 10;
	(*b).id = 2;
	b->age = 10;
	printf("%d,%d\n",a.id,a.age);
		printf("%d,%d",b->id,b->age);
}  

