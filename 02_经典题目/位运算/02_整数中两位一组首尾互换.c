/****************************************************************************
 * @file     02_整数中两位一组首尾互换.c
 * @brief    一个32位unsigned int型值，2位2位一组，两头互换，最后返回结果一个
 * 			 32 位的unsigned int型值。
 * @version  V1.00
 * @date     2014年6月12日
 * @note     位运算
****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/** 
 * @brief     整数中两位互换。
 * @param[in] number      需要反转的数
 * @retval    成功：0，失败：1
 * @see       None
 * @note      比如0b01011010，变为10100101。		  
 */
uint32_t Swap2Bits(uint32_t number)
{
	uint32_t a;
	a = ((number & 0xC0000000)>>30) | ((number & 0x00000003)<<30)
	| ((number & 0x30000000)>>26) | ((number & 0x0000000C)<<26)
	| ((number & 0x0C000000)>>22) | ((number & 0x00000030)<<22)
	| ((number & 0x03000000)>>18) | ((number & 0x000000C0)<<18)
	| ((number & 0x00C00000)>>14) | ((number & 0x00000300)<<14)
	| ((number & 0x00300000)>>10) | ((number & 0x00000C00)<<10)
	| ((number & 0x000C0000)>>6) | ((number & 0x00003000)<<6)
	| ((number & 0x00030000)>>2) | ((number & 0x0000C000)<<2);
	return a;
}

/** 
 * @brief     32bits按二进制位反转。
 * @param[in] number      需要反转的数
 * @retval    成功：0，失败：1
 * @see       None
 * @note      查表法，比如0b01010101010101010101010101010101，
 *			  变为0b10101010101010101010101010101010。		  
 */
uint32_t Swap2Bits_ST(uint32_t number)
{
	static unsigned char rchars[] = "\0\x08\x04\x0c\x02\x0a\x06\x0e\x01\x09\x05\x0d\x03\x0b\x07\x0f";
	
	return (rchars[(number>>28)&0xF] ) | ((rchars[(number>>24)&0xF])<<4)|
			((rchars[(number>>20)&0xF])<<8) | ((rchars[(number>>16)&0xF])<<12) | 
			((rchars[(number>>12)&0xF])<<16)| ((rchars[(number>>8)&0xF])<<20) |
			((rchars[(number>>4)&0xF])<<24) | ((rchars[(number)&0xF])<<28);
}
/** 
 * @brief     8bits按二进制位反转。
 * @param[in] number      需要反转的数
 * @retval    成功：0，失败：1
 * @see       None
 * @note      查表法，比如0b01010101，变为0b10101010。		  
 */
unsigned char reserve_bin(unsigned char value )
{
    static unsigned char rchars[] = "\0\x08\x04\x0c\x02\x0a\x06\x0e\x01\x09\x05\x0d\x03\x0b\x07\x0f";
    return rchars[value >> 4] | ( rchars[value & 0x0F] << 4 );

}

/** 
 * @brief     8bits按十进制位反转。
 * @param[in] number      需要反转的数
 * @retval    成功：0，失败：1
 * @see       None
 * @note      	  
 */
unsigned char reserve_dec( unsigned char value )
{
    return (value / 100) + ( value / 10 % 10 * 10 ) + (value % 10 * 100);
}
 
/** 
 * @brief     8bits按十六进制位反转。
 * @param[in] number      需要反转的数
 * @retval    成功：0，失败：1
 * @see       None
 * @note      	  
 */
unsigned char reserve_hex( unsigned char value)
{
    return ((value << 4) & 0xFF) | ((value >> 4) & 0xFF);
}

int main()
{
	uint32_t number = 0x12345678;//反转之后等于0x1E2A6C48
	char a[40];
	itoa(number, a, 2);
	printf("%32s    %X\n", a, number);
	number = Swap2Bits_ST(number);
	itoa(number, a, 2);
	printf("%32s     %X\n",a,number);
	
	unsigned char value  = 0xAF;
	printf("%X  ",reserve_hex(value));
}
