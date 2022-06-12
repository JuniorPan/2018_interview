#include <iostream>
#include <vector>
#include <set>
using namespace std;



int Partition(int *data, int n, int start, int end)
{
    if (data == nullptr || n <= 0 || start < 0 || end <= start)
        return -1;

    int i = start;
    int j = end;
    int pivot = data[end];
    while(i < j)
    {
        while(i < j && data[i] < pivot)
            i++;
        if (i < j)
        {
            data[j] = data[i];
            j--;
        }

        while(i < j && data[j] >= pivot)
            j--;
        if (i < j)
        {
            data[i] = data[j];
            i++;
        }
    }

    data[i] = pivot;

    return i;

}


int Partition_1(int arr[], int start, int end)
{

    int i = start;
    int j = end;
    int pivot = arr[end];
    cout << "pivot " << pivot << endl;
    while (i < j)
    {

        while(i < j && arr[i] < pivot)  //从左往右找
            i++;
        if (i < j)
        {
            arr[j] = arr[i];
            j--;
        }


        while(i < j && arr[j] >= pivot) // 从右往右找
            j--;
        if (i < j)
        {
            arr[i] = arr[j];;
            i++;
        }

    }

    arr[i] = pivot;

    return i;


}

int getMoreThanHalf(int *data, int n)
{
    if (n <= 0)
        return 0;
    int start = 0;
    int end = n - 1;
    int mid = n / 2;
    int index = Partition(data, n, start, end);
    cout << index << endl;
    while(mid != index)
    {
        cout << mid << " " << index << endl;
        if (index > mid)
        {
            end = index-1;
            index = Partition(data, n, start, end);
        }
        else{
            start = index + 1;
            index = Partition(data, n, start, end);
        }
    }
    return data[mid];
}


class Solution {
    
private:
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

void heapify(int *&arr, int index, int size)
{
    int left = 2 * index + 1;
    while(left < size)
    {
        int smallest = left + 1 < size && arr[left+1] < arr[left] ? left +1: left ; // smallest记录左右子树中较小的那个
        if (arr[smallest] > arr[index])
            break;
        
        int temp = arr[smallest];
        arr[smallest] = arr[index];
        arr[index] = temp;

        index = smallest;
        left = 2 * index + 1;
    }
}
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || nums.size() < k)
            return 0;
        
        int *heap = (int *)malloc(sizeof(int) * k);
        
        for(int i = 0; i < k; i++)
        {
            heapInsert(heap, i, nums[i]);
        }
        
        for(int j = k; j < nums.size(); j++)
        {
            if (nums[j] > heap[0])
            {
                heap[0] = nums[j];
                heapify(heap, 0, k);
            }
        }
        return heap[0];
    }
};


int main()
{
    int data[] = {1,2,33,3,3,3,5,4,6,3,3};
    int n = sizeof(data) / sizeof(data[0]);

    cout << getMoreThanHalf(data,n);
    
    return 0;
}