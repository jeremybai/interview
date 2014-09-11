/****************************************************************************
 * @file     03_反转链表.c
 * @brief    将一个链表进行反转 
 * @version  V1.00
 * @date     2014.7.9
 * @note     一个指针走快一点另一个指针走慢一点
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
typedef struct node 
{
	struct node * next;
	ElementType data;
} Node,*Node_ptr;

/** 
 * @brief     输入链表个数和元素创建链表。
 * @param[in] 无
 * @retval    Node *  返回创建链表的首指针。
 * @see       Node
 * @note      无
 */
Node* List_User_Init()
{
	Node * Head_ptr,*Tail_ptr,*node_ptr;
	ElementType data; 
	int num,i;
	Tail_ptr = 	Head_ptr = NULL;
	printf("请输入链表元素数目：\n");
	scanf("%d",&num);
	printf("请输入链表元素：\n");	
	for(i = 0; i < num; i++)
	{
		if(NULL  == (node_ptr = (Node *)malloc(sizeof(Node))))
		{
			perror("error...");
			exit(0);
		}
		scanf("%d",&node_ptr->data);
		node_ptr->next = NULL;
		if(i == 0)
		{
			Head_ptr = Tail_ptr	= node_ptr;
		}
		else
		{		
			Tail_ptr->next = node_ptr;
			Tail_ptr = node_ptr;
		}

	}
	return Head_ptr;
}
/** 
 * @brief     链表遍历。
 * @param[in] head_ptr   链表的首指针
 * @retval    None
 * @see       Node
 * @note      无
 */
void List_Traversal(Node * head_ptr)
{
	if(head_ptr == NULL)
		exit(0);
	Node * node_ptr = head_ptr;
	while(node_ptr != NULL)
	{
		printf("%d  ",node_ptr->data);
		node_ptr = node_ptr->next;
	}
	printf("\n");
}

/** 
 * @brief     反转链表
 * @param[in] head_ptr   链表的首指针
 * @retval    反转后链表的首指针
 * @see       Node
 * @note      无
 */
Node_ptr ListReverse(Node_ptr phead)
{
	if(NULL == phead)
	{
		printf("ListReverse param error!\r\n");
		return NULL;
	}
	Node_ptr pnext,ptr,ppre;
	ppre = phead->next;
	phead->next = NULL;
	
	pnext = phead;
	ptr = ppre;
	while(NULL != ptr)
	{
		ppre = ptr->next;
		ptr->next = pnext;
		
		pnext = ptr;
		ptr = ppre;
	}
	return pnext;
}

int main()
{	
	Node_ptr ptr = List_User_Init();
	Node_ptr ptrrev;
	List_Traversal(ptr);
	if(NULL == (ptrrev = ListReverse1(ptr)))
	{
		printf("param error!\r\n");
		return 1;
	}	
	List_Traversal(ptrrev);
	return 0;
}