#include "../generateRandomArray.h"





// 题目是这样的，给一个数组，返回一个大小相同的数组。
// 返回的数组的第i个位置的值应当是，对于原数组中的第i个元素，至少往右走多少步，才能遇到一个比自己大的元素
//（如果之后没有比自己大的元素，或者已经是最后一个元素，则在返回数组的对应位置放上-1）。

// 简单的例子：

// input: 5,3,1,2,4
//return: -1 3 1 1 -1 


vector<int> getNextNeed(vector<int> &nums)
{
    vector<int> res(nums.size(), -1);
    stack<int> monoStack; // 单调栈
    for(int i = 0; i < nums.size(); i++)
    {
        while(!monoStack.empty() && nums[i] > nums[monoStack.top()])
        {
            res[monoStack.top()] = i;
            monoStack.pop();
        }
        monoStack.push(i);
    }

    return res;
}


int main()
{

    int arr[] = {5,3,1,2,4};
    vector<int> nums(arr, arr+5);
    printArray(nums);
    printArray(getNextNeed(nums));


    return 0;
}