#include <iostream>
#include <vector>

using namespace std;

int low_bound(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            right = mid - 1;
        else if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
    }
    return left;
}
int main()
{

    vector<int> nums = {1, 2, 3, 4, 8};
    int target = 9;

    cout << "low_bound_9: " << low_bound(nums, 9) << endl;

    cout << "low_bound 7: " << low_bound(nums, 7) << endl;

    

    return 0;
}