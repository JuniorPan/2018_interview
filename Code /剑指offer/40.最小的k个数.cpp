#include <iostream>
#include <set>
#include <vector>
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
    while (index != 0)
    {
        int parent = (index - 1) / 2; // 获取父节点

        if (arr[parent] < arr[index])
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
    while (left < size)
    {
        int big = left + 1 < size && arr[left + 1] < arr[left] ? left : left + 1; // smallest记录左右子树中较小的那个
        if (arr[big] < arr[index])
            break;

        int temp = arr[big];
        arr[big] = arr[index];
        arr[index] = temp;

        index = big;
        left = 2 * index + 1;
    }
}

vector<int> findKthLargest(vector<int> &nums, int k)
{

    vector<int> heap(k, 0);

    for (int i = 0; i != k; i++)
    {
        heapInsert(heap, i, nums[i]);
    }

    for (int j = k; j < nums.size(); j++)
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
int partition(vector<int> &nums, int left, int right)
{
    int small = left - 1;
    for (int i = left; i < right; i++)
    {
        if (nums[i] < nums[right])
            swap(nums[++small], nums[i]);
    }

    swap(nums[++small], nums[right]);
    return small;
}

void quickSort(vector<int> &nums, int target)
{

    int left = 0;
    int right = nums.size() - 1;
    int index = partition(nums, left, right);

    cout << "index: " << index << endl;
    cout << "target: " << target << endl;

    while (index != target)
    {
        if (index == target)
            return;
        if (index < target)
        {
            left = index + 1;
            index = partition(nums, left, right);
        }
        else
        {
            right = index - 1;
            index = partition(nums, left, right);
        }
    }
}

vector<int> GetLeastNumbers_Solution(vector<int> nums, int k)
{
    vector<int> res;
    int left = 0;
    int right = nums.size() - 1;
    int index = partition(nums, left, right);

    cout << "index: " << index << endl;
    cout << "k: " << k << endl;
    while (index != k - 1)
    {
        if (index > k - 1)
        {
            right = index - 1;
            index = partition(nums, left, right);
        }
        else
        {
            left = index + 1;
            index = partition(nums, left, right);
        }
    }
    for (int i = 0; i < k; i++)
    {
        res.push_back(nums[i]);
    }
    return res;
}

int main()
{

    vector<int> arr = {4, 5, 1, 8, 2, 7, 3, 6};

    vector<int> res = GetLeastNumbers_Solution(arr, 5);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    // int a[] = {4,5,1,8,2,7,3,6};
    // int n = sizeof(a)/sizeof(a[0]);

    // getLastKnumbers(a, n, 4);
    // TraverseArray(a, n);
    // int index = Partition(a, n, 0, n-1);

    // cout << "hello " << endl;
    return 0;
}
