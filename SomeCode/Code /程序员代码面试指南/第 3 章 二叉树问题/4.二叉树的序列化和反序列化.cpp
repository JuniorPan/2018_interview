#include "../../generateRandomArray.h"

typedef struct TreeNode
{
	int val;
	struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;


TreeNode* de(istringstream& iss)
{
    TreeNode* root = NULL;
    string word;
    if (iss >> word && word != "#") {
        root = new TreeNode(stoi(word));
        root->left = de(iss);
        root->right = de(iss);
    }
    return root;
}

string serialize(TreeNode* root)
 {
    if (root == NULL)
    {
        return "#";
    }
    else
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    
    
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data)
 {
    istringstream iss(data);
    return de(iss);
}


void morrisInOrder(TreeNode *root)
{
    if (root == nullptr)
        return ;
    TreeNode *cur1 = root;
    TreeNode *cur2 = nullptr;

    while(cur1)
    {
        cur2 =cur1->left;
        if (cur2)
        {
            while(cur2->right && cur2->right != cur1)
            {
                cur2 = cur2->right;
            }
            if(cur2->right == nullptr)
            {
                cur2->right = cur1;
                cur1 = cur1->left;
                continue;
            }

            else
            {
                cur2->right = nullptr;
            }
        }

        cout << cur1->val << " "; 
        cur1 = cur1->right;
    }
}

int main()
{
    string s = "1 2 # 4 # # 3 5 # # #";

    TreeNode *root = deserialize(s);
    cout << serialize(root) << endl;
    morrisInOrder(root);
    return 0;
}