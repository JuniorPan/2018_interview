#include "../../generateRandomArray.h"


int maxSubMatrix(vector<vector<int>> &matrix)
{
    int res = INT_MIN;
    int cur = 0;

    if (matrix.size() < 0 || matrix[0].size() < 0)
        return 0;

    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> help(n, 0);

    for(int i = 0; i < m; i++) // i， j 用来控制行 
    {
        vector<int> help(n,0);
        for(int j = i; j < m; j++)
        {
            cur = 0;
            for(int k = 0; k < help.size(); k++)
            {
                help[k] += matrix[j][k];
                cur += help[k];
                res = max(cur, res);
                cur = cur > 0 ? cur : 0;
            }
        }
    }
    return res;

}

int main()
{


    return 0;
}