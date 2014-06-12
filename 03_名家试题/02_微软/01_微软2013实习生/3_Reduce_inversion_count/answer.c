/****************************************************************************
 * @file     answer.c
 * @brief    参见description。
 * @version  V1.00
 * @date     2014.5.1
 * @note     
****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


/** 
 * @brief     归并排序函数实现从小到大排序。
 * @param[in] array  原始数组指针
 * @param[in] temp   用于存放排序的数组
 * @param[in] begin  数组起始位置
 * @param[in] end    数组结束位置
 * @retval    
 * @see       None
 * @note      		  
 */
int MergeSort(int *array, int *temp, int begin, int end)
{
	int inv_count = 0;  //记录逆序数
	if(NULL == array || NULL == temp )
	{
		printf("参数错误!\n");
		return -1;
	}
	int mid;
	if(begin < end)
	{
		//将数组分成两部分，分别进行归并排序，再将两个排好序的数组进行合并
		mid = (begin + end)/2;
		inv_count = MergeSort(array, temp, begin, mid);
		inv_count += MergeSort(array, temp, mid + 1, end);
		inv_count += Merge(array, temp, begin, mid + 1, end);
	}
	return inv_count;
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
		return -1;
	}
	int inv_count = 0;
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
			inv_count += mid - i;
			temp[k++] = array[j++];
		}
	}
	//拷贝剩余的元素到缓冲区temp
	while(i <= mid-1)
	{
		temp[k++] = array[i++];
	}
	while(j <= end)
	{
		temp[k++] = array[j++];
	}
	//将temp中排好序的数据复制到array中
	for(i = begin; i <= end; i++)
	{
		array[i] = temp[i];
	}
	return inv_count;
}


int main()
{
	int i,j,k,decrease,max,inv_count,num,arr_num;
	char *str = (char*)malloc(100*sizeof(char));
	int *SourceArray = (int*)malloc(100*sizeof(int));
	while(scanf("%s", str) != EOF) 
	{
		i = j = num = 0;
		while(str[i] != '\0')
		{
			if(str[i] >= '0' && str[i] <= '9')
			{
				num *= 10;
				num += str[i] - '0';
			}
			else
			{
				SourceArray[j++] = num;
				num = 0;
			}
			str[i++] = '\0';
		}
		SourceArray[j++] = num;
		arr_num = j;
		int *temp = (int*)malloc(arr_num*sizeof(int));
		int *copy = (int*)malloc(arr_num*sizeof(int));
		memcpy(copy,SourceArray,arr_num*sizeof(int));
		//printf("当前逆序数的个数为：%d  \n",inv_count = MergeSort(copy,temp,0,arr_num-1));
		inv_count = MergeSort(copy,temp,0,arr_num-1);
		max = 0;
		for(i = 0; i < arr_num-1; i++)
		{
			for(j = i + 1; j < arr_num; j++)
			{
				
				if(SourceArray[i] <= SourceArray[j])
					continue;
				decrease = 1;
				//影响的是i和j之间的数，即i+1到j-1
				for(k = i + 1; k < j; k++)
				{
					if((SourceArray[k] <  SourceArray[i]) && (SourceArray[k] > SourceArray[j]))
					{
						decrease = decrease + 2;
					}
					if(SourceArray[k] == SourceArray[i] || SourceArray[k] == SourceArray[j])
					{
						decrease++;
					}
				}
				if(decrease > max)
				{
					max = decrease;
				}
			}
		}		
		printf("%d\n",inv_count - max);
		free(temp);
		free(copy);
		temp = copy = NULL;
	}
	free(str);
	str = NULL;
}
