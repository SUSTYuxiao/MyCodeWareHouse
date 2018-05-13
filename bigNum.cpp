//
// Created by 张鹏霄 on 2018/5/13.
//
// 大数运算

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isnot_legal(const string &str)
{
    if( !( (str[0]-'0' > 0  && str[0]-'0' < 10) || str[0] == '-') )
        return true;
    for (int i = 1; i < str.size()-1; ++i)
    {
        if(!(str[i]-'0' > 0  && str[i]-'0' < 10))
            return true;
    }
    return false;
}

bool _compare(const string &left, const string &right)
{
    if(left.size() > right.size())
        return true;
    if(left.size() < right.size())
        return false;
    for (int j = 0; j < left.size() ; --j)
    {
        if(left[j] > right[j])
            return true;
        else if(left[j] < right[j])
            return false;
    }
    return true;//相等
}

string _add(string &left, string &right, string op)
{

    string ret;
    ret.resize(left.size(), '0');

    //加法
    int carry = 0;//进位
    int tmp = 0;
    for (int k = 0; k < left.size(); ++k)
    {
        tmp = left[k]-'0' + right[k]-'0' + carry;
        carry = tmp / 10;
        ret[k] = char((tmp % 10) + '0');
    }

    if (carry)
        ret += "1";

    ret += op;//添加符号
    reverse(ret.begin(), ret.end());
    return ret;
}

string _sub(string &left, string &right, string op)
{
    string ret;
    ret.resize(left.size(), '0');

    //减法
    for (int k = 0; k < left.size(); ++k)
    {
        if (left[k] < right[k])
        {
            left[k+1] -= 1;
            left[k] += 10;
        }
        ret[k] = left[k] - right[k] + '0';
    }

    ret += op;//添加符号
    reverse(ret.begin(), ret.end());
    return ret;
}

string _start(string &left, string &right)
{
    //初始化
    string ret;
    string _left = left;
    string _right = right;
    string op ="";
    enum way {ADD, SUB};
    way _way = ADD;

    //判断浮点数 TODO
//    string *big = &_left;
//    string *small  = &_right;
//    size_t leftsize = _left.size()-1 -_left.rfind('.');
//    size_t rightsize = _left.size()-1 -_left.rfind('.');


    //判断合法
    if (isnot_legal(left) || isnot_legal(right))
    {
        exit(-1);
    }



    //判断所有可能性
    if(left[0] == '-' && right[0] == '-') //全为负数
    {
        _left = left.substr(1);
        _right = right.substr(1);
        op = "-";
    }
    else if (left[0] != '-' && right[0] != '-') //全为正数
        ;
    else
    {
        _way = SUB;
        if(left[0] == '-')
        {
            _left = left.substr(1);
            swap(_left, _right);
        }
        if(right[0] == '-')
            _right = right.substr(1);
        if (!_compare(_left, _right))
        {
            swap(_left, _right);
            op = "-";
        }
    }

    //处理数据
    reverse(_left.begin(), _left.end());
    reverse(_right.begin(), _right.end());
    if (_left.size() > _right.size())
        _right.resize(_left.size(), '0');
    else
        _left.resize(_right.size(), '0');

    switch (_way)
    {
        case ADD:
            return _add(_left, _right, op);
        case SUB:
            return _add(_left, _right, op);
    }
}