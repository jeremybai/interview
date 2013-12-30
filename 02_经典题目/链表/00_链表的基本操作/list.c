/****************************************************************************
 * @file     list.c
 * @brief    链表基本操作源文件
 * @version  V1.00
 * @date     2013.12.30
 * @note     无
****************************************************************************/
#include "list.h" 

//创建空链表
int List_Init(Node *N)
{
	if(N == NULL)
		return 1;
	if(NULL  == (N = (Node *)malloc(sizeof(Node))))
	{
		perror("error...");
		return 1;
	}
	N->next = NULL;
	
	return 0;
}

//输入链表个数和元素创建链表
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
//链表遍历
int List_Traversal(Node * head_ptr)
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
//链表删除
void List_Delete(Node * head_ptr)
{
	if(head_ptr == NULL)
		return ;
	Node * node_ptr = head_ptr,*next_ptr;
	while(node_ptr != NULL)
	{
		next_ptr = node_ptr->next;
		free(node_ptr);
		node_ptr = next_ptr;
	}
}
//链表插入
void List_Insert(Node * head_ptr,ElementType data)
{
	if(head_ptr == NULL)
		return ;
	Node * node_ptr = head_ptr,*new_ptr;	
	while(node_ptr->next != NULL)
	{
		node_ptr = node_ptr->next;
	}
	if(NULL  == (new_ptr = (Node *)malloc(sizeof(Node))))
	{
		perror("error...");
		exit(0);
	}	
	new_ptr->data = data;
	new_ptr->next = NULL;
	node_ptr->next = new_ptr;
}
//链表指定位置插入,在第n个节点之后插入
void List_Insertn(Node * head_ptr,int n,ElementType data)
{
	if(head_ptr == NULL)
		return ;
	Node * node_ptr = head_ptr,*new_ptr;	
	while(n--)
	{
		node_ptr = node_ptr->next;
	}
	if(NULL  == (new_ptr = (Node *)malloc(sizeof(Node))))
	{
		perror("error...");
		exit(0);
	}	
	new_ptr->data = data;
	new_ptr->next = node_ptr->next;;
	node_ptr->next = new_ptr;
}



void List_DeleteNode(Node * head_ptr)
{
	if(head_ptr == NULL)
		return ;
	else if(head_ptr->next == NULL)
			head_ptr = NULL;
	Node * node_ptr = head_ptr;	
	while(node_ptr->next->next != NULL)
	{
		node_ptr = node_ptr->next;
	}
	free(node_ptr->next);
	node_ptr->next = NULL;
}


void List_DeleteNthNode(Node * head_ptr,int n)
{
	if(head_ptr == NULL || n < 0)
		return ;
	Node * node_ptr = head_ptr,*del_ptr;	
	while(n-- > 1)
	{
		node_ptr = node_ptr->next;
	}
	del_ptr = node_ptr->next;
	node_ptr->next = del_ptr->next;
	free(del_ptr);
}
int main()
{
	Node * head_ptr;	
	head_ptr = List_User_Init();
	List_Traversal(head_ptr);
	List_Insert(head_ptr,7);
	List_Insertn(head_ptr,2,7);
	List_Traversal(head_ptr);
	List_DeleteNode(head_ptr);
	List_DeleteNthNode(head_ptr,3);
	List_Traversal(head_ptr);
	List_Delete(head_ptr);
}


