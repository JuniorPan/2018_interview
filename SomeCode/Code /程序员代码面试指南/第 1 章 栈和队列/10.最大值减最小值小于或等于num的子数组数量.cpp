#include "../../generateRandomArray.h"



int getNum(vector<int> &arr, int num)
{
    if (arr.empty())
        return -1;

    deque<int> qmax;
    deque<int> qmin;

    int i = 0;
    int j = 0;
    int res = 0;
    while(i < arr.size())
    {
        while(j < arr.size())
        {
            while(!qmax.empty() && arr[qmax.back()] <=  arr[j]) // 维护一个最大值窗口
                qmax.pop_back();
            qmax.push_back(i);

            while(!qmin.empty() && arr[qmin.back()] >=  arr[j]) // 维护一个最小值窗口
                qmin.pop_back();
            qmin.push_back(i);

            if (arr[qmax.front()] - arr[qmin.front()] > num)
                break;
            j++;
        }

        if (qmin.front() == i)
        {
            qmin.pop_front();
        }
         if (qmax.front() == i)
        {
            qmax.pop_front();
        }

        res += j - i;
        i++;
    }
    return res;
}



int main()
{




    return 0;
}