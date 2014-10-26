/****************************************************************************
 * @file     03_整数中1的个数.c
 * @brief    
 * @version  V1.00
 * @date     2014.10.21
 * @note     位运算
****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/** 
 * @brief     8位整数中1的个数。
 * @param[in] number      需要计算的数
 * @retval    整数中1的个数
 * @see       None
 * @note      		  
 */
uint8_t NumberOfOne(uint8_t num)
{
	num = (num & 0x55) + ((num>>1) & 0x55);
	num = (num & 0x33) + ((num>>2) & 0x33);
	num = (num & 0x0F) + ((num>>4) & 0x0F);
	return num;
}

int main()
{
	uint8_t number = 0xFF;
	printf("%d  ",NumberOfOne(number));
	
}
