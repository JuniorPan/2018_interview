#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


void printPairSum(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n <= 1)
        return;

    int left = 0;
    int right = n - 1;
    while(left < right)
    {
        if (nums[left] + nums[right] < k)
            left++;
        else if (nums[left] + nums[right] > k)
            right--;
        else
        {
            if (left == 0 || nums[left-1] != nums[left])
                cout << nums[left] << " " << nums[right] << endl;
            left++;
            right--;
        }
    }
}


void printPairSum_2(vector<int> &nums, int f, int left ,int right, int k)
{

    while(left < right)
    {
        if (nums[left] + nums[right] < k)
            left++;
        else if (nums[left] + nums[right] > k)
            right--;
        else
        {
            if (left == f+1 || nums[left-1] != nums[left])
                cout << nums[f] << " " << nums[left] << " " << nums[right] << endl;
            left++;
            right--;
        }
    }
}

void printTri(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n < 2)
        return;
    for(int i = 0; i < n-2; i++)
    {
        if (i == 0 || nums[i] != nums[i-1])
            printPairSum_2(nums, i, i+1 ,n-1, k-nums[i]);
    }
}


int main()
{
    cout << "hello wor" << endl;

    vector<int> nums = {-1,0,1,2,-1,-4};
    sort(nums.begin(), nums.end());
    int k = 0;
    printTri(nums, k);

    return 0;
}