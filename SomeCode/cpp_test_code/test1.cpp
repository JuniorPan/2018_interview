#include <iostream>
#include <vector>

using namespace std;


int main()
{

    vector<int> nums = {1,2,3,4,5};

    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = i+1; j < nums.size(); j++)
        {
            cout << " " << nums[i] << "-->" << nums[j] << endl;
        }
    }


    return 0;
}