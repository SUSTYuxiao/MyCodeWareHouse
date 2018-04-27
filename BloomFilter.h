//
// Created by 张鹏霄 on 2018/4/24.
// 布隆过滤器
// 布隆过滤器
// 认为某个值存在是不准确的，
// 认为某个值不存在是准确的，
//

#ifndef MYCODEWAREHOUSE_BLOOMFILTER_H
#define MYCODEWAREHOUSE_BLOOMFILTER_H

#include "BitMap.h"

template <class K
        ,class HashFuc1
        ,class HashFuc2
        ,class HashFuc3>
class BloomFilter
{
    public:
    BloomFilter(size_t num)
            :_bm(num * 5)
            ,_range(num * 5)
    {}//总位数 = (k / 0.7) * 数据个数 k为映射几个位

    bool Set(const K& key)
    {
        //使用HashFuc*()(key) 通过使用匿名对象的()重载，避免声明一个普通对象
        size_t hash1nd = HashFuc1()(key);
        size_t hash2nd = HashFuc2()(key);
        size_t hash3nd = HashFuc3()(key);

        _bm.Set(hash1nd % _range);
        _bm.Set(hash2nd % _range);
        _bm.Set(hash3nd % _range);
    }

//    void ReSet(const K &key)
//    {
//
//    }

    bool Find(const K &key)
    {
        size_t hash1nd = HashFuc1()(key);
        size_t hash2nd = HashFuc2()(key);
        size_t hash3nd = HashFuc3()(key);

        if(! _bm.Find(hash1nd % _range)) //find返回值为0 则说明没找到
            return false;

        if(! _bm.Find(hash2nd % _range))
            return false;

        if(! _bm.Find(hash3nd % _range))
            return false;

        return true;
    }

    protected:
    BitMap _bm;
    size_t _range;
};

#endif //MYCODEWAREHOUSE_BLOOMFILTER_H
