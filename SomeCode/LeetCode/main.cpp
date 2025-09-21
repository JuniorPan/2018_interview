//
//  main.cpp
//  leetcode
//
//  Created by panqiang on 2018/1/19.
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    
    
    int index = nums.size() - 1;
    while(nums[index] < nums[index-1])
    {
        index = index - 1;
    }
    
    if (index == 0)
    {
        sort(nums.begin(), nums.end());
        return ;
    }
    cout << "index: " << index << endl;
    
    int j = nums.size() -1;
    cout << "j: " << j << endl;
    while(nums[j] <= nums[index-1])
    {
        j--;
    }
    
    cout << "j: " << j << endl;
    
    int temp = nums[j];
    nums[j] = nums[index-1];
    nums[index-1] = temp;
    
    
    
    
    sort(nums.begin()+index, nums.end());
    
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}




int main01(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums = {1,1,5};
    nextPermutation(nums);
    

    
    std::cout << "Hello, World!\n";
    return 0;
}
