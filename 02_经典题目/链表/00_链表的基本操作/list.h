/****************************************************************************
 * @file     list.h
 * @brief    链表基本操作头文件 
 * @version  V1.00
 * @date     2013.12.30
 * @note     无
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

/**		判断节点是否需要删除的函数指针 \n  
 *     
 *		自定义判断节点是否需要删除的函数指针。    
 */ 
typedef bool (* remove_fn)(node const * v);


Node * List_Init();
Node* List_User_Init();
void List_Traversal(Node * head_ptr);
void List_Delete(Node * head_ptr);
void List_Insert(Node * head_ptr,ElementType data);
void List_Insertn(Node * head_ptr,int n,ElementType data);
void List_DeleteNode(Node * head_ptr);
void List_DeleteNthNode(Node * head_ptr,int n);
Node * remove_if_basic(Node * head, remove_fn rm);
bool fun1(Node const * node_ptr);
