#include "../../generateRandomArray.h"

int maxSum(vector<vector<int> > matrix)
{
    if (matrix.empty())
        return 0;
    int m = matrix.size();
    int n = matrix[0].size();

    int max_v = INT_MIN;
    int cur = 0;
    vector<int> help(n, 0);
    for(int i = 0; i < m; i ++)
    {
        vector<int> help(n, 0);
        for(int j = i; j < m; j++)
        {
            cur = 0;
            for(int k = 0; k < n; k++)
            {
                help[k] += matrix[j][k];
                cur += help[k];
                max_v = max(max_v, cur);
                cur = cur > 0 ? cur : 0;
            }
        }
    }
    return max_v;
}


int main()
{




    return 0;
}