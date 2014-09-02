/****************************************************************************
 * @file     01_二叉搜索树的后序遍历.c
 * @brief    输入一个字符串，判断该数组是不是某二叉搜索树的后序遍历
 * @version  V1.00
 * @date     2014.7.22
 * @note     时间复杂度:   空间复杂度:
 * @note     
 ****************************************************************************/
 #include <stdio.h>
 #include <stdbool.h>
 /** 
 * @brief     判断输入数组是不是某二叉搜索树的后序遍历
 * @param[in] 数组的指针
 * @param[in] 数组的长度
 * @retval    true：数组是某二叉搜索树的后序遍历 false：数组不是某二叉搜索树
			  的后序遍历。
 * @see       Node
 * @note      无
 */
 bool IsPostOrder(int *array, int length)
 {
	if(NULL == array || 0 == length)
	{
		//printf("param error!\r\n");
		return false;
	}
	if(length == 1)
		return true;
	int root = array[length-1];
	int i,j;
	bool left,right;
	for(i = 0; i < length-1; i++)
	{
		if(array[i] > root)
			break;
	}
	j = i;
	for(; j < length-1; j++)
	{
		if(array[j] < root)
		{
			return false;
		}
	}
	left = true;
	if(i > 0)
		left = IsPostOrder(array,i);
	right = true;
	if(i < length - 1)
		right = IsPostOrder(array+i, length-i-1);
	return (left&&right);
 }
 
 int main()
 {
	int test[] = {5,7,6,9,11,10,8};
	int test1[] = {7,4,6,5};
	int *test2 = NULL;
	printf("%d",IsPostOrder(test,sizeof(test)/sizeof(int)));		
	printf("%d",IsPostOrder(test1,sizeof(test1)/sizeof(int)));
	printf("%d",IsPostOrder(test2,sizeof(test2)/sizeof(int)));
 }
 
 