//
// Created by 张鹏霄 on 2018/1/3.
//

// 模拟简单栈 以及 实现非递归 前序、中序、后序遍历二叉树
#ifndef BITHOMEWORK_BINTREE_H
#define BITHOMEWORK_BINTREE_H

#include "stdio.h"
#include "stdlib.h"

typedef char datatype;

typedef struct BinNode{
    datatype data;
    BinNode* lchild;
    BinNode* rchild;
}BinNode;

typedef struct stack{
    BinNode *node[100];
    int size = 0;
}stack;

BinNode* CreateBinaryTree(BinNode **T);//前序建立二叉树

void Push(stack *_stack, BinNode *node);//压栈
void Pop(stack *_stack);//出栈
void Clear(stack *_stack);//栈清空
BinNode* Top(stack *_stack);//取栈顶元素
int IsEmpty(stack *_stack);//栈判空

void PreorderTree(BinNode *T);//非递归前序
void InorderTree(BinNode *T);//非递归中序
void PostorderTree(BinNode *T);//非递归后序



#endif //BITHOMEWORK_BINTREE_H