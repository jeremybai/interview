/****************************************************************************
 * @file     BinaryTree.h.h
 * @brief    二叉树基本操作头文件 
 * @version  V1.00
 * @date     2013.12.25
 * @note     
****************************************************************************/


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


TreeNode* Create_Binarytree();
void Preorder_Traversal(TreeNode *T);
