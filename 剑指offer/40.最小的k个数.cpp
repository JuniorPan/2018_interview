#include <iostream>
#include <vector>
#include <set>
using namespace std;


void heapInsert(vector<int> &arr, int index, int value)
{
    arr[index] = value;
    while(index != 0)
    {
        int parent = (index-1) / 2; // 获取父节点

        if(arr[parent] < arr[index])
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

void heapify(vector<int> &arr, int index, int size)
{
    int left = 2 * index + 1;
    while(left < size)
    {
        int smallest = left + 1 < size && arr[left+1] < arr[left] ? left : left+1 ; // smallest记录左右子树中较小的那个
        if (arr[smallest] < arr[index])
            break;
        
        int temp = arr[smallest];
        arr[smallest] = arr[index];
        arr[index] = temp;

        index = smallest;
        left = 2 * index + 1;
    }
}

int findKthLargest(vector<int>& nums, int k) 
{
    if (nums.empty() || nums.size() < k)
        return 0;
    
    // int *heap = (int *)malloc(sizeof(int) * k);
    vector<int> heap(k , 0);
    
    for(int i = 0; i < k; i++)
    {
        heapInsert(heap, i, nums[i]);
    }
    
    for(int j = k; j < nums.size(); j++)
    {
        if (nums[j] < heap[0])
        {
            heap[0] = nums[j];
            heapify(heap, 0, k);
        }
    }

    sort(heap.begin(), heap.end());
    for (int i = 0; i < k; i++)
    {
        cout << heap[i] << " "; 
    }
    cout << "----------" << endl;
    return heap[0];
}


int main()
{

    vector<int> arr = {4,5,1,8,2,7,3,6};

    cout << findKthLargest(arr, 4) << endl;
    // int a[] = {4,5,1,8,2,7,3,6};
    // int n = sizeof(a)/sizeof(a[0]);

    // getLastKnumbers(a, n, 4);
    // TraverseArray(a, n);
    // int index = Partition(a, n, 0, n-1);
  
    cout << "hello " << endl;
    return 0;
}

