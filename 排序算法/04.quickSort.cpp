#include "../generateRandomArray.h"


// void swap(vector<int> &arr, int i, int j)
//  {
//     int tmp = arr[i];
//     arr[i] = arr[j];
//     arr[j] = tmp;
// }

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


int partrition(vector<int>& input, int start, int end)
{

    int small = start - 1;
    
    for(int i = start;i < end; i++)
    {
        if(input[i] < input[end])
        {
            small++;
            if (i != small)
                swap(input[small], input[i]);
        }
    }
    small++;
    swap(input[small],input[end]);
    return small;
}

void quicksort2(vector<int> &nums, int start, int end)
{   
    if (start == end)
        return;
    int index = partrition(nums, start, end);
    if (index > start)
        quicksort2(nums, start, index - 1);
    if (index < end)
        quicksort2(nums, index+1, end);

}

int main()
{
    int count = 0;
    while(true)
    {
        srand((unsigned)time(NULL));
        int maxSize = rand() % 20 + 1;
        int maxValue = rand() % 100 + 1;
        vector<int> nums = generateRandomArray(maxSize, maxValue);

        vector<int> nums2(nums);
        // copyArray(nums, nums2);

        quicksort2(nums, 0, nums.size()-1);
        sort(nums2.begin(), nums2.end());

        for (int i = 0; i < nums2.size(); i++)
        {
            if (nums2[i] != nums[i])
            {
                cout << "false" << " ";
                break;
            }
        }


        count ++;
        if (count > 100)
            break;
    }
    


    return 0;
}