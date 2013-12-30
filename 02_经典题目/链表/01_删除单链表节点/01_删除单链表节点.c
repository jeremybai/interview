/****************************************************************************
 * @file     01_删除单链表节点.c
 * @brief    删除单链表中符合条件的节点 
 * @version  V1.00
 * @date     2013.12.30
 * @note     无
****************************************************************************/
#include <stdio.h>
#include <malloc.h>


/**		链表结构体定义 \n  
 *     
 *		定义链表节点所包含的成员变量，包含指向下一个节点的指针和当前节点的值。    
 */ 
typedef struct node 
{
	struct node * next;
	int node_val;
} node;

/**		判断节点是否需要删除的函数指针 \n  
 *     
 *		自定义判断节点是否需要删除的函数指针。    
 */ 
typedef bool (* remove_fn)(node const * v);

//
/** 
 * @brief     Linus所说的删除单链表中所有满足条件的节点的方法。
 * @param[in] head  指向头节点的二级指针
 * @param[in] rm    自定义节点是否删除的函数指针
 * @retval    None
 * @see       node
 * @note      相比于基本方法不需要维护指向前一个节点的prev指针了，
			  也不需要再去判断是否为链表头了
 */
void remove_if(node ** head, remove_fn rm)
{
    for (node** curr = head; *curr; )
    {
        node * entry = *curr;
        if (rm(entry))
        {
            *curr = entry->next;
            free(entry);
        }
        else
            curr = &entry->next;
    }
}

/** 
 * @brief     删除单链表中所有满足条件的节点的基本方法。
 * @param[in] head  指向头节点的指针
 * @param[in] rm    自定义节点是否删除的函数指针
 * @retval    None
 * @see       node
 * @note      无
 */
node * remove_if_basic(node * head, remove_fn rm)
{
	for(node *prev = NULL, *curr = head ;curr != NULL; )
	{
		node *next = curr->next;
		if (rm(curr))
		{
			if(prev)
				prev-next = next;    //删除的不是头结点 
			else	
				head =  next;        //删除的是头结点
			free(curr);
		}
		else
			prev = curr;
		curr = next;
	}
	return head;
}

int main()
{	
	
}