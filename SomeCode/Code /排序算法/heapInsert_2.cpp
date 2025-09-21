#include "../generateRandomArray.h"



void heapInsert(vector<int> &arr, int index)
{
    while(arr[index] > arr[(index-1)/2])
    {
        swap(arr[index], arr[(index-1)/2]);
        index = (index-1)/2;
    }
}

void heapify(vector<int> &arr, int index, int size)
{
    int left = 2 * index + 1;
    while(left < size)
    {
        int largest = left + 1 < size && arr[left+1] > arr[left] ? left+1 : left; // largest记录左右子树中较大的那个
        largest  = arr[largest] > arr[index] ? largest : index;
        if (largest == index)
            break;
        
        swap(arr[largest], arr[index]);
        index = largest;
        left = 2 * index + 1;
    }
}

void heapSort(vector<int> &arr)
{
    if (arr.empty() || arr.size() < 2)
        return ;

    int n = arr.size();
    for(int i = 0; i < n; i++)
        heapInsert(arr, i);
    
    
    swap(arr[0], arr[--n]);
    while(n > 0)
    {
        heapify(arr, 0, n);
        swap(arr[0], arr[--n]);
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
    cout << "厉害了" << endl;


    return 0;
}