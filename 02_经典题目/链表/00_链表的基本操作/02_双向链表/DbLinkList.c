/****************************************************************************
 * @file     DbLinkList.c
 * @brief    双向链表源文件。
 * @version  V1.00
 * @date     2014.1.6
 * @note     
****************************************************************************/
#include <stdio.h>
#include <malloc.h>
typedef int ElementType;

typedef struct list_head {
	struct list_head *next, *prev;
	ElementType data;
}List_Head,*List_Head_ptr;

//定义变量并且初始化节点的next和prev指针指向自己
#define LIST_HEAD_INIT(name) { &(name), &(name)}
#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)
	
//用于将已经存在的变量的成员指针指向自己
void List_Head_Init(List_Head_ptr list)
{
	list->next = list;
	list->prev = list;
}
/** 
 * @brief     在两个连续的节点中间插入节点。
 * @param[in] list  链表的表头
 * @retval    None
 * @see       List_Head_ptr
 * @note      只有在前后节点已知的情况下操作内部节点使用
 */
void List_Head_Add(List_Head_ptr list)
{
	list->next = list;
	list->prev = list;
}


/** 
 * @brief     在表头后面增加一个节点，内部函数。
 * @param[in] new_ptr  需要增加的节点指针，
 * @param[in] prev     插入位置的前一个节点指针
 * @param[in] next     插入位置的后一个节点指针
 * @retval    None
 * @see       List_Head_ptr
 * @note      
 */
static inline void __list_add(List_Head_ptr new_ptr, List_Head_ptr prev, List_Head_ptr next)
{
	next->prev = new_ptr;
	new_ptr->next = next;
	new_ptr->prev = prev;
	prev->next = new_ptr;
}


/** 
 * @brief     在表头后面增加一个节点。
 * @param[in] new_ptr  需要增加的节点指针，
 * @param[in] head     链表头指针
 * @retval    None
 * @see       List_Head_ptr
 * @note      在表头后面添加新节点，可以用来实现栈。
 */
void list_add(List_Head_ptr new_ptr, List_Head_ptr head)
{
	__list_add(new_ptr, head, head->next);
}


/** 
 * @brief     在表头前面增加一个节点。
 * @param[in] new_ptr  需要增加的节点指针，
 * @param[in] head     链表头指针
 * @retval    None
 * @see       List_Head_ptr
 * @note      在链表结尾添加新节点，可以用来实现队列。
 */
void list_add_tail(List_Head_ptr new_ptr, List_Head_ptr head)
{
	__list_add(new_ptr, head->prev, head);
}

/** 
 * @brief     删除两个节点之间的节点，内部函数
 * @param[in] prev     删除位置的前一个节点指针
 * @param[in] next     删除位置的后一个节点指针
 * @retval    None
 * @see       List_Head_ptr
 * @note      在链表指定位置删除节点。
 */
static inline void __list_del(List_Head_ptr prev, List_Head_ptr next)
{
	next->prev = prev;
	prev->next = next;
}

/** 
 * @brief     删除节点。
 * @param[in] entry   需要删除的节点指针
 * @retval    None
 * @see       List_Head_ptr
 * @note      在链表指定位置删除节点。
 */
static void list_del(List_Head_ptr entry)
{
	__list_del(entry->prev, entry->next);
	free(entry);
	entry = NULL;
}

/**   判断链表是否为空 \n
 *  
 *    若该节点的next指针指向自己即为空链表
 */
static inline int list_empty(const List_Head_ptr head)
{
	return head->next == head;
}

/** 
 * @brief     将两个链表链接。
 * @param[in] list   新加入的链表
 * @param[in] head   被链接的链表，作为表头
 * @retval    None
 * @see       List_Head_ptr
 * @note      list的第一个节点作为首节点，head的尾节点作为尾节点，合并后head作为表头。
 *            参考http://www.ibm.com/developerworks/cn/linux/kernel/l-chain/
 */
static inline void __list_splice(List_Head_ptr list, List_Head_ptr head)
{
	struct list_head *first = list->next;
	struct list_head *last = list->prev;
	struct list_head *at = head->next;

	first->prev = head;
	head->next = first;

	last->next = at;
	at->prev = last;
}


/** 
 * @brief     将两个链表链接。
 * @param[in] list   新加入的链表
 * @param[in] head   被链接的链表，作为表头
 * @retval    None
 * @see       List_Head_ptr
 * @note      list的第一个节点作为首节点，head的尾节点作为尾节点，合并后head作为表头。
 *            参考http://www.ibm.com/developerworks/cn/linux/kernel/l-chain/
 */
void list_splice(List_Head_ptr list, List_Head_ptr head)
{
	if (!list_empty(list))
		__list_splice(list, head);
}

#define __list_for_each(pos, head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)

/** 
 * @brief     遍历整个链表
 * @param[in] head     需要遍历的链表表头
 * @retval    None
 * @see       List_Head_ptr
 * @note      
 */
static void list_traversal(List_Head_ptr head)
{
	List_Head_ptr pos;
	__list_for_each(pos,head)
	{
		printf("%d   ",pos->data);
	}
}
	
int main()
{
	int num;
	LIST_HEAD(HEAD1);	
	LIST_HEAD(HEAD2);
	List_Head_ptr head1 = &HEAD1,head2 = &HEAD2, node_ptr;
	printf("请输入链表1元素数目：\n");
	scanf("%d",&num);
	printf("请输入链表元素：\n");	
	for(int i = 0; i < num; i++)
	{
		if(NULL  == (node_ptr = (List_Head_ptr)malloc(sizeof(struct list_head))))
		{
			perror("error...");
			exit(0);
		}
		List_Head_Init(node_ptr);   //初始化成员指针
		scanf("%d",&node_ptr->data);//初始化数据域
		list_add_tail(node_ptr,head1);
	}

	printf("请输入链表2元素数目：\n");
	scanf("%d",&num);
	printf("请输入链表元素：\n");	
	for(int i = 0; i < num; i++)
	{
		if(NULL  == (node_ptr = (List_Head_ptr)malloc(sizeof(struct list_head))))
		{
			perror("error...");
			exit(0);
		}
		List_Head_Init(node_ptr);   //初始化成员指针
		scanf("%d",&node_ptr->data);//初始化数据域
		list_add_tail(node_ptr,head2);
	}
	
	printf("将链表1链接到链表2：\n");
	list_splice(head1,head2);
	list_traversal(head2);
}
