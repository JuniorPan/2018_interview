#include <iostream>
#include <vector>
using namespace std;


int Min(int *arr, int len)
{
    int low = 0;
    int high = len-1;
    int mid = 0;

    while(low < high)
    {
        if (low == high - 1)
        {
            mid = high;
            break;
        }

        mid = (low + high) / 2;
        if (arr[low] == arr[high] && arr[mid] == arr[low])
        {
            int res = 0;
            for(int i = low; i <= high; i++)
            {
                if (res < arr[i])
                {
                    res = arr[i];
                }
                return res;
            }
        }
        
        if (arr[low] >= arr[mid])
        {
            high = mid;

        }
        if (arr[mid] >= arr[high])
        {
            low = mid;
        }

    }
    return arr[mid];

}

int minNumberInRotateArray(vector<int> rotateArray)
 {
        int end = rotateArray.size() - 1;
        if(end < 0)
            return 0;
        int start = 0;
        int mid = start;
        while(rotateArray[start] >= rotateArray[end]){
             
            if (start == end - 1) {
                mid = end;
                break;
            }
            mid = (start + end) / 2;
            if (rotateArray[start] == rotateArray[end] && rotateArray[start] == rotateArray[mid]) {
                int res = rotateArray[start];
                for(int i = start + 1; i <= end; i++)
                {
                    if (res > rotateArray[i])
                        res = rotateArray[i];
                }
                return res;
            }
            if (rotateArray[start] <= rotateArray[mid])
                start = mid;
            else if(rotateArray[mid] <= rotateArray[end])
                end = mid;
        }
        return rotateArray[mid];
    }

int main()
{



    return 0;
}