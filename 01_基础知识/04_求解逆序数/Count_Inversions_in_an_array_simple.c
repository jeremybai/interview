/****************************************************************************
 * @file     Count_Inversions_in_an_array_simple.c
 * @brief    列出数组中所有的逆序数
 * @version  V1.00
 * @date     2014年5月26日
 * @note     思路：暴力求解。
****************************************************************************/

/**		求解逆序数   
 *     
 *		遍历数组，如果i < j && arr[i] > arr[j]，计数自加1。    
 */ 
int getInvCount(int arr[], int n)
{
	int inv_count = 0;
	int i, j;

	for(i = 0; i < n - 1; i++)
		for(j = i+1; j < n; j++)
			if(arr[i] > arr[j])
				inv_count++;
	return inv_count;
}


int main(int argv, char** args)
{
	int arr[] = {1, 20, 6, 4, 5};
	printf(" Number of inversions are %d \n", getInvCount(arr, 5));
	getchar();
	return 0;
}