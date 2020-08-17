/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (55.18%)
 * Likes:    4094
 * Dislikes: 123
 * Total Accepted:    560.2K
 * Total Submissions: 997.3K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * Each element of candidate is unique.
 * 1 <= target <= 500
 * 
 * 
 */

// @lc code=start
class Solution
{
public:

    vector<vector<int>> res;
    vector<int> temp;
    void dfs(vector<int> &candidates, int target, int start)
    {

        if (target < 0)
            return;
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            temp.push_back(candidates[i]); // 添加当前数
            dfs(candidates, target - candidates[i], i); // 接着往下遍历
            temp.pop_back(); // 弹出当前数,
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }
};
// @lc code=end
