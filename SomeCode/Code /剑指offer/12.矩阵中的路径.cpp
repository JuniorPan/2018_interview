#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int row,col;
    bool haspath(char* matrix, int rows, int cols, char* str)
    {
        row = rows;
        col = cols;
        vector<int> visted(row*col,0);
        for(int i = 0; i < rows; i++)
            for(int j = 0 ; j < cols; j++)
            {
                if (dfs(matrix,visted,i,j,str))
                {
                    return true;
                }     
            }
        return false;
    }

    bool dfs(char* matrix, vector<int> &visted ,int i, int j, char* str)
    {
        // 如果不满足条件直接返回
        if(i<0||j<0||i>=row||j>=col)//越界
            return false;
        
        if (matrix[i*col+j] != *str || visted[i*col+j] != 0)
            return false;
             
        visted[i*col+j] = 1;
        if(*(str+1) == 0)
            return true;
        bool flag = dfs(matrix,visted,i,j+1,str+1)||
                    dfs(matrix,visted,i+1,j,str+1)||
                    dfs(matrix,visted,i-1,j,str+1)||
                    dfs(matrix,visted,i,j-1,str+1);
        if(flag == false)
            visted[i*col+j] = 0;
        return flag;
        
    }
};