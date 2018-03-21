//
// Created by 张鹏霄 on 2018/1/3.
//

#include "Non-recursive-BinTree.h"

BinNode* CreateBinaryTree(BinNode **T)
{
    char data;
    scanf("%c",&data);//abd#f##eg###c##

    if(data=='#')
    {
        *T=NULL;
    }
    else
    {
        *T=(BinNode *)malloc(sizeof(BinNode));
        (*T)->data=data;
        (*T)->lchild = CreateBinaryTree(&(*T)->lchild);
        (*T)->rchild = CreateBinaryTree(&(*T)->rchild);
    }
    return *T;
}

void Push(stack *_stack, BinNode* node)
{
    if (_stack->size==100)
    {
        return;
    }

    _stack->node[_stack->size++] = node;
}

void Pop(stack *_stack)
{
    if (_stack->size == 0)
    {
        return;
    }

    _stack->size--;
}

void Clear(stack *_stack)
{
    _stack->size = 0;
}

BinNode* Top(stack *_stack)
{
    if (_stack->size == 0)
    {
        return NULL;
    }

    return _stack->node[_stack->size-1];
}

int IsEmpty(stack *_stack)
{
    return _stack->size == 0 ? 1: 0;
}

void PreorderTree(BinNode *T)//非递归前序
{
    stack S;
    stack *_stack = &S;

    printf("preorder: ");
    while (T || !IsEmpty(_stack))//节点为空且栈为空则遍历结束
    {
        while (T)//寻找左孩子叶节点
        {
            printf("%c ", T->data);
            Push(_stack, T);
            T = T->lchild;
        }
        T = Top(_stack);
        Pop(_stack);

        T = T->rchild;
    }
    printf("\n");
}

void InorderTree(BinNode *T)//非递归中序
{
    stack S;
    stack *_stack = &S;

    printf("Inorder: ");
    while (T || !IsEmpty(_stack))//节点为空且栈为空则遍历结束
    {
        while (T)//寻找左孩子叶节点
        {
            Push(_stack, T);
            T = T->lchild;
        }
        T = Top(_stack);
        Pop(_stack);

        printf("%c ", T->data);

        T = T->rchild;
    }
    printf("\n");

}

void PostorderTree(BinNode *T)//非递归后序
{
    stack S;
    stack *_stack = &S;
    BinNode *prev = NULL;//记录上一遍历节点

    printf("Postorder: ");
    while (T || !IsEmpty(_stack))//节点为空且栈为空则遍历结束
    {
        while (T)//寻找左孩子叶节点
        {
            Push(_stack, T);
            T = T->lchild;
        }
        T = Top(_stack);
        Pop(_stack);


        if (T->rchild && T->rchild != prev)
        {
            Push(_stack, T);
            T = T->rchild;
            prev = T;
        }
        else
        {
            printf("%c ", T->data);
            T = NULL;
        }

    }
    printf("\n");

}


