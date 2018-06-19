#include "../generateRandomArray.h"


void merge(vector<int> &arr, int l, int mid, int r)
{
    vector<int> help(r-l+1);
    int i = 0;
    int p1 = l;
    int p2 = mid + 1;

    while(p1 <= mid && p2 <= r)
    {
        help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }

    while (p1 <= mid)
    {
        help[i++] = arr[p1++];
    }
    while (p2 <= r)
    {
        help[i++] = arr[p2++];
    }

    for (i = 0; i < help.size(); i++) 
    {
		arr[l + i] = help[i];
	}

}
void mergeSort(vector<int> &arr, int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = l + ((r -l ) >> 1);
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}




int main()
{

    srand((unsigned)time(NULL));
    int maxSize = rand() % 10 + 1;
    int maxValue = rand() % 100 + 1;
    vector<int> nums = generateRandomArray(maxSize, maxValue);
    mergeSort(nums, 0, nums.size()-1);
    printArray(nums);
    return 0;
}