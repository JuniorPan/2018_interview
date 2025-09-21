#include <iostream>
#include <vector>

using namespace std;
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    if (nums.empty())
        return 0;
    int cur_prod = 1;
    int left = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        cur_prod *= nums[i];
        while (cur_prod < k && left <= i)
        {
            res += (i - left + 1);
            cout << "cur_prod: " << cur_prod << " left: " << left << " i: " << i << " len: " << i - left + 1 << endl;;
            cur_prod = cur_prod / nums[left++];
        }
        
    }
    return res;
}

int main()
{

    vector<int> nums = {10, 2, 5, 6};
    int k = 100;

    int res = numSubarrayProductLessThanK(nums, k);

    cout << "res: " << res;

    return 0;
}