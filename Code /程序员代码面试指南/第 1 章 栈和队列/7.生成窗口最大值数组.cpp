#include "../../generateRandomArray.h"


vector<int> getMaxWindow(vector<int> arr, int w)
{
    if (arr.empty() || arr.size() < w || w < 1)
    {
        vector<int> res;
        return res;
    }
    deque<int> q;
    vector<int> res(arr.size() - w + 1, 0);

    int index = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        while(!q.empty() && arr[q.back()] <=  arr[i]) // 如果队列不空并且当前元素比队尾元素大，那么就一直弹出
            q.pop_back();
        q.push_back(i);

        if (q.front() == i - w) // 如果队头元素下标过期了，直接弹出
        {
            q.pop_front();
        }
        if (i >= w -1) // 表明开始形成窗口了
        {
            res[index++] = arr[q.front()];
        }
    }
    
    return res;
}



int main()
{

    cout << to_string(12);


    return 0;
}