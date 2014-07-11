 /**************************************************************************
 * @file     BinaryTree.c
 * @brief    二叉树基本操作源文件 
 * @version  V1.00
 * @date     2013.12.25
 * @note     创建，前序，中序，后序遍历
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
 * @brief   使用先序遍历二叉树。
 * @param[in]   T	根节点指针
 * @retval  None。
 * @see     TreeNode;
 * @note    先序遍历二叉树。
 */
void Preorder_Traversal(TreeNode *T)
{
    ElementType data;
    if(T!=NULL)
    {
        data=T->data;
        printf("%c ",data);
        Preorder_Traversal(T->leftchild);
        Preorder_Traversal(T->rightchild);
    }
}
/** 
 * @brief   使用中序遍历二叉树。
 * @param[in]   T	根节点指针
 * @retval  None。
 * @see     TreeNode;
 * @note   中序遍历二叉树。
 */
void Inorder_Traversal(TreeNode *T)
{
    ElementType data;
    if(T!=NULL)
    {
        Inorder_Traversal(T->leftchild);
		data=T->data;
        printf("%c ",data);
        Inorder_Traversal(T->rightchild);
    }
}

/** 
 * @brief   使用后序遍历二叉树。
 * @param[in]   T	根节点指针
 * @retval  None。
 * @see     TreeNode;
 * @note    后序遍历二叉树。
 */
void Postorder_Traversal(TreeNode *T)
{
    ElementType data;
    if(T!=NULL)
    {
        Postorder_Traversal(T->leftchild);
        Postorder_Traversal(T->rightchild);
		data=T->data;
        printf("%c ",data);
    }
}
 
/** 
 * @brief   返回输入的树的镜像。
 * @param[in]   T：输入的树的指针
 * @retval  返回树的镜像
 * @see     TreeNode;
 * @note    递归实现
 */
void TreeMirror(TreeNode_ptr T)
{
	if(NULL == T)
		return ;
	if(NULL == T->leftchild && NULL == T->rightchild)
		return ;
	TreeMirror(T->leftchild);
	TreeMirror(T->rightchild);
	
	TreeNode_ptr temp = T->leftchild;
	T->leftchild = T->rightchild;
	T->rightchild = temp;
}
 
int main()
{
	TreeNode_ptr T1,T2;
	T1 = Create_Binarytree();
	TreeMirror(T1);
	Preorder_Traversal(T1);
}
