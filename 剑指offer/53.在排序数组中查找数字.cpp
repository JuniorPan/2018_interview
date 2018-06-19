#include <iostream>
using namespace std;

int getFirstK(int data[], int length, int k, int start, int end)
{
    if (start > end)
    {
        return -1;
    }

    int mid = (start + end) / 2;
    int midData = data[mid];

    if (midData == k)
    {
        if ((mid > 0 && data[mid-1] != k)|| mid == 0)
        {
            return mid;
        }  
        else
        {
            end = mid+1;
        }
    }
    else if (midData > k)
        end = mid - 1;
    else
        start = mid+1;
    return getFirstK(data, length, k, start, end);
}

int getLastK(int data[], int length, int k, int start, int end)
{
    if (start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    int midData = data[mid];

    if (midData == k)
    {
        if ((mid < length-1 && data[mid+1] != k)|| mid == length-1)
        {
            return mid;
        }  
        else
        {
            start = mid+1;
        }
    }
    else if (midData < k)
    {
       
        start = mid + 1;
    }    
    else
    {
         end = mid - 1;
    }
    return getLastK(data, length, k, start, end);
}

int getNumberOfK(int *data, int length, int k)
{
    int number = 0;
    if (data != nullptr && length > 0)
    {
        int first = getFirstK(data, length, k, 0, length-1);
        int last = getLastK(data, length, k, 0, length-1);

        if (first > -1 && last > -1)
            number = last - first + 1;
        return number;
    }
    return -1;
}


int getMissNumber(int data[], int len)
{
    if (data == nullptr || len <= 0)
        return -1;
    int left = 0;
    int right = len - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;
        if (data[mid] != mid)
        {
            if (mid == 0 || data[mid-1] == mid-1)
                return mid;
            right = mid -1;
        }
        else{
            left = mid + 1;
        }
    }

    if (left == len)
        return len;
    return -1;
}


int main_53_1()
{

    int data[] = {1,2,3,3,3,3,4,5};
    int length = sizeof(data) / sizeof(data[0]);

    cout << getFirstK(data, length,  3, 0, length-1) << endl;
    cout << getLastK(data, length,  3, 0, length-1) << endl;
    cout << getNumberOfK(data, length, 3) << endl;

    return 0;
}

int main()
{

    int data[] = {0,1,2,3,4,5,6,8,9};
    int length = sizeof(data) / sizeof(data[0]);

    cout << getMissNumber(data, length) << endl;
    return 0;
}

