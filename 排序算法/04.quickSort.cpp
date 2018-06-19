#include "../generateRandomArray.h"


void swap(vector<int> &arr, int i, int j)
 {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

vector<int>  partition(vector<int> arr, int l, int r)
{
    int less = l - 1;
    int more = r;
    while(l < more)
    {
        if (arr[l] < arr[r])
        {
            swap(arr, ++less, l++);
        }
        else if (arr[l] > arr[r])
        {
            swap(arr, --more, l);
        }
        else
        {
            l++;
        }
    }
    swap(arr, more, r);
    vector<int> res;
    res.push_back(less+1);
    res.push_back(more);
    return res;
}


void quickSort(vector<int>  arr, int l, int r)
 {
    if (l < r)
    {
        srand((unsigned)time(NULL));
        int random = l + rand() % (r - l) + 1;
        cout << "random: " << random << endl;
        swap(arr, random, r);
        vector<int> p = partition(arr, l, r);

        quickSort(arr, l, p[0] - 1);
        quickSort(arr, p[1] + 1, r);
    }
}

int main()
{

    srand((unsigned)time(NULL));
    int maxSize = rand() % 10 + 1;
    int maxValue = rand() % 100 + 1;
    vector<int> nums = generateRandomArray(maxSize, maxValue);
    printArray(nums);
    quickSort(nums, 0, nums.size()-1);
    printArray(nums);


    return 0;
}