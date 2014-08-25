/****************************************************************************
 * @file     05_复杂链表的复制.c
 * @brief    复杂链表的复制
 * @version  V1.00
 * @date     2014.7.24
 * @note     时间复杂度:最好:  最坏:
 * @note     
 ****************************************************************************/
#include <stdio.h>
#include <malloc.h>

/**		节点数据类型 \n  
 *     
 *		定义节点数据类型。    
 */
typedef int ElementType;
/**		链表结构体定义 \n  
 *     
 *		定义链表节点所包含的成员变量，包含指向下一个节点的指针和当前节点的值。    
 */ 
typedef struct complexlistnode 
{
	int m_nValue;
	struct complexlistnode * m_pNext;
	struct complexlistnode * m_pSibling;
} ComplexListNode,*ComplexListNode_ptr;

/** 
 * @brief     复杂链表的复制。
 * @param[in] pHead:需要复制的链表头
 * @retval    ComplexListNode *  返回复制链表的首指针。
 * @see       ComplexListNode
 * @note      无
 */
ComplexListNode* Clone(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	
	while(NULL != pNode->m_pNext )
	{
		ComplexListNode *pNew = malloc(sizeof(ComplexListNode));
		pNew->m_nValue = pNode->m_nValue;
		pNew->m_pNext = pNode->m_pNext;
		pNew->m_pSibling = NULL;
	}	
}


 int main()
 {
	ComplexListNode a;
	a.m_nValue = 1;
	ComplexListNode b;
	b.m_nValue = 2;
	ComplexListNode c;
	c.m_nValue = 3;	
	
	a.m_pNext = &b;
	b.m_pNext = &c;
	c.m_pNext = NULL;
	
	ComplexListNode *p = Clone(&a);
	while(NULL != p)
	{
		printf("%d   ",p->m_nValue);
		p = p->m_pNext;
	}	
 }
