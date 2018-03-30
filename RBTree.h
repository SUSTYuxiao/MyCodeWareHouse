//
// Created by 张鹏霄 on 2018/3/30.
//

#ifndef MYCODEWAREHOUSE_RBTREE_H
#define MYCODEWAREHOUSE_RBTREE_H

#include <iostream>
using std::cin;

enum COLOR{RED, BLACK};

template <class K, class V>
struct RBTreeNode
{
    K _key;
    V _value;
    COLOR;
    RBTreeNode *_parent;
    RBTreeNode *_lChild;
    RBTreeNode *_rChild;

    RBTreeNode(K &myKey, V &myValue)
            :_key(myKey)
            ,_value(myValue)
             ,COLOR(RED)
             ,_parent(NULL)
             ,_lChild(NULL)
             ,_rChild(NULL)
    {};
};

template <class K, class V>
class RBTree
{



    public:
    typedef RBTreeNode<K, V> Node;

    RBTRee():_root(NULL);

    bool Insert(const K &key, const V &value)
    {
        //判空
        if (!_root)
        {
            _root = new Node(key, value);
            return 1;
        }

        //插入节点
        Node *cur = _root;
        Node *parent = NULL;
        Node *grandFather = NULL;
        Node *uncle = NULL;
        while (1) //遇到插入位置则break
        {
            if (key > cur->_key)
            {
                parent = cur;
                cur = cur->_rChild;
                if (!cur)
                {
                    cur = new Node(key, value);
                    cur->_parent = parent;
                    parent->_rChild = cur;
                    break; //找到，在右子树插入
                }
            }
            else if (key < cur->_key)
            {
                parent = cur;
                cur = cur->_lChild;
                if (!cur)
                {
                    cur = new Node(key, value);
                    cur->_parent = parent;
                    parent->_lChild = cur;
                    break; //找到，在左子树插入
                }
            }
            else
            {
                break;
            }

            if (cur->_parent->COLOR == BLACK)//红黑相间，不需调整
            {
                return true;
            }

            //需要调整颜色节点
            while (parent || parent != _root)
            {
                //更新父节点的父节点及其另一子树的根节点
                grandFather = parent->_parent;
                if (parent == grandFather->_lChild)
                {
                    uncle = grandFather->_rChild;
                }
                else
                {
                    uncle = grandFather->_lChild;
                }

                if (uncle != NULL && uncle->COLOR == RED)
                {
                    parent->COLOR = uncle->COLOR = BLACK;
                    cur = grandFather;
                    parent = cur->_parent;
                }
                else
                {
                    if (cur == parent->_lChild && parent == grandFather->_lChild)//右单旋
                    {
                        RotateL(grandFather, false);
                    }
                    else if (cur == parent->_rChild && parent == grandFather->_rChild)//左单旋
                    {
                        RotateL(grandFather, false);
                    }
                    else if (cur == parent->_lChild && parent == grandFather->_rChild)//左右双旋
                    {
                        RotateLR(grandFather);
                    }
                    else//右左双旋
                    {
                        RotateRL(grandFather);
                    }

                }

            }
        }
    }


    void RotateL(Node *parent, bool isDouble)
    {
        Node *subR = parent->_rChild;
        Node *subRL = subR->_lChild;
        Node *pParent = parent->_parent;

        subR->_lChild = parent;
        subR->_parent = pParent;
        parent->_rChild = subRL;
        parent->_parent = subR;

        if (subRL)//subRL非空
        {
            subRL->_parent = parent;
        }

        if (pParent == NULL)//subR为根节点
        {
            _root = subR;
        }
        else
        {
            if (pParent->_rChild == parent)
            {
                pParent->_rChild = subR;
            }
            else
            {
                pParent->_lChild = subR;
            }
        }

        if (isDouble)
        {
            parent->COLOR = RED;
            subR->COLOR = BLACK;
        }
    }

    void RotateR(Node *parent, bool isDouble)
    {
        Node *subL = parent->_lChild;
        Node *subLR = subL->_rChild;
        Node *pParent = parent->_parent;

        subL->_rChild = parent;
        subL->_parent = pParent;
        parent->_lChild = subLR;
        parent->_parent = subL;

        if (subLR)//subRL非空
        {
            subLR->_parent = parent;
        }

        if (pParent == NULL)//subR为根节点
        {
            _root = subL;
        }
        else
        {
            if (pParent->_rChild == parent)
            {
                pParent->_rChild = subL;
            }
            else
            {
                pParent->_lChild = subL;
            }
        }

        if(isDouble)
        {
            parent->COLOR = RED;
            subL->COLOR = BLACK;
        }

    }

    void RotateLR(Node *parent)
    {

        RotateL(parent->_lChild, false);
        RotateR(parent, true);
    }

    void RotateRL(Node *parent)
    {
        RotateR(parent->_rChild, false);
        RotateL(parent, true);
    }

    bool isBalance()
    {
        //查是否右连续红节点
        //查每条路径黑节点数目
    }
    private:
    Node *_root;

};

#endif //MYCODEWAREHOUSE_RBTREE_H
