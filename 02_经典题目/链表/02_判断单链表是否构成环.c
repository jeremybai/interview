/****************************************************************************
 * @file     02_判断单链表是否构成环.c
 * @brief    判断单链表是否有环 
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
 * @brief     判断链表是否有环
 * @param[in] head_ptr   链表的首指针
 * @retval    1：链表形成环 0：未形成环
 * @see       Node
 * @note      无
 */
int IsLoop(Node_ptr ptr)
{
	Node_ptr p1,p2;
	p1 = p2 = ptr;
	while(NULL != p1 && NULL != p1->next)
	{
		p1 = p1->next->next;
		p2 = p2->next;
		if(p1 == p2)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{	
	Node_ptr ptr = List_User_Init();
	List_Traversal(ptr);
	Node_ptr p = ptr,tail;;
	int i = 2;
	while(p->next)
	{
		p = p->next;
	}
	tail = p;
	p = ptr;
	while(i--)
	{
		p = p->next;
	}
	tail->next = p;
	if(1 == IsLoop(ptr))
	{	
		printf("链表形成环状结构\r\n");
	}
	else
	{
		printf("链表未形成环状结构\r\n");
	}

}