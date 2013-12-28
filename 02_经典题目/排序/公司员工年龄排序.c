/****************************************************************************
 * @file     公司员工年龄排序.c
 * @brief    某公司有几万名员工，请完成一个时间复杂度为O(n)的算法对该公司员工
			 的年龄作排序，可使用O(1)的辅助空间。
 * @version  V1.00
 * @date     2013.12.28
 * @note     员工的数目虽然有几万人，但这几万员工的年龄却只有几十种可能。该方
			 法用长度100的整数数组辅助空间（年龄的Hash表）换来了O(n)的时间效率。
			 由于不管对多少人的年龄作排序，辅助数组的长度是固定的100个整数，
			 因此它的空间复杂度是个常数，是O(1)。
****************************************************************************/
#include "stdio.h"   

/** 
 * @brief     根据输入的年龄数组和长度，将数组内数据重新排序。
 * @param[in] ages    存放年龄的数组
 * @param[in] length  数组的长度（员工的个数）
 * @retval    None
 * @see       None
 * @note      无
 */
void SortAges(int ages[], int length)
{
    if(ages == NULL || length <= 0)
        return;
 
    const int oldestAge = 99;
    int timesOfAge[oldestAge + 1];
 
    for(int i = 0; i <= oldestAge; ++ i)
        timesOfAge[i] = 0;
 
    for(int i = 0; i < length; ++ i)
    {
        int age = ages[i];
        if(age < 0 || age > oldestAge)
		{
            printf("age out of range.\n");
			return ;
		}
        ++ timesOfAge[age];
    }
 
    int index = 0;//年龄在ages中的索引
    for(int i = 0; i <= oldestAge; ++ i)
    {
        for(int j = 0; j < timesOfAge[i]; ++ j)
        {
            ages[index] = i;
            ++ index;
        }
    }
}

int main()
{
	int i;
	int ages[16] = {25,24,26,24,25,19,25,29,36,80,76,76,76,45,25,48};
	SortAges(ages,16);
	for(i = 0; i < 16; i++)
	{
		printf("%d  ",ages[i]);
	}
}