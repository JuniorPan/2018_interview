#include "../generateRandomArray.h"


void heapInsert(vector<int> &nums, int index)
{
    while(nums[index] > nums[(index-1)/2])
    {
        swap(nums[index], nums[(index-1)/2]);
        index = (index-1) / 2;
    }
}

void heapify(vector<int> &nums, int index, int size)
{
    int left = 2 * index + 1;
    while(left < size)
    {
        int largets = left + 1 < size && nums[left+1] > nums[left] ? left+1 : left;
        largets = nums[largets] > nums[index] ? largets : index;
        if (largets == index) 
            break;
        swap(nums[largets], nums[index]);
        index = largets;
        left = 2 * index + 1;
    }
}

void heapSort(vector<int> &arr)
{
    if (arr.empty() || arr.size() < 2)
        return ;
    for(int i = 0; i < arr.size(); i++)
        heapInsert(arr, i);

    int length = arr.size();
    swap(arr[0], arr[--length]);
    while(length > 0)
    {
        heapify(arr, 0, length);
        swap(arr[0], arr[--length]);
    }
}


int main()
{

    srand((unsigned)time(NULL));

    for(int i = 0; i < 100; i++)
    {
        int maxSize = rand() % 50 + 1;
        int maxValue = rand() % 100 + 1;
        vector<int> nums = generateRandomArray(maxSize, maxValue);
        vector<int> copy(nums);
        
        heapSort(nums);
        sort(copy.begin(), copy.end());

        for(int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != copy[i])
            {
                cout << "failed" << endl;
                break;
            }
        }
    }
    cout << "厉害了!" << endl;
    return 0;
}