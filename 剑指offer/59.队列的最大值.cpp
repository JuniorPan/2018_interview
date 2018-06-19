#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void getMaxWindow(vector<int> arr, int w)
{
    vector<int> res(arr.size() - w  +1);

    deque<int> qmax;

    int index = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        if(!qmax.empty())
        {
            // 如果队列头元素不在滑动窗口中了，就删除头元素
            if(i >= qmax.front() + w)
            {
                qmax.pop_front();
            }
            //// 如果当前数字大于队列尾，则删除队列尾，直到当前数字小于等于队列尾，或者队列空
            while(!qmax.empty() && arr[qmax.back()] <= arr[i])   // 若队列不为空且队尾元素比当前元素小，则从队尾弹出
            {
                 qmax.pop_back();    
            }
                
        }
        qmax.push_back(i); 
        //// 滑动窗 口经过三个元素，获取当前的最大值，也就是队列的头元素
        if (i + 1 >= w)
        {
            res[index++] = arr[qmax.front()]; 
        }
    }

    for(int i = 0; i < index; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

}


int main()
{
    int arr[] = { 2, 3, 4, 2, 6, 2, 5, 1 };  
    vector<int>A(arr, arr + 8);  
    getMaxWindow(A, 3);
    cout << "hello world" << endl;
    return 0;
}