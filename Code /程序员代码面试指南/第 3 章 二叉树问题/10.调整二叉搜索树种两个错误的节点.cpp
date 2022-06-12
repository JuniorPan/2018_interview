#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <vector>
#include <queue>
using namespace std;



typedef struct TreeNode
{
	int val;
	struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;


int pos = 0;  
string nextString(string src)
{  
    string result;  
    if(pos < src.length())
    {  
        if(src[pos] == ' ')
        {  
            pos++;  
        }  
        while(src[pos] != ' ')
        {  
            result += src[pos];  
            pos++;  
        }  
        return result;  
    }  
    return nullptr;
} 
int str2int(string strsrc)
{  
    return atoi(strsrc.c_str());  
}  
//反序列化，根据字串先序遍历的特点       
TreeNode *deserialize(string data)
 {  
    // write your code here  
    string cur = nextString(data);  
    if(cur == "#")
    {  
        return nullptr;  
    }else
    {  
        TreeNode *root = new TreeNode(str2int(cur));  
        root -> left = deserialize(data);  
        root -> right = deserialize(data);  
        return root;  
    }  
}  


// void inOrderTraverse(TreeNode* &root, TreeNode* &pre,TreeNode* &first,TreeNode* &second)
// {
//     if (root == nullptr)
//         return;

//     stack<TreeNode*> s;
    
//     while(!s.empty() || root)
//     {
//         if(root)
//         {
//             s.push(root);
//             root = root->left;
//         }
//         else
//         {
//             root = s.top();
//             s.pop();
            
//             if (pre != nullptr && pre->val > root->val)
//             {
//                 first = first == nullptr ? pre : first;
//                 second = root;
//             }
//             root = root->right;
//         }
//     }
// }


// void recoverTree(TreeNode* root)
// {
            
//     TreeNode *first = nullptr; 
//     TreeNode *second = nullptr;
//     TreeNode *pre = nullptr;
//     inOrderTraverse(root, pre, first, second);
    
//     int temp = first->val;
//     cout << "temp";
//     second->val = first->val;
//     first->val = temp;
    
// }

void preOrder(TreeNode *root)
{
    if (root != nullptr)
    {
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{   
    string str = "3 5 1 # # # 2 4 # # #";
    TreeNode *root = deserialize(str);
    preOrder(root);

    // recoverTree(root);
  
    return 0; 
}