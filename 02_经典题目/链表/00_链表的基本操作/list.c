/****************************************************************************
 * @file     list.c
 * @brief    链表基本操作源文件
 * @version  V1.00
 * @date     2013.12.30
 * @note     无
****************************************************************************/
#include "list.h" 


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


Node* List_User_Init()
{
	Node * Head_ptr,*Tail_ptr,*node_ptr;
	ElementType data; 
	int num,i;
	Tail_ptr = 	Head_ptr = NULL;;
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
		scanf("%d",&data);
		node_ptr->data = data;
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

int List_Traversal(Node * head_ptr)
{
	Node * node_ptr = head_ptr;
	
	while(node_ptr != NULL)
	{
		printf("%d  ",node_ptr->data);
		node_ptr = node_ptr->next;
	}
}
void List_Delete(Node * head_ptr)
{
	Node * node_ptr = head_ptr,*next_ptr;
	
	while(node_ptr != NULL)
	{
		next_ptr = node_ptr->next;
		free(node_ptr);
		node_ptr = next_ptr;
	}
}
int main()
{
	Node * head_ptr;	
	head_ptr = List_User_Init();
	List_Traversal(head_ptr);
	List_Delete(head_ptr);
}


