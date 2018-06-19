#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int removeDuplicates(vector<int>& nums) 
{
    if (nums.empty())
        return 0;
    int k = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i-1])
        {
            continue;
        }
        else
        {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}


int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(nums) << endl;
    
    for(int i = 0; i < 5; i++)
    {
        cout << nums[i] << " "; 
    }
    cout << endl;

    return 0;
}