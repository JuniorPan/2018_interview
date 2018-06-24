#include <iostream>
#include <vector>
using namespace std;



int trap(vector<int>& height) {
    if (height.empty())
        return 0;
    
    int n = height.size();
    int res = 0;
    int left_max = height[0];
    int right_max = height[n-1];
    
    int l = 1;
    int r = n - 2;
    while(l <= r)
    {
        if (left_max <= right_max)
        {
            res += max(0, left_max - height[l]);
            left_max = max(left_max, height[l++]);
        }
        else
        {
            res += max(0, right_max - height[r]);
            right_max = max(height[r--], right_max);
        }
    }
    return res;
}