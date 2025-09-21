
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
    bool Tree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot2 == nullptr)
            return true;
        if (pRoot1 == nullptr)
            return false;
        
        if (pRoot1->val != pRoot2->val)
            return false;
        
        return Tree1HasTree2(pRoot1->left, pRoot2->left) && Tree1HasTree2(pRoot1->right, pRoot2->right);
    }
    
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == nullptr)
            return false;
        if (pRoot2 == nullptr)
            return false;
        
        else
            return Tree1HasTree2(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    } 
};