#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int getMaxLen(vector<int> &nums, int k)
{
    map<int,int> hashmap;
    map<int,int>::iterator it;; 
 
    if (nums.empty())
        return 0;
    hashmap[0] = -1;
    int len = 0;
    int sum = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        it = hashmap.find(sum - k);
        if(it != hashmap.end())
        {
            len = max(i - hashmap[sum-k], len);
        }
        if (it == hashmap.end())
        {
            hashmap[sum] = i;
        }
    }
    return len;
}


int main()
{
    vector<int> nums = {1,1,-1,1};
    int k = 0;
    cout << getMaxLen(nums, k);



    return 0;
}