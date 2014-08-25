 /**************************************************************************
 * @file     02_堆的基本操作.c
 * @brief    实现堆的基本操作 
 * @version  V1.00
 * @date     2014.8.25
 * @note     
****************************************************************************/
#include <stdio.h>
#include <malloc.h>

/**		内部函数  
*     
*		用于两个数进行交换。    
*/ 
static void Swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

/**		遍历函数  
*     
*		用于遍历堆。    
*/ 
void Traverse(int *array, int length)
{
	int i;
	for(i = 0; i < length; i++)
	{
		printf("%d  ",array[i]);
	}
	printf("\r\n");
}

/** 
* @brief     堆化操作。
* @param[in] array  原始数组指针
* @param[in] i      从指定节点开始堆化
* @param[in] length 数组长度
* @retval    错误码 0代表成功 1代表参数错误
* @see       None
* @note      	   		  
*/
int MaxHeapify(int *array, int i, int length)
{
	if((NULL == array) || i < 0 || length < 1)
	{
		printf("输入参数有误\n");
		return 1;
	}
	int nextnode = 2 * i + 1;
	int temp;
	while(nextnode < length)
	{
		//选出较大的孩子节点
		if(nextnode + 1 < length)
		{
			//确保该节点存在两个子节点
			nextnode = (array[nextnode + 1] > array[nextnode]) ? (nextnode + 1) : nextnode;
		}
		
		if(array[i] < array[nextnode])
		{
			//若子节点大于该节点，则进行交换
			Swap(&array[i], &array[nextnode]);
			i = nextnode;
			nextnode = 2 * i + 1;
		}
		else
		{
			//否则退出循环
			break;
		}
	}
	return 0;
}

/** 
 * @brief     创建大顶堆。
 * @param[in] array   数组的首指针
 * @param[in] length  链表长度
 * @retval    错误码  0代表成功 1代表参数错误
 * @see       
 * @note      无
 */
int BuildMaxHeap(int *array, int length)
{
	//找出最后一个节点对应的父节点，向前依次进行堆化
	for(int i = (length >> 1) - 1; i >= 0; i--)
	{
		MaxHeapify(array, i, length); 
	}
}



int HeapSort(int *array, int length)
{
	BuildMaxHeap(array, length);
	for(int i = length - 1; i > 0; i--)
	{
		Swap(&array[0], &array[i]);
		MaxHeapify(array, 0 , i);
	}
}

int main()
{
	int ForSort[10] = {9,1,8,2,7,3,4,6,5,0};
	BuildMaxHeap(ForSort, 10);
	HeapSort(ForSort, 10);
	Traverse(ForSort, 10);
}
