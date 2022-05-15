#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArray(vector<int> &nums)
{
    if (nums.empty())
        return {};

    // 这里做的是为了 0~i 上有序
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j + 1] < nums[j])
                swap(nums[j + 1], nums[j]);
        }
    }

    return nums;
}

int main()
{

    cout << "Hello World!" << end;
    return 0;
}