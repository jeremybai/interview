 /**************************************************************************
 * @file     01_栈的基本操作.c
 * @brief    实现栈的基本操作 
 * @version  V1.00
 * @date     2014.7.11
 * @note     push,pop
****************************************************************************/
#include <stdio.h>
#include <malloc.h>

/**		节点数据类型 \n  
 *     
 *		定义节点数据类型。    
 */
typedef int ElementType;
typedef int* ElementType_ptr;
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
 * @brief     在链表最后插入数据。
 * @param[in] head_ptr   链表的首指针
 * @param[in] data       需要插入的数据
 * @retval    指向新插入的节点
 * @see       Node,Node_ptr
 * @note      无
 */
Node_ptr List_Insert(Node * head_ptr,ElementType_ptr data)
{
	Node * node_ptr = head_ptr,*new_ptr;
	if(head_ptr != NULL)
	{
		while(node_ptr->next != NULL)
		{
			node_ptr = node_ptr->next;
		}
	}
	if(NULL  == (new_ptr = (Node *)malloc(sizeof(Node))))
	{
		perror("error...");
		exit(0);
	}	
	new_ptr->data = *data;
	new_ptr->next = NULL;
	node_ptr->next = new_ptr;
	return new_ptr;
}


/** 
 * @brief     删除链表最后一个节点。
 * @param[in] head_ptr   链表的首指针
 * @retval    指向删除之后最后一个节点
 * @see       Node
 * @note      无
 */
Node_ptr List_DeleteNode(Node * head_ptr,ElementType_ptr data)
{
	if(head_ptr == NULL)
		return NULL;
	else if(head_ptr->next == NULL)
			head_ptr = NULL;
	Node * node_ptr = head_ptr;	
	while(node_ptr->next->next != NULL)
	{
		node_ptr = node_ptr->next;
	}
	*data = node_ptr->next->data;
	free(node_ptr->next);
	node_ptr->next = NULL;
	return node_ptr;
}

/** 
 * @brief     栈初始化。
 * @param[in] ptr   栈底指针
 * @param[in] data       需要插入的数据
 * @retval    返回栈顶指针
 * @see       Node,Node_ptr
 * @note      无
 */
Node_ptr Stack_Init(ElementType_ptr data)
{
	Node_ptr ptr; 
	if(NULL != (ptr = (Node *)malloc(sizeof(Node))))
	{
		ptr->next = NULL;
		ptr->data = *data;	
	}
	return ptr;
}

/** 
 * @brief     栈初始化。
 * @param[in] ptr   栈底指针的指针
 * @param[in] data       需要插入的数据
 * @retval    返回栈顶指针
 * @see       Node,Node_ptr
 * @note      使用指针的指针作为参数使得在函数中可以修改传入的栈底指针
 */
Node_ptr Stack_Init1(Node_ptr *ptr,ElementType_ptr data)
{
	if(NULL != (*ptr = (Node *)malloc(sizeof(Node))))
	{
		(*ptr)->next = NULL;
		(*ptr)->data = *data;	
	}
	return *ptr;
}

/** 
 * @brief     在栈顶压入数据。
 * @param[in] ptr   栈底指针
 * @param[in] data       需要插入的数据
 * @retval    返回栈顶指针
 * @see       Node,Node_ptr
 * @note      无
 */
Node_ptr Push(Node_ptr ptr,ElementType_ptr data)
{
	return List_Insert(ptr,data);
}
/** 
 * @brief     在栈顶弹出数据。
 * @param[in] ptr   栈底指针
 * @param[in] data       需要弹出的数据
 * @retval    返回栈顶指针，data返回弹出的数据
 * @see       Node,Node_ptr
 * @note      无
 */
Node_ptr Pop(Node_ptr ptr,ElementType_ptr data)
{
	return List_DeleteNode(ptr,data);
}


int main(Node_ptr)
{
	Node_ptr ptr_bottom,ptr_top;
	ElementType data = 1;
	//ptr_bottom = Stack_Init(&data);
	//ptr_top = ptr_bottom;
	ptr_top = Stack_Init1(&ptr_bottom,&data);
	
	for(int i = 0; i < 10;i ++)
	{
		ptr_top = Push(ptr_bottom, &i);
	}
	for(int i = 0; i < 10;i ++)
	{
		ptr_top = Pop(ptr_bottom, &data);
		printf("%d",data);
	}
}