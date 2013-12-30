/****************************************************************************
 * @file     list.c
 * @brief    链表基本操作源文件
 * @version  V1.00
 * @date     2013.12.30
 * @note     无
****************************************************************************/
#include "list.h" 

/** 
 * @brief     创建空链表。
 * @param[in] 无
 * @retval    Node *  返回创建链表的首指针。
 * @see       Node
 * @note      无
 */
Node * List_Init()
{
	Node *head_ptr;
	if(head_ptr == NULL)
		exit(0);
	if(NULL  == (head_ptr = (Node *)malloc(sizeof(Node))))
	{
		perror("error...");
		exit(0);
	}
	head_ptr->next = NULL;
	return head_ptr;
}

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
 * @brief     删除整个链表。
 * @param[in] head_ptr   链表的首指针
 * @retval    None
 * @see       Node
 * @note      无
 */
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

/** 
 * @brief     在链表最后插入数据。
 * @param[in] head_ptr   链表的首指针
 * @param[in] data       需要插入的数据
 * @retval    None
 * @see       Node
 * @note      无
 */
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

/** 
 * @brief     链表指定位置插入,在第n个节点之后插入。
 * @param[in] head_ptr   链表的首指针
 * @param[in] n          需要插入数据的位置
 * @param[in] data       需要插入的数据
 * @retval    None
 * @see       Node
 * @note      无
 */
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



/** 
 * @brief     删除链表最后一个节点。
 * @param[in] head_ptr   链表的首指针
 * @retval    None
 * @see       Node
 * @note      无
 */
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

/** 
 * @brief     删除指定位置的节点。
 * @param[in] head_ptr   链表的首指针
 * @param[in] n          需要删除基点的位置
 * @retval    None
 * @see       Node
 * @note      无
 */
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

/** 
 * @brief     删除单链表中所有满足条件的节点的基本方法。
 * @param[in] head  指向头节点的指针
 * @param[in] rm    自定义节点是否删除的函数指针
 * @retval    None
 * @see       Node
 * @note      无
 */
Node * remove_if_basic(Node * head, remove_fn rm)
{
	for(Node *prev = NULL, *curr = head ;curr != NULL; )
	{
		Node *next = curr->next;
		if (rm(curr))
		{
			if(prev)
				prev->next = next;    //删除的不是头结点 
			else	
				head =  next;        //删除的是头结点
			free(curr);
		}
		else
			prev = curr;
		curr = next;
	}
	return head;
}

/** 
 * @brief     Linus所说的删除单链表中所有满足条件的节点的方法。
 * @param[in] head  指向头节点的二级指针
 * @param[in] rm    自定义节点是否删除的函数指针
 * @retval    None
 * @see       node
 * @note      相比于基本方法不需要维护指向前一个节点的prev指针了，
			  也不需要再去判断是否为链表头了
 */
void remove_if(node ** head, remove_fn rm)
{
    for (node** curr = head; *curr; )
    {
        node * entry = *curr;
        if (rm(entry))
        {
            *curr = entry->next;
            free(entry);
        }
        else
            curr = &entry->next;
    }
}
/**		简单判断函数 \n  
 *     
 *		判断节点的数据是否和4相等，相等返回1，否则返回0。    
 */ 
bool fun1(Node const * node_ptr)
{
	if(node_ptr->data == 4)
		return true;
	else
		return false;
}
/**		简单判断函数 \n  
 *     
 *		判断节点的数据是否和3相等，相等返回1，否则返回0。    
 */ 
bool fun2(Node const * node_ptr)
{
	if(node_ptr->data == 3)
		return true;
	else
		return false;
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
	
	head_ptr = remove_if_basic(head_ptr,fun1);
	remove_if(&head_ptr,fun2);
	
	List_Traversal(head_ptr);
	List_Delete(head_ptr);
}


