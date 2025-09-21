#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

void dfs(vector<int>& nums, int start, vector<int> &temp, vector<vector<int>> &res)
{
    if (temp.size() > 1)
    {
        res.push_back(temp);
    }
    
    unordered_set<int> hash;
    for(int i = start; i < nums.size(); i++)
    {
        if((temp.empty() || nums[i] >= temp.back()) && hash.find(nums[i]) == hash.end())
        {
            temp.push_back(nums[i]);
            dfs(nums, i+1, temp, res);
            temp.pop_back();
            hash.insert(nums[i]);
        }
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums)
{
    vector<vector<int>> res;
    vector<int> curseq;
    dfs(nums,0,curseq,res);
    return res;
}


int main(int argc, const char * argv[])
{
    cout << "hello world" << endl;
    return 0;
}