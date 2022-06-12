#include <iostream>
#include <vector>
using namespace std;


bool Find(int target, vector<vector<int> > array)
{
    if (array.empty())
        return false;
    
    int m = array.size();  // 行数
    int n = array[0].size(); // 列数
    
    int row = 0;
    int col = n -1;
    while (col >= 0 && row < m)
    {
        if (array[row][col] == target)
        {
            return true;
        }
        else if (array[row][col] > target)
        {
            col--;
        }
        else
        {
            row++;
        }
    }
    return false;
}