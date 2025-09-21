#include <stdio.h>
#include <stdio.h>
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
        temp.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], temp, res, i);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> tmp;
    dfs(candidates, target, tmp, res, 0);
    return res;
}

int main()
{
    vector<int> candidates = {10,1,2,7,6,5};
    vector<vector<int>> res;
    int target = 8;

    res = combinationSum(candidates, target);

    for (auto vec :res)
    {
        for(int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}