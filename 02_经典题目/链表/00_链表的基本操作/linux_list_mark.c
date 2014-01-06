/****************************************************************************
 * @file     DbLinkList.c
 * @brief    双向链表源文件。
 * @version  V0.00
 * @date     2014.1.5
 * @note     
****************************************************************************/
typedef int ElementType;
typedef int size_t;
struct list_head {
	struct list_head *next, *prev;
};

struct list_node {
	struct list_head list;
	ElementType	data;
};

//定义变量并且初始化节点的next和prev指针指向自己
#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

	
//2.6的linux中，INIT_LIST_HEAD宏已经修改为内联函数
// #define INIT_LIST_HEAD(ptr) do { \
	(ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)
//用于给已经存在的变量赋值
static inline void INIT_LIST_HEAD(struct list_head *list)
{
	list->next = list;
	list->prev = list;
}

/*
 * These are non-NULL pointers that will result in page faults
 * under normal circumstances, used to verify that nobody uses
 * non-initialized list entries.
 */
#define LIST_POISON1  ((void *) 0x00100100)
#define LIST_POISON2  ((void *) 0x00200200)


/*
 * Insert a new entry between two known consecutive entries.在两个连续的节点中间插入节点
 *
 * This is only for internal list manipulation where we know 
 * the prev/next entries already!只有在前后节点已知的情况下操作内部节点使用
 */
static inline void __list_add(struct list_head *new_ptr, struct list_head *prev, struct list_head *next)
{
	next->prev = new_ptr;
	new_ptr->next = next;
	new_ptr->prev = prev;
	prev->next = new_ptr;
}

/**
 * list_add - add a new entry 在表头后面增加一个节点
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.在表头后面添加新节点。
 * This is good for implementing stacks.可以用来实现栈。
 */
static inline void list_add(struct list_head *new_ptr, struct list_head *head)
{
	__list_add(new_ptr, head, head->next);
}

/**
 * list_add_tail - add a new entry在表头前面增加一个节点
 * @new: new entry to be added
 * @head: list head to add it before
 *
 * Insert a new entry before the specified head.在链表结尾添加新节点。
 * This is useful for implementing queues.可以用来实现队列。
 */
static inline void list_add_tail(struct list_head *new_ptr, struct list_head *head)
{
	__list_add(new_ptr, head->prev, head);
}

/*
 * Delete a list entry by making the prev/next entries删除两个节点之间的节点。
 * point to each other.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static inline void __list_del(struct list_head * prev, struct list_head * next)
{
	next->prev = prev;
	prev->next = next;
}


/**
 * list_del - deletes entry from list.
 * @entry: the element to delete from the list.
 * Note: list_empty on entry does not return true after this, the entry is
 * in an undefined state.
 */
static inline void list_del(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
	entry->next = (struct list_head *)LIST_POISON1;
	entry->prev = (struct list_head *)LIST_POISON2;
}


/**
 * list_del_init - deletes entry from list and reinitialize it.
 * @entry: the element to delete from the list.
 */
static inline void list_del_init(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
	INIT_LIST_HEAD(entry);
}

/**
 * list_move - delete from one list and add as another's head
 * 从链表中删除节点，把它作为另外一个链表的头结点
 * @list: the entry to move
 * @head: the head that will precede our entry
 */
static inline void list_move(struct list_head *list, struct list_head *head)
{
        __list_del(list->prev, list->next);
        list_add(list, head);
}

/**
 * list_move_tail - delete from one list and add as another's tail
 * 从链表中删除节点，把它作为另外一个链表的尾结点
 * @list: the entry to move
 * @head: the head that will follow our entry
 */
static inline void list_move_tail(struct list_head *list,
				  struct list_head *head)
{
        __list_del(list->prev, list->next);
        list_add_tail(list, head);
}

/**
 * list_empty - tests whether a list is empty
 * @head: the list to test.
 */
static inline int list_empty(const struct list_head *head)
{
	return head->next == head;
}

/**
 * __list_splice - 将两个链表链接
 * @list: 被链接的链表.
 * @head: 被链接的链表，作为表头
 * list的第一个节点作为首节点，head的尾节点作为尾节点，合并后head作为表头
 * http://www.ibm.com/developerworks/cn/linux/kernel/l-chain/
 */
static inline void __list_splice(struct list_head *list,
				 struct list_head *head)
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
 * list_splice - join two lists
 * @list: the new list to add.
 * @head: the place to add it in the first list.
 */
static inline void list_splice(struct list_head *list, struct list_head *head)
{
	if (!list_empty(list))
		__list_splice(list, head);
}

/**
 * list_splice_init - join two lists and reinitialise the emptied list.
 * @list: the new list to add.
 * @head: the place to add it in the first list.
 *
 * The list at @list is reinitialised
 */
static inline void list_splice_init(struct list_head *list,
				    struct list_head *head)
{
	if (!list_empty(list)) {
		__list_splice(list, head);
		INIT_LIST_HEAD(list);
	}
}

/**
 * Get offset of a member，获得TYPE类型结构体中MEMBER成员的偏移
 */
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

/**
 * Casts a member of a structure out to the containing structure
 * @param ptr        the pointer to the member.
 * @param type       the type of the container struct this is embedded in.
 * @param member     the name of the member within the struct.
 * 通过list_head成员指针ptr得到结构体的地址
 */
#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})
/*@}*/



/**
 * list_entry - get the struct for this entry
 * @ptr:	the &struct list_head pointer.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_struct within the struct.
 */
#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)
	
/**
 * list_for_each	-	iterate over a list
 * @pos:	the &struct list_head to use as a loop counter.
 * @head:	the head for your list.
 */

#define list_for_each(pos, head) \
  for (pos = (head)->next;prefetch(pos->next), pos != (head);	\
       pos = pos->next)
	   
/**
 * __list_for_each	-	iterate over a list
 * @pos:	the &struct list_head to use as a loop counter.
 * @head:	the head for your list.
 *
 * This variant differs from list_for_each() in that it's the
 * simplest possible list iteration code, no prefetching is done.
 * Use this for code that knows the list to be very short (empty
 * or 1 entry) most of the time.
 */
#define __list_for_each(pos, head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)



int main()
{

}









