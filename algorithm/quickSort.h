//
// Created by 张鹏霄 on 2018/6/16.
//

#ifndef MYCODEWAREHOUSE_QUICKSORT_H
#define MYCODEWAREHOUSE_QUICKSORT_H

#include <vector>
using namespace std;

int fuc(vector<int> &arr, int left, int right)
{
    int key = arr[right]; //基准值设为最右侧值

    //前后指针法
    int prev = left -1;
    int cur = left -1;

    while(++cur < right)
    {
        if(arr[cur] < key && ++prev != cur)
            swap(arr[cur], arr[prev]);
    }

    swap(arr[++prev], arr[right]);

    return prev;
}

void quickSort(vector<int> &a, int left, int right)
{

    if(right >= left || a.empty())
        return;

    int mid = fuc(a, left, right);
    quickSort(a, left, mid - 1);
    quickSort(a, mid + 1, right);
}

#endif //MYCODEWAREHOUSE_QUICKSORT_H
