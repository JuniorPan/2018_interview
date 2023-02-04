
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> res(nums.size(), 0);
    if (nums.empty())
        return res;
    vector<int> left(nums.size(), 0);
    vector<int> right(nums.size(), 0);

    cout << "Test1" << endl;
    left[0] = 1;
    cout << "Test2" << endl;
    for (int i = 1; i < nums.size(); i++)
    {
        cout << "Test3" << endl;
        left[i] = nums[i - 1] * left[i - 1];
    }
    cout << "Test4" << endl;
    // for(int i = 0; i < left.size(); i ++)
    // {
    //     cout << left[i] << " left ";
    // }
    right[nums.size() - 1] = 1;
    cout << "Test5" << endl;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i + 1];
        cout << "Test6" << endl;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        res[i] = left[i] * right[i];
    }
    return res;
}

int main()
{
    vector<int> nums = {1,2,3,4};
    vector<int> res = productExceptSelf(nums);

    for(int i = 0; i < res.size(); i ++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}