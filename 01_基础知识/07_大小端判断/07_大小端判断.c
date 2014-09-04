/****************************************************************************
 * @file     07_大小端判断及转换.c
 * @brief    判断当前机器是大端还是小端存储
 * @version  V1.00
 * @date     2014.9.3
 * @note     
****************************************************************************/
#include <stdio.h>
#include <stdbool.h>

#define BigtoLittle16(A)   ((( (uint16)(A) & 0xff00) >> 8)   |   \
							(( (uint16)(A) & 0x00ff) << 8))
							
#define BigtoLittle32(A)   ((( (uint32)(A) & 0xff000000) >> 24)  | \
                            (( (uint32)(A) & 0x00ff0000) >> 8)   | \
                            (( (uint32)(A) & 0x0000ff00) << 8)   | \
                            (( (uint32)(A) & 0x000000ff) << 24))
/** 
 * @brief     测试程序来判断机器的字节序：
 * @param[in] None 
 * @retval    true：大端模式	false：小端模式
 * @see       None
 * @note      		  
 */
bool IsBigEndian()
{
	int a = 0x1234;
	char b =  *(char *)&a;  //通过将int强制类型转换成char单字节，通过判断起始存储位置。即等于取b等于a的低地址部分
	if( b == 0x12)
	{
		printf("大端模式\r\n");
		return true;
	}
	printf("小端模式\r\n");
	return false;
}
/** 
* @brief     测试程序来判断机器的字节序：
* @param[in] None 
* @retval    true：大端模式	false：小端模式
* @see       None
* @note      联合体union的存放顺序是所有成员都从低地址开始存放，利用该特性
			 可以轻松地获得了CPU对内存采用Little-endian还是Big-endian模式读写		  
*/
bool IsBigEndian1()
{
	union NUM
	{
		int a;
		char b;
	}num;
	num.a = 0x1234;
	if( num.b == 0x12 )
	{
		printf("大端模式\r\n");
		return true;
	}
	printf("小端模式\r\n");
	return false;
}

int main()
{
	printf("%d",IsBigEndian1());
}