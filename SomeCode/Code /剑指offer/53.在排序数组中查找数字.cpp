#include <iostream>
#include <vector>
using namespace std;


    int getFirstK(vector<int> &data, int left, int right, int k)
    {
        
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if (data[mid] == k)
            {
                if ((mid > 0 && data[mid-1] != k) || mid == 0)  
                    return mid;
                else
                    right = mid - 1;
            }
            else if (data[mid] > k)
                right = mid-1;
            else
                left = mid + 1;
        }
        return -1;
    }
    
    int getLastK(vector<int> &data, int left, int right, int k)
    {
        
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if (data[mid] == k)
            {
                if ((data[mid+1] != k ))
                    return mid;
                else
                    left = mid + 1;
            }
            else if (data[mid] < k)
            {
                left = mid+1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }
    
    
    int GetNumberOfK(vector<int> data ,int k) 
    {
        int f = getFirstK(data, 0 , data.size()-1, k);
        int l = getLastK(data, 0 , data.size()-1, k);
        if (f == -1 || l == -1)
            return 0;
        return l - f + 1;
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


int main()
{

    vector<int> data = {3,3,3,3,3,3};

    cout << getFirstK(data, 0, data.size() -1 , 3) << endl;
    cout << getLastK(data, 0, data.size() -1 , 3) << endl;
    return 0;
}

