#include <iostream>
#include <deque>
#include <vector>
using namespace std;


int merge(vector<int> &arr, int l, int mid, int r)
{
    vector<int> help(r-l+1);
    int i = 0;
    int p1 = l;
    int p2 = mid + 1;
    int count = 0;

    while(p1 <= mid && p2 <= r)
    {
        // help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];

        // // 左数组比右数组大
        // temp[k++] = a[j++];
        // // 因为如果a[i]此时比右数组的当前元素a[j]大，
        // // 那么左数组中a[i]后面的元素就都比a[j]大
        // // 【因为数组此时是有序数组】
        if (arr[p1] > arr[p2])
        {
            count += mid - p1 + 1;
            help[i++] = arr[p2++];
        }
        else
        {
            help[i++] = arr[p1++];
        }

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
    return count;

}
int mergeSort(vector<int> &arr, int l, int r)
{
    if (l == r)
    {
        return 0;
    }
    int mid = l + ((r -l ) >> 1);
    int left = mergeSort(arr, l, mid);
    int right = mergeSort(arr, mid+1, r);
    int count = merge(arr, l, mid, r);
    return left + right + count;
}

int main()
{

    vector<int> arr = {1,2,3,4,5,6,7,0};
    cout << mergeSort(arr, 0, arr.size()-1) << endl;
    return 0;
}