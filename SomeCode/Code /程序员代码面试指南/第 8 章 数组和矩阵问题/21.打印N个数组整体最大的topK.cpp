#include <iostream>
using namespace std;


void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;

}

void heapInsert(int *heap, int index)
{
    while(index != 0)
    {
        int parent = (index-1) / 2;
        if(heap[parent] < heap[index])
        {
            swap(heap[parent], heap[index]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}


void heapify(int *heap, int index, int heapsize)
{
    int left = 2 * index +1;
    int right = 2 * right + 1;
    int largest = index;
    while(left < heapsize)
    {
        if (heap[left] > heap[index])
            largest = left;
        if (right < heapsize && heap[right] > heap[largest])
            largest = right;
        if(largest != index)
        {
            swap(heap[largest], heap[index]);
        }
        else{
            break;
        }
        index = largest;
        left = 2 * index + 1;
        right = 2 * index + 1;
    }
}



int main()
{
    int arr[] = {4,1,2,5,8,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapify(arr, 0, n);


    return 0;
}