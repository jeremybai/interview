 /**************************************************************************
 * @file     BinaryTree.c
 * @brief    二叉树基本操作源文件 
 * @version  V1.00
 * @date     2013.12.25
 * @note     
****************************************************************************/
#include "BinaryTree.h"
#include "stdio.h"
#include "malloc.h"

/** 
 * @brief   使用先序遍历创建二叉树。
 * @param   None
 * @retval  TreeNode* 创建的树节点。
 * @see     TreeNode;
 * @note    scanf函数的问题：scanf会读入回车符，当需要一个一个的输入字符时，可以在%c前面加个空格
 */
TreeNode* Create_Binarytree()
{
    ElementType ch;
    TreeNode* T;
    // scanf(" %c",&ch);    //这样调用scanf时，树的结点一次全部输入，如果要一次一个的输入，在%c前加个空格
	ch  = getchar();
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
 * @param   T	根节点指针
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


int main()
{
	TreeNode* T;
	T = Create_Binarytree();
	Preorder_Traversal(T);
}
