#include "../generateRandomArray.h"

// 1）二分查找元素x的下标，如无 return  -1
/*  
bin_search 二分查找元素x的下标，如无 return -1 
low,high 分别为待查元素的区间的 上下界(包含边界). 
x为待查元素. 
注意 low <= high  
*/  
int bin_search(int *a, int low, int high, int x)  
{  
    if(NULL == a || low > high || low <0)  
        return -1;  
  
    int mid;  
    while(low <= high)//注意是<=，若是<会找不到边界值情况  
    {  
        mid = low + ((high-low) >> 1);  
        if(x < a[mid])  
            high = mid-1;  
        else if(x > a[mid])  
            low = mid +1;  
        else  
            return mid;  
    }  
    return -1;  
}  


int binary_search(vector<int> &nums, int low , int high, int x)
{
    if (nums.empty() || low > high || low < 0)
        return -1;

    while(low <= high)
    {
        int mid = low + ((high - low) >> 1);

        if (x < nums[mid])
            high = mid - 1;
        else if (x > nums[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

// 问题2，二分查找返回x(可能有重复)第一次出现的下标，如无return  -1。
int binary_search_first(vector<int> &nums, int low , int high, int x)
{
    if (nums.empty() || low > high || low < 0)
        return -1;
    
    while(low < high)
    {
        int mid = low + ((high - low) >> 1);

        if (nums[mid] < x)
            low = mid+1;
        else
            high = mid;
    }
    if (nums[low] == x)
        return low;
    return -1;
}

// 二分查找返回x(可能有重复)最后一次出现的下标，如无return  -1
int binary_search_last(vector<int> &nums, int low , int high, int x)
{
    if (nums.empty() || low > high || low < 0)
        return -1;
    
    while(low+1 < high)
    {
        int mid = low + ((high - low) >> 1);

        if(nums[mid]<=x) // <=x  
            low = mid;  
        else // >x  
            high = mid-1; 
    }

    if(nums[high] == x)//先判断high  
        return high;  
    else if(nums[low] == x)  
        return low;  
    return -1;
    
}



int main()
{


    vector<int> nums = {5,7,7,8,8,10};
    cout << binary_search_first(nums, 0, nums.size()-1, 8 ) << endl;
    cout << binary_search_last(nums, 0, nums.size()-1, 8 ) << endl;

    return 0;
}