#include "../generateRandomArray.h"


int main()
{

    srand((unsigned)time(NULL));
    int maxSize = rand() % 10 + 1;
    int maxValue = rand() % 100 + 1;
    vector<int> nums = generateRandomArray(maxSize, maxValue);
    int n = nums.size();
    vector<int> left2right(n, 0);

    
    int maxleft = INT_MIN;
    
    for(int j = n-1; j >= 0; j--)
    {
        if (nums[j] > maxleft)
        {
            left2right[j] = nums[j];
            maxleft = nums[j];
        }
        else
        {
            left2right[j] = maxleft;
        }
    }

    printArray(nums);
    printArray(left2right);

}