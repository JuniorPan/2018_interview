#include <iostream>
#include <vector>
using namespace std;

// 和为s的两个数字
vector<int> FindNumbersWithSum(vector<int> array,int sum)
{
    vector<int> res;
    int length = array.size();
    if (length <= 1 || sum < 0)
        return res;
    
    int left = 0;
    int right = length-1;
    while(left < right)
    {
        int cur = array[left] + array[right];
        
        if (cur == sum)
        {
            res.push_back(array[left]);
            res.push_back(array[right]);
            break;
        }
        else if (cur > sum)
        {
            right --;
        }
        else
        {
            left ++;
        }
    }
    return res;
}


// 和为s的连续正序列

void FindContinousSum(int sum)
{
    if (sum < 3)
        return ;
    
    int left = 1; 
    int right = 2;

    int mid = (1 + sum ) / 2;
    int cur = left + right;

    while(left < mid)
    {
        if (cur == sum)
        {
            for (int i = left; i <= right; i++)
            {
                cout << i << " ";
            }
        }

        else if (cur > sum)
        {
            cur -= left;
            left++; 
        }
        else
        {
            right ++;
            cur += sum;
        }
    }


}