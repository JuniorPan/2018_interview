#include <iostream>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 递归序
void pre_order(TreeNode *root)
{
    if (root == nullptr)
        return;
    // 第一次来到当前节点
    cout << root->val << ", ";
    pre_order(root->left);
    // 第二次来到当前节点
    cout << root->val << ", ";
    pre_order(root->right);
    // 第三次来到当前节点
    cout << root->val << ", ";
}

int main()
{
    TreeNode t1 = TreeNode(1);
    TreeNode t2 = TreeNode(2);
    TreeNode t3 = TreeNode(3);
    TreeNode t4 = TreeNode(4);
    TreeNode t5 = TreeNode(5);
    TreeNode t6 = TreeNode(6);
    TreeNode t7 = TreeNode(7);

    t1.left = &t2;
    t1.right = &t3;

    t2.left = &t4;
    t2.right = &t5;

    t3.left = &t6;
    t3.right = &t7;

    t4.left = nullptr;
    t4.right = nullptr;
    t5.left = nullptr;
    t5.right = nullptr;
    t6.left = nullptr;
    t6.right = nullptr;
    t7.left = nullptr;
    t7.right = nullptr;

    pre_order(&t1);

    



    return 0;
}
