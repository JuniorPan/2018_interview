#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void printMoreThanHalf(vector<int> nums)
{
    int time = 0;
    int cand = 0;
    
    for(int i = 0; i < nums.size(); i++)
    {
        if (time == 0)
        {
            cand = nums[i];
        }
        else if (cand == nums[i] )
        {
            time++;
        }
        else
        {
            time --;
        }
    }
    cout << cand;

}

int main()
{   

  
    return 0; 
}