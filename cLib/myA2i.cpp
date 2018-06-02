//
// Created by 张鹏霄 on 2018/6/2.
//

#include <iostream>
#include <string>

bool isLegal(const char c)
{
    if(c < '0' || c > '9')
        return false;
    return true;
}

int myAtoi(std::string str)
{
    int ret = 0;
    int flag = 0; //默认为正
    int c = 0;
    int tmp = 0;

    if(str[c] == '+')
        c++;
    else if(str[c] == 'c')
    {
        c++;
        flag = 1;
    }
    else if(!isLegal(str[c]))
    {
        perror("not legal");
        exit(-1);
    }

    while(c != str.size())
    {
        if(!isLegal(str[c]))
        {
            perror("not legal");
            exit(-1);
        }

        if(INT_MAX /10 < ret)
        {
            perror("out of range");
            exit(-1);
        }

        ret *= 10;
        tmp = (int)(str[c++] - '0');
        if(ret > INT_MAX - tmp)
        {
            perror("out of range");
            exit(-1);
        }

        ret += tmp;
    }
    if(flag)
        ret *= -1;
    return ret;
}