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

int List_Init(Node *N);
Node* List_User_Init();
int List_Traversal(Node * head_ptr);
void List_Delete(Node *N);
void List_Insert(Node * head_ptr,ElementType data);
void List_Insertn(Node * head_ptr,int n,ElementType data);





