 /**************************************************************************
 * @file     07_二叉搜索树转为双向链表.c
 * @brief    二叉搜索树转为双向链表 
 * @version  V1.00
 * @date     2014.9.11
 * @note     
****************************************************************************/
#include "stdio.h"
#include "malloc.h"

/**		节点数据类型  
 *     
 *		定义节点数据类型。    
 */
typedef int ElementType;


/**		树节点结构体定义  
 *     
 *		定义树节点所包含的成员变量。    
 */ 
typedef struct treenode
{
	ElementType data;					/**< 节点数据 */  
	struct treenode* leftchild;		/**< 左孩子节点指针 */  
	struct treenode* rightchild;		/**< 右孩子节点指针 */  
} TreeNode, *TreeNode_ptr;


/** 
* @brief   创建节点。
* @param[in]   data   节点的data
* @retval  None。
* @see     TreeNode;
* @note    
*/
TreeNode_ptr CreateNode(ElementType data)
{
	TreeNode_ptr node_ptr;
	if(NULL == (node_ptr = (TreeNode_ptr)malloc(sizeof(TreeNode))))
	{
		printf("申请空间错误!\r\n");
	}
	node_ptr->data = data;
	node_ptr->leftchild = NULL;
	node_ptr->rightchild = NULL;
	return node_ptr;
}

/** 
* @brief   将节点进行连接。
* @param[in]   root         根节点root
* @param[in]   leftchild    节点的leftchild
* @param[in]   rightchild   节点的rightchild
* @retval  None。
* @see     TreeNode;
* @note    
*/
void ConnectNodes(TreeNode_ptr root, TreeNode_ptr leftchild, TreeNode_ptr rightchild)
{
	if(NULL == root)
	printf("参数错误!\r\n");
	root->leftchild = leftchild;
	root->rightchild = rightchild;
} 

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
    scanf(" %d",&ch);    
    if(ch != -1)
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
        printf("%d ",data);
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
 
 
void Convent(TreeNode_ptr Root, TreeNode_ptr* LastNode)
{
	if(NULL == Root)
		return;
	TreeNode_ptr PCurrent = Root;
	if(NULL != PCurrent->leftchild)
	{
		Convent(PCurrent->leftchild, LastNode);
	}
	PCurrent->leftchild = *LastNode;
	if(NULL != (*LastNode))
		(*LastNode)->rightchild = PCurrent;
	*LastNode = PCurrent;
	if(NULL != PCurrent->rightchild)
	{
		Convent(PCurrent->rightchild, LastNode);
	}
}

TreeNode_ptr ConventToDList(TreeNode_ptr Root)
{
	TreeNode_ptr LastNode = NULL;
	Convent(Root, &LastNode);
	if(NULL != LastNode)
	{
		while( NULL != LastNode->leftchild)
		{
			LastNode = LastNode->leftchild;
		}	
	}
	return LastNode;
}

int main()
{
	//TreeNode_ptr T;
	//T = Create_Binarytree();
	TreeNode_ptr TreeNode_ptr4 = CreateNode(4);
	TreeNode_ptr TreeNode_ptr2 = CreateNode(2);
	TreeNode_ptr TreeNode_ptr3 = CreateNode(3);
	TreeNode_ptr TreeNode_ptr1 = CreateNode(1);
	TreeNode_ptr TreeNode_ptr6 = CreateNode(6);
	TreeNode_ptr TreeNode_ptr5 = CreateNode(5);
	TreeNode_ptr TreeNode_ptr7 = CreateNode(7);
	
	ConnectNodes(TreeNode_ptr4, TreeNode_ptr2, TreeNode_ptr6);
	ConnectNodes(TreeNode_ptr2, TreeNode_ptr1, TreeNode_ptr3);
	ConnectNodes(TreeNode_ptr6, TreeNode_ptr5, TreeNode_ptr7);
	
	printf("\n中序遍历为：");
	Inorder_Traversal(TreeNode_ptr4);

	printf("\n转化为双向链表：");
	TreeNode_ptr Head = ConventToDList(TreeNode_ptr4);
	while(NULL != Head)
	{
		printf("%d    ",Head->data);
		Head = Head->rightchild;
	}

	printf("\n");
}
