/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (62.48%)
 * Likes:    4158
 * Dislikes: 108
 * Total Accepted:    634.7K
 * Total Submissions: 997.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> temp;
    vector<bool> used;

    void dfs(vector<int> &nums, int start)
    {

        if (temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!used[i])
            {
                temp.push_back(nums[i]);
                used[i] = true;
                dfs(nums, i + 1);
                used[i] = false;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        dfs(nums, 0);
        return res;
    }
};
// @lc code=end
