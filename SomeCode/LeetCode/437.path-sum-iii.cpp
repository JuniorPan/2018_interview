/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (45.70%)
 * Likes:    4446
 * Dislikes: 312
 * Total Accepted:    236.4K
 * Total Submissions: 496.2K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 * 
 * Find the number of paths that sum to a given value.
 * 
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 * 
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 * 
 * Example:
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * Return 3. The paths that sum to 8 are:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // 本质上还是回溯
    void dfs(TreeNode *node, int sum, int curSum, vector<TreeNode *>& path, int &res)
    {
        if (!node)
            return;

        curSum += node->val;
        path.push_back(node);
        if (curSum == sum)
            res++;
        int t = curSum;
        for (int i = 0; i < path.size() - 1; ++i) {
            t -= path[i]->val;
            if (t == sum) ++res;
        }
        dfs(node->left, sum, curSum, path, res);
        dfs(node->right, sum, curSum, path, res);
        path.pop_back();
        
    }

    int pathSum(TreeNode *root, int sum)
    {
        int res = 0;
        vector<TreeNode*> path;
        dfs(root, sum, 0, path, res);
        return res;
    }
};
// @lc code=end
