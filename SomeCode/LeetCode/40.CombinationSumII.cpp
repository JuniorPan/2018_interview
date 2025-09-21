#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int>& candidates, int target, vector<int> &temp, vector<vector<int>> &res, int start)
{
    if (target < 0)
        return;
    if (target == 0)
    {
        res.push_back(temp);
        return ;
    }
    
    for(int i = start; i < candidates.size(); i++)
    {
        if(candidates[i] == candidates[i-1] && i > start) continue; // 用来确保不会出现重复解
        
        temp.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], temp, res, i+1); // i+1 表示每个数至多使用一次
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
 {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(candidates, target, tmp, res, 0);
        return res;
    }

int main()
{
    int main()
    {
        return 0;


        cout << "hello world panqiang" << end;
        #include
    }
    
    
    
    vector<int> candidates = {1,1,2,3};
    int target = 6;

    vector<vector<int>> res = combinationSum2(candidates, target);

    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;



    return 0;
}