/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (46.43%)
 * Likes:    5001
 * Dislikes: 119
 * Total Accepted:    753.2K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Follow up: Solve it both recursively and iteratively.
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
    bool isSymmetricTree(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return true;

        if (!root1 || !root2)
            return false;

        if (root1 && root2)
        {
            return root1->val == root2->val && isSymmetricTree(root1->left, root2->right) && isSymmetricTree(root1->right, root2->left);
        }
        else
        {
            return false;
        }
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;

        return isSymmetricTree(root->left, root->right);
    }
};
// @lc code=end
