#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


void swap(int *arr, int index1, int index2)
{
    int tem = arr[index1];
    arr[index2] = arr[index1];
    arr[index1] = tem;
}

void printArray(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// 最大堆的插入操作
void heapInsert(int *arr, int value, int index)
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


void heapify(int *arr, int index, int heapSize)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    while(left < heapSize)
    {
        if (arr[left] > arr[index])
        {
            largest = left;
        }
        if (right < heapSize && arr[right] > arr[largest])
        {
            largest = right;
        }
        if (largest != index)
        {

            int temp = arr[largest];
            arr[largest] = arr[index];
            arr[index] = temp;
        }
        else{
            break;
        }
        index = largest;
        left = 2 * index + 1;
        right = 2 * index + 2;
    }
}

void getMinKNumsByHeap(int *arr, int k, int n)
{

    
    if (k < 1 || arr == nullptr || n <= 0)
        return;
    int *heap = (int *)malloc(sizeof(int) * k);

    for(int i = 0; i < k; i++)
    {
        heapInsert(heap, arr[i], i);
    }

    for(int i = k; i < n; i++ )
    {
        if (arr[i] < heap[0])
        {
            heap[0] = arr[i];
            heapify(heap, 0, k);
        }
    }
    // printArray(heap, k);
    cout << heap[0] << endl;
}

int main()
{
    int arr[] = {3,5,5,2,52,1,45,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    getMinKNumsByHeap(arr, 4, n);

    return 0;
}