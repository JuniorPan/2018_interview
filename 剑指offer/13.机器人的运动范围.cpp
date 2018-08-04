#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    int getsum(int num)
        {
        int sum = 0;
        while(num)
            {
            sum += num % 10;
            num /= 10;
              
        }
        return sum;
    }
    
    int dfs(int rows, int cols, int i, int j, int k, vector<int> &visted)
    {
        // 如果不满足条件直接返回
        if (i < 0 || j < 0 || i >= rows || j >= cols  || visted[i*cols + j] == 1 || getsum(i) + getsum(j) > k)
            return 0;
        int count = 0;
        visted[i*cols + j] = 1;
        count  = 1 + dfs(rows, cols, i + 1, j, k, visted) + 
                     dfs(rows, cols, i, j+1, k, visted) + 
                     dfs(rows, cols, i-1, j, k, visted) + 
                     dfs(rows, cols, i, j-1, k, visted);
        
        return count;
    }
    
    
    int movingCount(int threshold, int rows, int cols)
    {
        
        vector<int> visted(cols*rows, 0);
        return dfs(rows, cols, 0,0,threshold,  visted);
        
    }
};