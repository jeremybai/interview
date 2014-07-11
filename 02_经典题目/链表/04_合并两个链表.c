/****************************************************************************
 * @file     04_合并两个链表.c
 * @brief    输入2个有序链表，合并之后输出的链表还是有序的
 * @version  V1.00
 * @date     2014.7.10
 * @note     时间复杂度:最好O(m、n中的最小值)最坏:O(m+n) 空间复杂度O(1)
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
 * @brief     合并两个链表
 * @param[in] head1_ptr：第一个链表的首指针
 * @param[in] head2_ptr：第二个链表的首指针
 * @retval    反转后链表的首指针
 * @see       Node
 * @note      当输入两个参数为同一个指针的时候，第一个节点指向自己构成循环链表
 */
Node_ptr ListMerge_Recursion(Node_ptr head1_ptr, Node_ptr head2_ptr)
{
	if(head1_ptr == NULL)
		return head2_ptr;
	else if(head2_ptr == NULL)
		return head1_ptr;
	Node_ptr head_ptr;
	if(head1_ptr->data <= head2_ptr->data)
	{
		head_ptr = head1_ptr;
		head_ptr->next = ListMerge_Recursion(head1_ptr->next,head2_ptr);
	}
	else
	{
		head_ptr = head2_ptr;
		head_ptr->next = ListMerge_Recursion(head1_ptr,head2_ptr->next);
	}
	return head_ptr;
}



/** 
 * @brief     合并两个有序链表
 * @param[in] head1_ptr：第一个链表的首指针
 * @param[in] head2_ptr：第二个链表的首指针
 * @retval    反转后链表的首指针
 * @see       Node
 * @note      当输入两个参数为同一个指针的时候，第一个节点指向自己构成循环链表
 */
Node_ptr ListMerge(Node_ptr head1_ptr, Node_ptr head2_ptr)
{
	Node_ptr head1 = head1_ptr;
	Node_ptr head2 = head2_ptr;
	Node_ptr ptr,head;

	if(head1->data < head2->data)
	{
		ptr = head1;
		head1 = head1->next;
	}
	else
	{
		ptr = head2;
		head2 = head2->next;
	}
	head = ptr;
	
	while(NULL != head1 && NULL != head2)
	{
		if(head1->data < head2->data)
		{
			ptr->next = head1;
			ptr = ptr->next;
			head1 = head1->next;
		}
		else
		{
			ptr->next = head2;
			ptr = ptr->next;
			head2 = head2->next;
		}
	}
	if(!head1)
	{
		ptr->next = head2;
	}
	else if(!head2)
	{
		ptr->next = head1;
	}
	return head;
}
int main()
{	
	Node_ptr ptr1 = List_User_Init();
	Node_ptr ptr2 = List_User_Init();

	Node_ptr ptr = ListMerge(ptr1,ptr2);
	List_Traversal(ptr);
	return 0;
}