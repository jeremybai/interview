/****************************************************************************
 * @file     06_两个链表的第一个公共节点.c
 * @brief    输入2个链表， 输出两个链表的第一个公共节点
 * @version  V1.00
 * @date     2014.9.2
 * @note     时间复杂度:最好O()最坏:O() 空间复杂度O()
 * @note     
 ****************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include <math.h>

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
 * @brief     根据输入两个链表输出两个链表的第一个公共节点的值。
 * @param[in] head1_ptr   链表1的首指针
 * @param[in] head2_ptr   链表2的首指针
 * @retval    公共节点
 * @see       Node
 * @note      无
 */
Node_ptr CommonNode(Node_ptr head1_ptr, Node_ptr head2_ptr)
{
	if(NULL == head1_ptr || NULL == head2_ptr)
	{
		printf("输入参数有误\r\n");
		return NULL;
	}
	Node_ptr node_ptr = head1_ptr, Node1_ptr, Node2_ptr;
	int i,head1_len = 0, head2_len = 0, difference;
	//计算两个链表的长度
	while(node_ptr != NULL)
	{
		head1_len++;
		node_ptr = node_ptr->next;
	}
	node_ptr = head2_ptr;
	while(node_ptr != NULL)
	{
		head2_len++;
		node_ptr = node_ptr->next;
	}
	//计算长度之差，长的链表先走difference步
	difference = head1_len - head2_len;
	Node1_ptr = head1_ptr;
	Node2_ptr = head2_ptr;
	if(difference > 0)
	{
		//head1比head2长，需要先走difference步
		for(i = 0; i < abs(difference); i++){ Node1_ptr = Node1_ptr->next; }
	}
	else
	{
		for(i = 0; i < abs(difference); i++){ Node2_ptr = Node2_ptr->next; }
	}
	while(NULL != Node1_ptr && NULL != Node2_ptr && Node1_ptr->data != Node2_ptr->data)
	{
		Node1_ptr = Node1_ptr->next;
		Node2_ptr = Node2_ptr->next;
	}
	if(NULL == Node1_ptr || NULL == Node2_ptr)
	{
		printf("未找到公共节点\r\n");
		return NULL;
	}
	else
		return Node1_ptr;
}


int main()
{	
	Node a,b,c,d,e,x,y,z;
	a.data = 0;b.data = 1;c.data = 2;d.data = 3;e.data = 4;
	a.next = &b;b.next = &c;c.next = &d;d.next = &e;e.next = NULL;
	
	x.data = 0;y.data = 5;z.data = 0;
	x.next = &y;y.next = &z;
	
	z.next = &c;  	//存在相同节点
	//z.next = NULL;//不存在相同节点
	List_Traversal(&a);
	List_Traversal(&x);
	printf("\r\n公共节点的data = %d\r\n",CommonNode(&a, &x)->data);
	return 0;
}