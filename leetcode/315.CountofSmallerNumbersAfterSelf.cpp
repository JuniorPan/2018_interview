#include "../generateRandomArray.h"



    
   void merge(vector<int>& nums, int left, int mid, int right, vector<int>& res)
    {
        vector<int> help(right-left+1, 0);
        
        int k = 0;
        int i = left;
        int j = mid+1;
        
        while(i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
                help[k++] = nums[i++];
            else if(nums[i] > nums[j])
            {
                res[i] += 1;
                cout << "I: " << nums[i] << endl;
                help[k++] = nums[j++];
            }
        }
        while (i <= mid)
        {
            help[k++] = nums[i++];
        }
        while (j <= right)
        {
            help[k++] = nums[j++];
        }
    
        for (int f = 0; f < help.size(); f++) 
        {
            nums[left + f] = help[f];
        }
    }
    
    void mergerSort(vector<int>& nums, int left, int right, vector<int>& res)
    {
        if (left == right)
            return ;
        int mid = left + (right-left) / 2;
        
        mergerSort(nums, left, mid, res);
        mergerSort(nums, mid+1, right,res);
        merge(nums, left, mid, right, res);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty())
            return vector<int>{};
        
        vector<int> res(nums.size(), 0);
        mergerSort(nums, 0, nums.size()-1, res);
        return res;
    }

    


int main()
{

    int arr[] = {5,2,6,1};
    vector<int> nums(arr, arr+4);
    printArray(countSmaller(nums));


    return 0;
}