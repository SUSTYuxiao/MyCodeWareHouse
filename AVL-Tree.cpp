//
// Created by 张鹏霄 on 2018/3/24.
//
#include <iostream>
using namespace std;

template <class K, class V>
struct AVLNode
{
    K _key;
    V _value;
    int _baf; //Balance Factor 平衡因子
    AVLNode *_parent;
    AVLNode *_lChild;
    AVLNode *_rChild;

    AVLNode(const K &key, const V &value)
            :_key(key)
            ,_value(value)
            ,_baf(0)
            ,_parent(NULL)
            ,_lChild(NULL)
            ,_rChild(NULL)
    {};
};

template  <class K, class V>
class AVLTree
{
    typedef AVLNode<K,V> Node;

    private:
    Node* _root;

    public:
    AVLTree()
            :_root(NULL)
    {};

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
        while (1) //遇到插入位置则break
        {
            if (key > cur->_key)
            {
                parent = cur;
                cur = cur->_rChild;
                if (!cur)
                {
                    cur = new Node(key, value);
                    cur->_parent=parent;
                    parent->_rChild = cur;
                    return true; //找到，在右子树插入
                }
            }
            else if (key < cur->_key)
            {
                parent = cur;
                cur = cur->_lChild;
                if (!cur)
                {
                    cur = new Node(key, value);
                    cur->_parent=parent;
                    parent->_lChild = cur;
                    return true; //找到，在左子树插入
                }
            }
            else
            {
                break;
            }
        }

        //更新平衡因子
        while (!_root)
        {
            if (cur == parent->_rChild)
            {
                parent->_baf++;
            }
            else
            {
                parent->_baf--;
            }

            if (parent->_baf == 0)//无需更新
            {
                return true;
            }
            else if (parent->_baf == 1 || parent->_baf == -1)//向上更新
            {
                cur = parent;
                parent = parent->_parent;
            }

            if (parent->_baf == 2)//右子树过高
            {
                if (cur->_baf == 1)
                {
                    RotateL(parent);
                }
                else
                {
                    RotateRL(parent->_lChild);
                }
            }
            else//左子树过高
            {
                if (cur->_baf == 1)
                {
                    RotateR(parent);
                }
                else
                {
                    RotateLR(parent->_rChild);
                }
            }
        }//end of while
    }

    void RotateL(Node *parent)
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

        parent->_baf = 0;
        subR->_baf = 0;
    }

    void RotateR(Node *parent)
    {
        Node *subL = parent->_lChild;
        Node *subLR = subL->_lChild;
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

        parent->_baf = 0;
        subL->_baf = 0;
    }

    void RotateLR(Node *parent)
    {
        int bafSaver = parent->_lChild->_rChild->_baf;//记录subLR的平衡因子
        Node *subR = parent->_rChild;

        RotateL(parent->_lChild);
        RotateR(parent);

        if (bafSaver == 1)
        {
            parent->_baf = -1;
        }
        else if (bafSaver == -1)
        {
            subR->_baf = 1;
        }
    }

    void RotateRL(Node *parent)
    {
        int bafSaver = parent->_rChild->_lChild->_baf;//记录subRL的平衡因子
        Node *subR = parent->_rChild;

        RotateR(parent->_rChild);
        RotateL(parent);

        if (bafSaver == 1)
        {
            parent->_baf = -1;
        }
        else if (bafSaver == -1)
        {
            subR->_baf = 1;
        }
    }

};

