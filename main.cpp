#include <cstdio>
#include <iostream>
using namespace std;

//#include "fileCompress.h"
#include "AVL-Tree.h"

#include "sys/stat.h"

//int main(void)
//{
//    compress com1;
//    //压缩
//    string str("the.mp4");
//    com1.doCompress(str);
//    compress com2;
//    //解压缩
//    str += ".Huffman";
//    com2.unCompress(str);
//    return 0;
//}

int main(void)
{
    AVLTree<int,int> t;
    int a[] = {4,2,6,1,3,5,15,7,16,14};

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
    {
        t.Insert(a[i], 0);
    }

    return 0;

}