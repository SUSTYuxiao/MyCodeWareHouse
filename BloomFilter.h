//
// Created by 张鹏霄 on 2018/4/24.
// 布隆过滤器
//

#ifndef MYCODEWAREHOUSE_BLOOMFILTER_H
#define MYCODEWAREHOUSE_BLOOMFILTER_H

#include "BitMap.h"

template <class K>
class BloomFilter
{
    public:
    BloomFilter(size_t num):_bm(num*5) //总位数 = (k / 0.7) * 数据个数 k为映射几个位
    {

    }
    void Set(const K& key)
    {

    }

    void ReSet(const K &key)
    {

    }

    void Test(const K &key)
    {

    }

    protected:
    BitMap _bm;
};

#endif //MYCODEWAREHOUSE_BLOOMFILTER_H
