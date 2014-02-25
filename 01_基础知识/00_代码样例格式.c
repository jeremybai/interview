 
// 1 文件头注释：
/****************************************************************************
 * @file     <文件名>.c
 * @brief    文件简要说明。
 * @version  V1.00
 * @date     年.月.日
 * @note     描述需要注意的问题
****************************************************************************/
//举例：
/****************************************************************************
 * @file     BinaryTree.h
 * @brief    二叉树基本操作头文件 
 * @version  V1.00
 * @date     2013.12.25
 * @note     None
****************************************************************************/


// 2 函数头注释：
/** 
 * @brief   函数简要说明。
 * @param   参数名和参数的描述，有个可选的参数：（dir），指明参数的方向是传入
			还是传出。dir的值可以为[in][out][in,out]. （多个参数在下一行继续
			添加 @param）
 * @retval  返回值和返回值的描述
 * @see     本函数参考其它的相关的函数;
 * @note    描述需要注意的问题
 */
 
// 举例
/** 
 * @brief     使用先序遍历二叉树。
 * @param[in] T  根节点指针
 * @retval    None
 * @see       TreeNode
 * @note      None
 */
 void Preorder_Traversal(TreeNode *T);
 
 
 //3 简单注释，用于一些参数和返回都为空的简单函数，类，结构体，枚举等。
 /**    Brief description  
 *    description continued \n 
 *  
 *    Detailed description starts here.  
 */ 
//举例
//3.1结构体
/**		树节点结构体定义 \n  
 *     
 *		定义树节点所包含的成员变量。    
 */ 
typedef struct treenode
{
	int data;					/**< 节点数据 */  
	struct treenode* leftchild;		/**< 左孩子节点指针 */  
	struct treenode* rightchild;		/**< 右孩子节点指针 */  
} TreeNode, *TreeNode_ptr;
//3.2枚举
/**    颜色的枚举定义 \n  
  *   
  *    该枚举定义了系统中需要用到的颜色,可以使用该枚举作为系统中颜色的标识  
  */ 
enum TEnum   
{   
     RED,           /**< 枚举，标识红色    */      
     BLUE,          /**< 枚举，标志蓝色    */      
     YELLOW         /**< 枚举，标志黄色. */      
}enumVar;  