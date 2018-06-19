#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


int deleteAndEarn(vector<int>& nums)
 {
        if (nums.size() <= 0)
            return 0;
        
        int n = 6;
        vector<int> newVec(n, 0);
        
        for(int num : nums)
        {
            newVec[num] += num;
            cout << num;
        }
            

        for(int i = 0; i < n; i++)
        {
            cout << newVec[i] << " "; 
        }
        return 0;
}

int main()
{

    vector<int> nums= {3,4,2,6,5};
    deleteAndEarn(nums);
    cout << "hello" << endl;

    return 0;
}