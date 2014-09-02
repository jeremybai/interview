/****************************************************************************
* @file     03_判断是不是平衡二叉树.c
* @brief    判断是不是平衡二叉树
* @version  V1.00
* @date     2014.9.2
* @note     输入一个二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中
			任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
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
	scanf(" %c",&ch);
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
* @brief   输出输入二叉树的深度。
* @param   T：输入二叉树的根节点
* @retval  二叉树的深度。
* @see     TreeNode_ptr;
* @note    递归调用
*/
int BinaryTreeDepth(TreeNode_ptr T)
{
	if(NULL == T)
		return 0;
	int leftdepth, rightdepth;
	leftdepth = BinaryTreeDepth(T->leftchild);
	rightdepth = BinaryTreeDepth(T->rightchild);
	return (leftdepth > rightdepth) ? leftdepth+1 : rightdepth+1;
}

/** 
* @brief   判断是不是平衡二叉树。
* @param   T：输入二叉树的根节点
* @retval  0：不是  1：是。
* @see     TreeNode_ptr;
* @note    递归调用，缺点是节点会被重复计算深度
*/
int IsBalancedBinary1(TreeNode_ptr T)
{
	if(NULL == T)
		return 1;
	int leftdepth, rightdepth, difference;
	leftdepth = IsBalancedBinary1(T->leftchild);
	rightdepth = IsBalancedBinary1(T->rightchild);
	difference = leftdepth - rightdepth;
	if(difference > 1 || difference < -1)
		return 0;
	
	return IsBalancedBinary1(T->leftchild) && IsBalancedBinary1(T->rightchild);
}

/** 
* @brief   判断是不是平衡二叉树。
* @param   T：输入二叉树的根节点
* @retval  0：不是  1：是。
* @see     TreeNode_ptr;
* @note    递归调用，避免重复计算
*/
int IsBalancedBinary2(TreeNode_ptr T, int *depth)
{
	if(NULL == T)
	{
		*depth = 0;
		return 1;
	}
	int leftdepth, rightdepth,difference;
	if(IsBalancedBinary2(T->leftchild, &leftdepth) && IsBalancedBinary2(T->rightchild, &rightdepth))
	{
		difference = leftdepth - rightdepth;
		if(difference <= 1 && difference >= -1)
		{
			*depth = (leftdepth > rightdepth) ? leftdepth+1 : rightdepth+1;
			return 1;
		}
	}
	return 0;
}
int main()
{
	TreeNode_ptr root= Create_Binarytree();
	int depth  =0;
	if(IsBalancedBinary2(root, &depth))
	{
		printf("Balanced");
	}
	else
	{
		printf("Not Balanced");		
	}
}