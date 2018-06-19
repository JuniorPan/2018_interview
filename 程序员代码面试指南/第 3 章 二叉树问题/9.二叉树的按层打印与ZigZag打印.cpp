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


void printByLevel(TreeNode *root)
{
    if (root == nullptr)
        return ;
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;

    TreeNode *last = root;
    TreeNode *nlast = nullptr;
    cout << "\nlevel: " << ++level << ": ";
    while(!q.empty())
    {
        root = q.front();
        q.pop();
        cout << root->val << " ";
        if (root->left)
        {
            q.push(root->left);
            nlast = root->left;
        }

        if (root->right)
        {
            q.push(root->right);
            nlast = root->right;
        }

        if (root == last && !q.empty())
        {
            cout << "\nlevel: " << level << ": ";
            level ++;
            last = nlast;
            
            
        }
    }


}

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

int main()
{   
    string str = "1 2 # 4 # # 3 5 # # # # ";
    TreeNode *root = deserialize(str);
    // preOrder(root);

    printByLevel(root);
    
    return 0; 
}