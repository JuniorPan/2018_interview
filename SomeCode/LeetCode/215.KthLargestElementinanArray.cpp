#include "../generateRandomArray.h"

void heapInsert(int *arr, int index, int value)
{
    arr[index] = value;
    while(index != 0)
    {
        int parent = (index-1) / 2; // 获取父节点

        if(arr[parent] > arr[index])
        {
            int temp = arr[parent];
            arr[parent] = arr[index];
            arr[index] = temp;
        
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void heapify(int *& arr, int index, int size)
{
    int left = 2 * index + 1;
    while(left < size)
    {
        int smallest = (left + 1 < size && arr[left+1] < arr[left]) ? left+1: left; // smallest记录左右子树中较小的那个
        cout << "smallest: " << smallest << endl;
        smallest  = arr[smallest] < arr[index] ? smallest : index;
        cout << "smallest: " << smallest << endl;
        if (smallest == index)
            break;

        cout << "smallest: " << smallest << endl;
        
        int temp = arr[smallest];
        arr[smallest] = arr[index];
        arr[index] = temp;

        index = smallest;
        left = 2 * index + 1;
    }
}



int findKthLargest(int *nums, int k) 
{

    
    int *heap = (int *)malloc(sizeof(int) * k);
    
    for(int i = 0; i < k; i++)
    {
        heapInsert(heap, i, nums[i]);
    }
    cout << "建小堆: " << endl;
    printArray(heap, k);
    
    for(int j = k; j < 4; j++)
    {
        if (nums[j] > heap[0])
        {
            heap[0] = nums[j];
            cout << "交换之后: " << nums[j] << endl;
            printArray(heap, k);

            heapify(heap, 0, k);


            cout << "heapify之后: " << endl;
            printArray(heap, k);
        }
    }

    cout << "建堆插入: " << endl;
    printArray(heap, k);
    return 0;
}

int main()
{

    // int maxSize = rand() % 50 + 1;
    // int maxValue = rand() % 100 + 1;
    // vector<int> nums = generateRandomArray(maxSize, maxValue);
    // printArray(nums);
    int nums[4] = {3,1,2,4};
    findKthLargest(nums, 2);


    // int *arr = (int *)malloc(sizeof(int) * nums.size());
    // for(int i = 0; i < nums.size(); i ++)
    // {
    //     arr[i] = nums[i];
    // }

    // heapSort(arr, nums.size());
    // printArray(arr, nums.size());

    // sort(nums.begin(), nums.end());
    // printArray(nums);

}
