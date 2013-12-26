/**************************************************************************
 * @file     输入函数区别.c
 * @brief    了解scanf(),getchar()和gets()等函数
 * @version  V1.00
 * @date     2013.12.25
 * @note     scanf()函数读取数据是遇到回车、空格、TAB就会停止；
			 scanf()读取字符串会舍弃最后的回车符；			scanf()读取字符串时，字符串中不可以出现空格，一旦出现空格，后面
			 的数据就会舍弃残留在缓冲区中被下一次读取。
			 gets()读取字符串可以接受空格。
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string>
/* 
读取字符时：
1 scanf()以Space、Enter、Tab结束一次输入，不会舍弃最后的回车符（即回车符会残留
  在缓冲区中）；
2 getchar()以Enter结束输入，也不会舍弃最后的回车符；
读取字符串时：
1 scanf()以Space、Enter、Tab结束一次输入，不接受空格，会舍弃最后的回车符；
2 gets()以Enter结束输入（空格不结束），接受空格，会舍弃最后的回车符！


解决方法：
1  C语言里提供了函数（fflush(stdin)）清空缓冲区，只要在读数据之前先清空缓冲区就没问题。
2  自己取出缓冲区里的残留数据：scanf("%[^\n]",string);
*/

#define READSTRING1
int main()
{
/* scanf()和getchar()函数是从输入流缓冲区中读取值的，而并非从键盘(也就是终端)缓冲区读取。而读取时遇到回车('\n')而结束的，这个'\n'会一起读入输入流缓冲区的，所以第一次接受输入时取走字符后会留下字符'\n'，这样第二次的读入函数直接从缓冲区中把'\n'取走了，显然读取成功了，所以不会再从终端读取！这就是为什么这个程序只执行了一次输入操作就结束的原因！ 
*/
#if defined SCANF
	printf("SCANF TEST\n");
	char ch1, ch2;
	scanf("%c", &ch1); 
	scanf("%c", &ch2);
	printf("%d %d\n", ch1, ch2);
#elif defined GETCHAR   
	printf("GETCHAR TEST\n");
	char ch1, ch2;
	ch1 = getchar();
	ch2 = getchar();
	printf("%d %d\n", ch1, ch2);
#elif defined READSTRING1   
	char str1[20], str2[20];
	scanf("%s",str1); 
	printf("%s\n",str1);    
	scanf("%s",str2); 
	printf("%s\n",str2); 
#elif defined READSTRING2   
	char str1[20], str2[20];
	gets(str1); 
	printf("%s\n",str1);    
	gets(str2); 
	printf("%s\n",str2); 
#endif	

   printf("日期：%s\n",__DATE__);
   printf("时间：%s\n",__TIME__);
   printf("文件名：%s\n",__FILE__);
   printf("这是第%d行代码\n",__LINE__);
   printf("本编译器%s标准C\n",(__STDC__)?"符合":"不符合");
}

    
	