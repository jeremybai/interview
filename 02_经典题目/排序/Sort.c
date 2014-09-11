/****************************************************************************
* @file     Sort.c
* @brief    七种基本排序算法实现及复杂度稳定性。
* @version  V1.00
* @date     2014.2.24
* @note     
****************************************************************************/
#include <stdio.h>
#include <stdint.h>

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

/** 
* @brief     冒泡排序函数实现从小到大排序。
* @param[in] array  数组起始地址
* @param[in] length  数组大小
* @retval    None
* @see       None
* @note      时间复杂度O(n^2)；最好情况O(n)；最坏情况O(n^2)；
			空间复杂度O(1)；稳定。
			改进1：设置一个标志，如果这一趟发生了交换，则为true，否则为false。
				   明显如果有一趟没有发生交换，说明排序已经完成。
			改进2：如果有100个数的数组，仅前面10个无序，后面90个都已排好序且
				   都大于前面10个数字，那么在第一趟遍历后，最后发生交换的位置
				   必定小于10，且这个位置之后的数据必定已经有序了，记录下这位
				   置，第二次只要从数组头部遍历到这个位置就可以了。			  
*/
int BubleSort(int *array, int length)
{
	if((NULL == array) || length < 1)
	{
		printf("输入参数有误\n");
		return 1;
	}
	int i,j;
	for(i = 0; i < length-1; i++)
	{
		for(j = 0; j < length-1-i; j++)
		{
			if(array[j] > array[j+1])
			{
				Swap(&array[j],&array[j+1]);
			}
		}
	}
	return 0;
}

/** 
* @brief     归并排序函数实现从小到大排序。
* @param[in] array  原始数组指针
* @param[in] temp   用于存放排序的数组
* @param[in] begin  数组起始位置
* @param[in] mid    第二个数组起始位置
* @param[in] end    数组结束位置
* @retval    错误码 0代表成功 1代表参数错误
* @see       None
* @note      		  
*/
int Merge(int *array, int *temp, int begin, int mid, int end)
{
	if(NULL == array || NULL == temp )
	{
		printf("参数错误!\n");
		return 1;
	}
	int i = begin;
	int j= mid;
	int k = begin;
	//将两个数组依次进行比较，把小的存放至temp数组，再将temp数组拷贝至array
	while((i <= mid - 1) && (j <= end))
	{
		if(array[i] <= array[j])
		{
			temp[k++] = array[i++];
		}
		else
		{
			temp[k++] = array[j++];
		}
	}
	while(i <= mid-1)
	{
		temp[k++] = array[i++];
	}
	while(j <= end)
	{
		temp[k++] = array[j++];
	}
	for(i = begin; i <= end; i++)
	{
		array[i] = temp[i];
	}
	return 0;
}

/** 
* @brief     归并排序函数实现从小到大排序。
* @param[in] array  原始数组指针
* @param[in] temp   用于存放排序的数组
* @param[in] begin  数组起始位置
* @param[in] end    数组结束位置
* @retval    错误码 0代表成功 1代表参数错误
* @note      时间复杂度O(nlgn)；最好情况O(nlgn)；最坏情况O(nlgn)；
			空间复杂度O(1)；稳定。	    		  
*/
int MergeSort(int *array, int *temp, int begin, int end)
{
	if(NULL == array || NULL == temp )
	{
		printf("参数错误!\n");
		return 1;
	}
	int mid;
	if(begin < end)
	{
		//将数组分成两部分，分别进行归并排序，再将两个排好序的数组进行合并
		mid = (begin + end)/2;
		MergeSort(array, temp, begin, mid);
		MergeSort(array, temp, mid + 1, end);
		Merge(array, temp, begin, mid + 1, end);
	}
	return 0;
}

/** 
* @brief     插入排序函数实现从小到大排序。
* @param[in] array  数组起始地址
* @param[in] length  数组大小
* @retval    None
* @see       None
* @note      时间复杂度O(n^2)；最好情况O(n)；最坏情况O(n^2)；
			 空间复杂度O(1)；稳定。			  
*/
int InsertSort(int *array, int length)
{
	if((NULL == array) || length < 1)
	{
		printf("输入参数有误\n");
		return 1;
	}
	int i = 0, j = 0, temp = 0;  
	for(i = 1; i < length; i++)
	{
		for(j = i - 1; j >= 0 && array[j] > array[j+1]; j--)
		{
			Swap(&array[j], &array[j+1]);
		}
	}	
	return 0;
}

/** 
* @brief     快速排序函数实现从小到大排序。
* @param[in] array  数组起始地址
* @param[in] length  数组大小
* @retval    None
* @see       None
* @note      时间复杂度O(nlgn)；最好情况O(nlgn)；最坏情况O(n^2)；
			空间复杂度O(nlgn)；不稳定。			  
*/
void QuickSort(int *array, int low,int high)
{
	if((NULL == array) || low < 0 || high < 0)
	{
		printf("输入参数有误\n");
		return;
	}
	if ( low < high ) 
	{
		int i = low, j = high, temp = array[low];
		while ( i < j ) 
		{
			//从右往左扫描，如果数组元素大于temp,
			//则继续，直至找到第一个小于temp的元素
			while ( i < j && array[j] >= temp ) 
			{
				--j;
			}
			if ( i < j ) {
				array[i++] = array[j];
			}
			//从左往右扫描，如果数组元素小于temp,
			//则继续，直至找到第一个大于temp的元素
			while ( i < j && array[i] <= temp ) {
				++i;
			}
			if ( i < j ) {
				array[j--] = array[i];
			}
		}
		array[i] = temp;
		QuickSort(array, low, i - 1);
		QuickSort(array, i + 1, high);
	}
}

/** 
* @brief     选择排序函数实现从小到大排序。
* @param[in] array  原始数组指针
* @param[in] length 数组长度
* @retval    错误码 0代表成功 1代表参数错误
* @see       None
* @note      时间复杂度O(n^2)；最好情况O(n^2)；最坏情况O(n^2)；
			 空间复杂度O(1)；不稳定。	   		  
*/
int SelectSort(int *array, int length)
{
	if(NULL == array || 0 == length )
	{
		printf("参数错误!\n");
		return 1;
	}
	int i,j,min,min_index;
	for(i = 0; i < length-1; i++)
	{
		min = array[i],min_index = i;
		for(j = i; j < length; j++)
		{
			if(array[j] < min)
			{
				min = array[j];
				min_index = j;
			}
		}
		if(i != min_index)
			Swap(&array[i],&array[min_index]);
	}
	return 0;
}

/** 
* @brief     希尔排序函数实现从小到大排序。
* @param[in] array  原始数组指针
* @param[in] length 数组长度
* @retval    错误码 0代表成功 1代表参数错误
* @see       None
* @note      时间复杂度O(n^1.3)；最好情况O(n)；最坏情况O(n^2)；
			空间复杂度O(1)；不稳定(相同两个数在不同的序列中
			可能导致相对顺序发生变化)。	   		  
*/
int ShellSort(int array[], int length)
{
	if((NULL == array) || length < 1)
	{
		printf("输入参数有误\n");
		return 1;
	}
	int gap, i, j, temp;
	for(gap = length/2; gap > 0; gap /= 2)
	{
		//gap每次减半
		for(i = gap; i < length; i++)
		{
			//对间隔gap的数列进行插入排序，array[j]前的数列是有序的，所以只需要将
			//array[j+gap]插入到前面的序列中
			for(j = i - gap; j >= 0 && array[j] > array[j+gap]; j -= gap)
			{
				Swap(&array[j], &array[j+gap]);
			}	
		}
	}

}

/** 
* @brief     堆化操作。
* @param[in] array  原始数组指针
* @param[in] i      从指定节点开始堆化
* @param[in] length 数组长度
* @retval    错误码 0代表成功 1代表参数错误
* @see       None
* @note      时间复杂度O(nlgn)；最好情况O(nlgn)；最坏情况O(nlgn)；
			 空间复杂度O(1)；不稳定。	   		  
*/
void HeapAjust(int array[],int i,int length)
{
	if((NULL == array) || i < 0 || length < 1)
	{
		printf("输入参数有误\n");
		return;
	}	
	int nChild;
	int nTemp;
	//若改变了顺序，则将nChild赋值为i，继续堆化
	for(nTemp = array[i]; 2 * i + 1 < length; i = nChild)
	{
		//左孩子
		nChild = 2 * i + 1;
		//选出较大的孩子
		if(nChild < length -1 && array[nChild+1] > array[nChild])
		{
			nChild++;
		}
		//如果比自己的最大的孩子小，就交换
		if(nTemp < array[nChild])
		{
			array[i] = array[nChild];
			array[nChild] = nTemp;
		}
		else//如果比最大的孩子还大，就不交换
			break;
	}
}

/** 
* @brief     堆排序函数实现从小到大排序。
* @param[in] array  原始数组指针
* @param[in] length 数组长度
* @retval    错误码 0代表成功 1代表参数错误
* @see       None
* @note      时间复杂度O(nlgn)；最好情况O(nlgn)；最坏情况O(nlgn)；
			 空间复杂度O(1)；不稳定。	   		  
*/
int HeapSort(int array[],int length)
{
	if((NULL == array) || length < 1)
	{
		printf("输入参数有误\n");
		return 1;
	}	
	int i,j;
	//i=(length>>1)-1，加上括号，原因：优先级的问题
	for(i = (length>>1) - 1; i >= 0; i--)
	{
		HeapAjust(array,i,length); //初始化一个堆
	}

	for(j = length-1; j > 0; --j)
	{
		Swap(&array[0], &array[j]);//交换堆顶元素和最后一个元素
		//此时数组分为无序区0 ~ j和有序区j ~ length-1
		HeapAjust(array,0,j);      //将无序区重新堆化
	}
}

int main()
{
	int ForSort[10] = {9,1,8,2,7,3,4,6,5,0},i;
	int ForSort1[10] = {0,1,2,3,4,5,6,7,8,9};
	int ForSort2[10] = {9,8,7,6,5,4,3,2,1,0};
	QuickSort(ForSort,0,9);
	for(i = 0; i < 10; i++)
	{
		printf("%d   ",ForSort[i]);
	}
}
