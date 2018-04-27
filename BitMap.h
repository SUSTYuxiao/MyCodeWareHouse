//
// Created by 张鹏霄 on 2018/4/24.
// 位图
//

#ifndef MYCODEWAREHOUSE_BITMAP_H
#define MYCODEWAREHOUSE_BITMAP_H

#include <cstdio>
#include <vector>

class BitMap
{
    public:
    BitMap(size_t range)
    {
        _bit.resize((range >> 5) + 1, 0);
    }

    void Set(const size_t num)
    {
        size_t whichByte = num >> 5; //whichByte 指位图中哪一个size_t存储该位
        size_t whichBit = num % 32;
        _bit[whichByte] |= 1 << whichBit;
    }

    void ReSet(const size_t num)
    {
        size_t whichByte = num >> 5; //whichByte 指位图中哪一个size_t存储该位
        size_t whichBit = num % 32;
        _bit[whichByte] &= ~(1 << whichBit);
    }

    bool Find(const size_t num)
    {
        size_t whichByte = num >> 5; //whichByte 指位图中哪一个size_t存储该位
        size_t whichBit = num % 32;
        return (bool)(_bit[whichByte] & (1 << whichBit));
    }

    protected:
    std::vector<size_t> _bit;

};

#endif //MYCODEWAREHOUSE_BITMAP_H
