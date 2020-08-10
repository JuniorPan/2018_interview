/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution {
    int merge(vector<int> &arr, int left, int mid, int right)
    {
        vector<int> help(right-left+1);
        int index = 0;
        int i = left;
        int j = mid + 1;
        int count = 0;
        // todo: 核心是这个循环
        while(i <= mid && j <= right)
        {
            if (arr[i] > 2LL*arr[j])
            {
                count += mid - i + 1;
                ++j;
            }
            else
                ++i;
        }

        i = left;
        j = mid+1;
        index = 0;
        while(i <= mid && j <= right)
        {
            help[index++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
        }


        while (i <= mid)
        {
            help[index++] = arr[i++];
        }
        while (j <= right)
        {
            help[index++] = arr[j++];
        }

        for (index = 0; index < help.size(); index++) 
        {
            arr[left + index] = help[index];
        }
        return count;
    }

    int mergeSort(vector<int> &arr, int l, int r)
    {
        if (l == r)
        {
            return 0;
        }
        int mid = l + ((r -l ) >> 1);
        int left = mergeSort(arr, l, mid);
        int right = mergeSort(arr, mid+1, r);
        int count = merge(arr, l, mid, r);
        return left + right + count;
    }
public:
    // 思路: 利用归并排序，但是代码写不出来
    int reversePairs(vector<int>& nums) 
    {
        if (nums.size() <= 1)
            return 0;
        
        return mergeSort(nums, 0, nums.size()-1);
    }
};
// @lc code=end

