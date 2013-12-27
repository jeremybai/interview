/**************************************************************************
 * @file     02_new和malloc区别.cpp
 * @brief    malloc/free与new/delete的区别。
 * @version  V1.00
 * @date     2013.12.26
 * @note     
****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

malloc与free是C++/C 语言的标准库函数，new/delete 是C++的运算符。对于非内部数
据类的对象而言，光用maloc/free 无法满足动态对象的要求。对象在创建的同时要自动
执行构造函数， 对象消亡之前要自动执行析构函数。由于malloc/free是库函数而不
是运算符，不在编译器控制权限之内，不能够把执行构造函数和析构函数的任务强加
malloc/free。


int main()
{
 int* p = (int*)malloc(2*sizeof(float));

}


