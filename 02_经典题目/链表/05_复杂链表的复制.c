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
 * @brief     链表m_pNext的复制。
 * @param[in] pHead:需要复制的链表头
 * @retval    0:成功
 * @see       ComplexListNode
 * @note      无
 */
int Clone(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	
	while(NULL != pNode)
	{
		ComplexListNode *pNew = malloc(sizeof(ComplexListNode));
		pNew->m_nValue = pNode->m_nValue;
		pNew->m_pNext = pNode->m_pNext;
		pNew->m_pSibling = NULL;
		
		pNode->m_pNext = pNew;
		pNode = pNew->m_pNext;
	}	
	return 0;
}

/** 
 * @brief     链表m_pSibling的复制。
 * @param[in] pHead:需要复制的链表头
 * @retval    0:成功
 * @see       ComplexListNode
 * @note      无
 */
int CloneSibling(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	
	while(NULL != pNode)
	{
		pNode->m_pNext->m_pSibling = pNode->m_pSibling->m_pNext;
		pNode = pNode->m_pNext->m_pNext;
	}	
	return 0;
}

/** 
 * @brief     链表的拆分。
 * @param[in] pHead:需要复制的链表头
 * @retval    ComplexListNode*  返回复制链表的首指针。
 * @see       ComplexListNode
 * @note      将链表中的奇数偶数节点拆分
 */
ComplexListNode_ptr ReConnect(ComplexListNode *pHead)
{
	ComplexListNode_ptr pNode = pHead;
	ComplexListNode_ptr pCopyHead, pCopyNode;
	
	if(NULL != pNode)
	{
		pCopyHead = pCopyNode = pNode->m_pNext;
		pNode->m_pNext = pCopyNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	while(NULL != pNode)
	{
		pCopyNode->m_pNext = pNode->m_pNext;
		pCopyNode = pCopyNode->m_pNext;
		
		pNode->m_pNext = pCopyNode->m_pNext;
		pNode = pNode->m_pNext;
	}	
	return pCopyHead;
}

 int main()
 {
	ComplexListNode a;
	a.m_nValue = 1;
	ComplexListNode b;
	b.m_nValue = 2;
	ComplexListNode c;
	c.m_nValue = 3;	
	ComplexListNode d;
	d.m_nValue = 4;	
	ComplexListNode e;
	e.m_nValue = 5;	
	ComplexListNode f;
	f.m_nValue = 6;	
	
	a.m_pNext = &b;
	b.m_pNext = &c;
	c.m_pNext = &d;
	d.m_pNext = &e;
	e.m_pNext = &f;
	f.m_pNext = NULL;
	
	a.m_pSibling = &f;
	b.m_pSibling = &d;
	c.m_pSibling = &e;
	d.m_pSibling = &c;
	e.m_pSibling = &b;
	f.m_pSibling = &a;
	
	ComplexListNode_ptr pHead;
	Clone(&a);
	CloneSibling(&a);
	pHead = ReConnect(&a);
	ComplexListNode_ptr p = &a;
	
	while(NULL != p)
	{
		printf("%d->%d | ",p->m_nValue, p->m_pSibling->m_nValue);
		p = p->m_pNext;
	}	
	printf("\r\n");
	
	while(NULL != pHead)
	{
		printf("%d->%d | ",pHead->m_nValue, pHead->m_pSibling->m_nValue);
		pHead = pHead->m_pNext;
	}	
 }
