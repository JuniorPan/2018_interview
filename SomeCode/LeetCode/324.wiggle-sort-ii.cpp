
#include <iostream>
#include <vector>
using namespace std;

int partrition(vector<int> &nums, int left, int right)
{
    int i = left, j = right;
    int pivot = nums[i]; //基准值
    while (i < j)
    {
        //当尾部元素大于等于基准值时向前移动后面的指针
        while (i < j && nums[j] >= pivot)
            j--;
        if (i < j)
        {
            nums[i] = nums[j];
            i++;
        }
        //当前面的元素小于基准值时向后移动前面的指针
        while (i < j && nums[i] < pivot)
            i++;
        if (i < j)
        {
            nums[j] = nums[i];
            j--;
        }
    }
    nums[i] = pivot;
    return i;
}

int quickSelect(vector<int> &nums, int begin, int end, int k)
{
    int index = partrition(nums, begin, end);
    cout << "index: " << index << endl;

    while (index != k)
    {
        if (index > k)
        {
            end = index - 1;
            index = partrition(nums, begin, end);
        }
        else
        {
            begin = index + 1;
            index = partrition(nums, begin, end);
        }
    }
    return index;
}

int main()
{
    vector<int> nums = {3,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1};
    int k =2;
    int index = partrition(nums, 0, nums.size() - 1);
    while (index != k-1)
    {
        if (index > k-1)
        {
            index = partrition(nums, 0, index - 1);
        }
        else
        {
            index = partrition(nums, index + 1, nums.size() - 1);
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    vector<int> res;

    for (int i = 0; i < k; i++)
    {
        res.push_back(nums[i]);
        cout << nums[i] << " ";
    }
    cout << endl;
}

// int main()
// {

//     vector<int> nums = {8, 2, 5, 12, 6, 4};
//     int n = nums.size();

//     for (int i = 0; i < nums.size(); i++)
//     {
//         cout << nums[i] << " ";
//     }
//     cout << endl;

//     int index = quickSelect(nums, 0, n-1, n / 2);

//     cout << "mid: " << index << endl;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         cout << nums[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }
