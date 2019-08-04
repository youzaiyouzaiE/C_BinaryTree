#include <stdio.h>
#include <stdlib.h>
 
typedef struct BTNode  ////BinaryTreeNode
{
    char data;
    struct BTNode * pLChild;
    struct BTNode * pRChild;
} BTNODE, *PBTNode;


PBTNode createBT();

void frontPrintfBinryTree(PBTNode rootNode); //先序遍历

void middlePrintfBinryTree(PBTNode rootNode); //中序遍历

void tailPrintfBinryTree(PBTNode rootNode); //后序遍历
 
///此翻转只对满二叉树有效  注释部分
void translateBinryTree(PBTNode rootNode);//翻转二叉树

int main(int argc, char const *argv[])
{
    PBTNode rootNode = createBT();

    frontPrintfBinryTree(rootNode);
    printf("\n \n");

    middlePrintfBinryTree(rootNode);
    printf("\n \n");

    tailPrintfBinryTree(rootNode);
    printf("\n \n");

    printf("\n\n============================================\n\n");
    translateBinryTree(rootNode);
    frontPrintfBinryTree(rootNode);
    printf("\n \n");

    middlePrintfBinryTree(rootNode);
    printf("\n \n");

    tailPrintfBinryTree(rootNode);
    printf("\n \n");

    return 0;
}

///随便造个二叉树
PBTNode createBT() {
    PBTNode rootNode = (PBTNode)malloc(sizeof(BTNODE));
    PBTNode bNode = (PBTNode)malloc(sizeof(BTNODE));
    PBTNode cNode = (PBTNode)malloc(sizeof(BTNODE));
    PBTNode dNode = (PBTNode)malloc(sizeof(BTNODE));
    PBTNode eNode = (PBTNode)malloc(sizeof(BTNODE));
    PBTNode fNode = (PBTNode)malloc(sizeof(BTNODE));
    PBTNode gNode = (PBTNode)malloc(sizeof(BTNODE));
    PBTNode hNode = (PBTNode)malloc(sizeof(BTNODE));

    rootNode ->data = 'A';
    bNode ->data ='B';
    cNode ->data = 'C';
    dNode ->data = 'D';
    eNode ->data = 'E';
    fNode ->data = 'F';
    gNode ->data = 'G';
    hNode ->data = 'H';

    // rootNode ->pLChild = bNode;
    // bNode ->pLChild = NULL;
    // bNode ->pRChild = cNode;
    // cNode ->pLChild = dNode;
    // cNode ->pRChild = eNode;
    // dNode ->pLChild = NULL;
    // dNode ->pRChild = NULL;
    // eNode ->pLChild = NULL;
    // eNode ->pRChild = NULL;
    // rootNode ->pRChild = fNode;
    // fNode ->pRChild = gNode;
    // fNode ->pLChild = NULL;
    // gNode ->pLChild = hNode;
    // gNode -> pRChild = NULL;
    // hNode ->pLChild = NULL;
    // hNode ->pRChild = NULL;


    rootNode ->pLChild = bNode;
    rootNode ->pRChild = cNode;
    bNode ->pLChild = dNode;
    bNode ->pRChild = eNode;
    cNode ->pLChild = fNode;
    cNode ->pRChild = gNode;
    dNode ->pLChild = NULL;
    dNode ->pRChild = NULL;
    eNode ->pLChild = NULL;
    eNode ->pRChild = NULL;
    fNode ->pLChild = NULL;
    fNode ->pRChild = NULL;
    gNode ->pLChild = NULL;
    gNode ->pRChild = NULL;

    return rootNode;
}

///先访问根节点
///先序遍历左子树
///先序遍历左子树
void frontPrintfBinryTree(PBTNode rootNode) {
    if (rootNode != NULL)
    {
    printf("%c -> ",rootNode->data);
    if (rootNode ->pLChild != NULL) {
        frontPrintfBinryTree(rootNode ->pLChild);   
    }
    
    if (rootNode ->pRChild != NULL) {
        frontPrintfBinryTree(rootNode ->pRChild);
        }
    }  
}

//中序遍历左子树
//再访问根节点
//再中序遍历右子树
void middlePrintfBinryTree(PBTNode rootNode) {
    if (rootNode != NULL) {
        if (rootNode ->pLChild) 
        {
            middlePrintfBinryTree(rootNode ->pLChild);
        }
        printf("%c -> ",rootNode->data);
        if (rootNode ->pRChild) 
        {
            middlePrintfBinryTree(rootNode -> pRChild);
        }
    }
}

//先遍历左子树
//再遍历右子树
//再访问根节点
void tailPrintfBinryTree(PBTNode rootNode) 
{
    if (rootNode != NULL) { 
         if (rootNode ->pLChild) 
        {
            tailPrintfBinryTree(rootNode ->pLChild);
        }
        if (rootNode ->pRChild) 
        {
            tailPrintfBinryTree(rootNode -> pRChild);
        }
        printf("%c -> ",rootNode->data);
    }
}

///此翻转只对满二叉树有效
void translateBinryTree(PBTNode rootNode) 
{
    if (rootNode != NULL)
    {
        if (rootNode ->pLChild != NULL && rootNode ->pRChild != NULL )
        {
        PBTNode tempNode = rootNode ->pLChild;
        rootNode ->pLChild = rootNode ->pRChild;
        rootNode ->pRChild = tempNode;
        translateBinryTree(rootNode ->pLChild);
        translateBinryTree(rootNode ->pRChild);
        }
        

    }
}

