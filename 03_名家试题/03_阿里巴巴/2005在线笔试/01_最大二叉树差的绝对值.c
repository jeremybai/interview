/****************************************************************************
 * @file     01_最大二叉树差的绝对.c
 * @brief    写一个函数，输入一个二叉树，树中每个节点存放了一个整数值，函数
			 返回这棵二叉树中相差最大的两个节点间的差值绝对值。 
 * @version  V1.00
 * @date     2014.8.29
 * @note     
****************************************************************************/
#include "stdio.h"
#include "malloc.h"

/**		节点数据类型  
 *     
 *		定义节点数据类型。    
 */
typedef char ElementType;


/**		树节点结构体定义  
 *     
 *		定义树节点所包含的成员变量。    
 */ 
typedef struct treenode
{
	int data;					/**< 节点数据 */  
	struct treenode* leftchild;		/**< 左孩子节点指针 */  
	struct treenode* rightchild;		/**< 右孩子节点指针 */  
} TreeNode, *TreeNode_ptr;

/** 
 * @brief   使用先序遍历创建二叉树。
 * @param   None
 * @retval  TreeNode* 创建的树节点。
 * @see     TreeNode;
 * @note    scanf函数的问题：scanf会读入回车符，当需要一个一个的输入字符时，
			可以在%c前面加个空格
 */
TreeNode* Create_Binarytree()
{
    ElementType ch;
    TreeNode* T;
    scanf("%c",&ch);    //这样调用scanf时，树的结点一次全部输入，如果要一次一个的输入，在%c前加个空格
    if(ch != '#')
    {
		if(NULL == (T = (TreeNode*)malloc(sizeof(TreeNode))))
		{
			perror("error...");
			exit(1);
		}
        T->data = ch;
        T->leftchild = Create_Binarytree();
        T->rightchild = Create_Binarytree();
    }
    else
    {
        T = NULL;
    }
    return T;
}

/** 
 * @brief   返回这棵二叉树中相差最大的两个节点间的差值绝对值。
 * @param   head  当前节点的指针
 * @param   max   当前最大节点值
 * @param   min   当前最小节点值
 * @retval  None
 * @see     TreeNode;
 * @note    递归调用。
 */
void  MaxLength(TreeNode_ptr head, int *max, int *min)
{
	if(NULL == head)
	{
		//到达叶子节点，直接返回
		return;
	}
	if(head->data > *max)
	{
		*max = head->data;		
	}
	else if(head->data < *min)
	{
		*min = head->data;
	}
	MaxLength(head->leftchild, max, min);
	MaxLength(head->rightchild, max, min);
}

int main()
{
	TreeNode_ptr head_ptr =  Create_Binarytree();
	ElementType max = head_ptr->data, min = head_ptr->data;
	MaxLength(head_ptr, &max, &min);
	printf("%d",max-min);
}