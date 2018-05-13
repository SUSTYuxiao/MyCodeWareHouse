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

int main()
{
    string num1 = "1111111111111111911124235234373457437434743734543743574357435743745374537435743574537443574743747474374357435747343734745345111";
    string num2 = "43131734734745343573457435747345434734573457435743574357435734574357347745743573457474357435743557435743577435743743734572222";

    string ret = _add(num1, num2);
    cout << ret << endl;

    string sssss = "aaaaa.11111";
    string numm = sssss.substr(0, sssss.find('0'));
    sssss = sssss.substr(sssss.find('0') + 1);
    cout << numm << endl << sssss;

    return 0;
}
