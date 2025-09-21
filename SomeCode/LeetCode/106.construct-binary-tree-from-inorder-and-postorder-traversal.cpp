/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (48.56%)
 * Likes:    2207
 * Dislikes: 42
 * Total Accepted:    265K
 * Total Submissions: 545.7K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode *buildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd)
    {
        if (postStart > postEnd ||inStart > inEnd )
            return nullptr;

        TreeNode *root = new TreeNode(postorder[postEnd]);

        int i = find(inorder.begin(), inorder.end(), postorder[postEnd]) - inorder.begin();
        root->left = buildTree(inorder, inStart, i - 1, postorder, postStart, i+ postStart-inStart-1 ); // 左子树
        root->right = buildTree(inorder, i+1 ,inEnd, postorder, i+postStart-inStart, postEnd-1);  // 右子树

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return buildTree(inorder,0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
// @lc code=end
