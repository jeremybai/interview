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
 * @brief     创建循环链表。
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
	Tail_ptr->next = Head_ptr;
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
 * @brief     约瑟夫环，报到m的节点被删除，直到最后节点。
 * @param[in] head_ptr   链表的首指针
 * @retval    最后剩下的节点的指针
 * @see       head_ptr
 * @note      模拟过程求解
 */
Node_ptr Josephus(Node_ptr head_ptr, int m)
{
	if(head_ptr == NULL)
		return NULL;
	Node_ptr p = head_ptr;
	int count = 1;
	while(p->next != p)
	{
		p = p->next;
		count++;
		if(count == m)
		{
			Node_ptr temp = p->next;
			p->data = p->next->data;
			p->next = p->next->next;
			free(temp);
			temp = NULL;
			count = 1;
		}		
	}
	return p;
}


/** 
 * @brief     约瑟夫环，报到m的节点被删除，直到最后节点。
 * @param[in] head_ptr   链表的首指针
 * @retval    最后剩下的数
 * @see       head_ptr
 * @note      递归法 http://www.tuicool.com/articles/ZrQ3U3
 *            Josephus(n,m) = (Joseph(n-1,m)+m) % n （n>1）
 */
int Josephus_Recursion(int n, int m)
{
	if(n == 1)
		return 0;
	return (Josephus_Recursion(n-1, m) + m) % n;
}
/** 
 * @brief     约瑟夫环，报到m的节点被删除，直到最后节点。
 * @param[in] head_ptr   链表的首指针
 * @retval    最后剩下的数
 * @see       head_ptr
 * @note      迭代
 */
int Josephus_Iteration(int n, int m)
{
	int Josephus_last = 0, Josephus_now = 0, i = 0;
	for(i = 2; i <= n; i++)
	{
		Josephus_now = (Josephus_last + m) % i;
		Josephus_last = Josephus_now;
	}
	return Josephus_now;
}
int main()
{
	// Node * head = List_User_Init();
	// int m;
	// printf("请输入m（报到m的节点被删除）：");
	// scanf("%d",&m);
	// head = Josephus(head,m);
	// printf("剩下的节点为：%d\n", head->data);
	int n =  9,m = 3;
	printf("n = %d, m = %d,剩下的节点为：%d\n", n, m, Josephus_Recursion(n, m));
	printf("n = %d, m = %d,剩下的节点为：%d\n", n, m, Josephus_Iteration(n, m));
}
