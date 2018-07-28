#include <iostream>
#include <vector>
using namespace std;


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