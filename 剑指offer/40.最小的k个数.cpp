#include <iostream>
#include <vector>
#include <set>
using namespace std;


// void heapInsert(vector<int> &arr, int index, int value)
// {
//     arr[index] = value;
//     while(index != 0)
//     {
//         int parent = (index-1) / 2; // 获取父节点

//         if(arr[parent] < arr[index])
//         {
//             int temp = arr[parent];
//             arr[parent] = arr[index];
//             arr[index] = temp;
        
//             index = parent;
//         }
//         else
//         {
//             break;
//         }
//     }
// }

// void heapify(vector<int> &arr, int index, int size)
// {
//     int left = 2 * index + 1;
//     while(left < size)
//     {
//         int big = left + 1 < size && arr[left+1] < arr[left] ? left : left+1 ; // smallest记录左右子树中较大的那个
//         if (arr[big] < arr[index])
//             break;
        
//         int temp = arr[big];
//         arr[big] = arr[index];
//         arr[index] = temp;

//         index = big;
//         left = 2 * index + 1;
//     }
// }

// vector<int> findKthLargest(vector<int>& nums, int k) 
// {
//     // if (nums.empty() || nums.size() < k)
//     //     return 0;
    
//     // int *heap = (int *)malloc(sizeof(int) * k);
//     vector<int> heap(k , 0);
    
//     for(int i = 0; i < k; i++)
//     {
//         heapInsert(heap, i, nums[i]);
//     }
    
//     for(int j = k; j < nums.size(); j++)
//     {
//         if (nums[j] < heap[0])
//         {
//             heap[0] = nums[j];
//             heapify(heap, 0, k-1);
//         }
//     }

//     // sort(heap.begin(), heap.end());
//     // for(int i = heap.size()-1; i >= 0; i--)
//     // {
//     //     int temp = heap[i];
//     //     heap[0] = heap[i];
//     //     heap[i] = temp;

//     //     heapify(heap, 0, i-1);
//     // }




    
//     return heap;
// }

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
        int big = left + 1 < size && arr[left+1] < arr[left] ? left: left +1; // smallest记录左右子树中较小的那个
        if (arr[big] < arr[index])
            break;
        
        int temp = arr[big];
        arr[big] = arr[index];
        arr[index] = temp;

        index = big;
        left = 2 * index + 1;
    }
}

vector<int> findKthLargest(vector<int>& nums, int k) 
{

    vector<int> heap(k , 0);
    
    for(int i = 0; i != k; i++)
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

    // sort(heap.begin(), heap.end());
    // for(int i = heap.size(); i > 0; i--)
    // {
    //     int temp = heap[0];
    //     heap[0] = heap[i-1];
    //     heap[i-1] = temp;
    //     cout << "i: " << i << " heap[i-1]: " << heap[i-1] << endl;
    //     heapify(heap, 0, i-1);
    // }
    
    return heap;
}


int main()
{

    vector<int> arr = {4, 5, 1, 8, 2, 7, 3, 6};

    vector<int> res = findKthLargest(arr, 4);

    for(int i = 0; i < res.size(); i++)
        cout <<res[i] << " ";
    // int a[] = {4,5,1,8,2,7,3,6};
    // int n = sizeof(a)/sizeof(a[0]);

    // getLastKnumbers(a, n, 4);
    // TraverseArray(a, n);
    // int index = Partition(a, n, 0, n-1);
  
    // cout << "hello " << endl;
    return 0;
}

