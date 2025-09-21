#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) 
{
    int n = nums.size();
    int res;
    
    unordered_map<int, int> hash;
    int sum = 0;
    hash[0] = 1;
    for(int i = 0; i < n; i++)
    {
        sum += nums[i];
        
        if (hash.find(sum - k) != hash.end())
            res += hash[sum-k];
        hash[sum] ++;
        
    }
    return res;
}

int main()
{
    vector<int> nums = {1,3,2,3,1,2, -6};
    int k = 6;

    cout << subarraySum(nums, k) << endl;
}