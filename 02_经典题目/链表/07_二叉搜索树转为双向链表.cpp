#include<iostream>
#include<stdlib.h>
using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

//创建二叉树结点
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode=new BinaryTreeNode();
    pNode->m_nValue=value;
    pNode->m_pLeft=NULL;
    pNode->m_pRight=NULL;
    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent,BinaryTreeNode* pLeft,BinaryTreeNode* pRight)
{
    if(pParent!=NULL)
    {
        pParent->m_pLeft=pLeft;
        pParent->m_pRight=pRight;
    }
}

void InOrderPrintTree(BinaryTreeNode* pRoot)//中序遍历
{
    if(pRoot!=NULL)
    {
        if(pRoot->m_pLeft!=NULL)//
            InOrderPrintTree(pRoot->m_pLeft);

        cout<<"value of this node is "<<pRoot->m_nValue<<endl;

        if(pRoot->m_pRight!=NULL)
            InOrderPrintTree(pRoot->m_pRight);
    }
    else
    {
        cout<<"this node is null."<<endl;
    }

}

void Convert(BinaryTreeNode* pNode,BinaryTreeNode** pLastNodeInList)
{
    if(pNode==NULL)
        return;

    BinaryTreeNode* pCurrent=pNode;
    //左子树转换，遍历到左子树的叶子结点
    if(pCurrent->m_pLeft!=NULL)//遍历左子树
        Convert(pCurrent->m_pLeft,pLastNodeInList);

    pCurrent->m_pLeft=*pLastNodeInList;
    if((*pLastNodeInList)!=NULL)
        (*pLastNodeInList)->m_pRight=pCurrent;

    *pLastNodeInList=pCurrent;
    //右子树转换
    if(pCurrent->m_pRight!=NULL)//遍历右子树
        Convert(pCurrent->m_pRight,pLastNodeInList);

}

BinaryTreeNode* Convert(BinaryTreeNode* pRoot)
{
    BinaryTreeNode* pLastNodeInList=NULL;//指向双向链表的尾结点
    Convert(pRoot,&pLastNodeInList);//转换排序二叉树为双向链表

    //求双向链表的头结点
    BinaryTreeNode* pHeadOfList=pLastNodeInList;
    while(pHeadOfList!=NULL&&pHeadOfList->m_pLeft!=NULL)
        pHeadOfList=pHeadOfList->m_pLeft;
    return pHeadOfList;

}

//输出双向链表
void PrintList(BinaryTreeNode* pRoot)
{
    BinaryTreeNode* pNode = pRoot;
    while(pNode != NULL)
    {
        printf("%d\t", pNode->m_nValue);
        pNode = pNode->m_pRight;
    }
    printf("\nPrintList ends.\n");
}

int main()
{
//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
    //创建树结点
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);
    //连接树结点
    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

    //PrintTree(pNode10);
    InOrderPrintTree(pNode10);//中序遍历
    BinaryTreeNode* pHeadOfList=Convert(pNode10);//获取双向链表头结点
    PrintList(pHeadOfList);//输出链表
}

