 /**************************************************************************
 * @file     BinaryTree.c
 * @brief    二叉树基本操作源文件 
 * @version  V1.00
 * @date     2013.12.25
 * @note     创建，前序，中序，后序遍历
****************************************************************************/
#include "BinaryTree.h"
#include "stdio.h"
#include "malloc.h"

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
	//逐个输入，输入完一个空格或者回车
	//如果%c前不加空格，一次性输入，此时每个字符代表一个节点
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
}/** 
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
 
int main()
{
	TreeNode* T;
	T = Create_Binarytree();
    printf("前序遍历为：");
	Preorder_Traversal(T);
	printf("\n中序遍历为：");
	Inorder_Traversal(T);
	printf("\n后序遍历为：");
	Postorder_Traversal(T);
	printf("\n");
}
