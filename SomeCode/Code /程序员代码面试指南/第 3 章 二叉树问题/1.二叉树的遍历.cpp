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
 
//  string int2str(int intsrc)
//  {  
//     stringstream ss;  
//     ss << intsrc;  
//     return ss.str();  
// }  
// //序列化代码，先序遍历的顺序进行序列化      
// string serialize(TreeNode *root)
//  {  
//     // write your code here  
//     string sec;  
//     if(root == nullptr)
//     {  
//         sec += "# ";  
//     }else
//     {  
//         sec += int2str(root->val);  
//         sec += " ";  
//         sec += serialize(root->left);  
//         sec += serialize(root->right);  
//     }  
//     return sec;  
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



void inOrderTraverse(TreeNode *root) // 中序遍历非递归
{
    if(!root)
        return;
    stack<TreeNode *> s;

    while(!s.empty() || root)
    {
        if (root)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            root = s.top();
            cout << root->val << " ";
            s.pop();
            root = root->right;
        }
    }
    cout << endl;
}


// 倒着层次遍历 递归方式
void levelOrder(vector<vector<int> > &ans, TreeNode *node, int level) 
{
    if (!node)
        return;
    ans[level].push_back(node->val);
    levelOrder(ans,node->left,level-1);
    levelOrder(ans,node->right,level-1);
}


// 利用两个栈对二叉树实现后续遍历非递归
vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> res;
    if (root == nullptr)
        return res;
    
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;
    s1.push(root);
    while(!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);
        
        if (root->left)
            s1.push(root->left);
        if (root->right)
            s1.push(root->right);
    }
    while(!s2.empty())
    {
        res.push_back(s2.top()->val);
        s2.pop();
    }
    return res;
}

// 二叉树前序遍历非递归方式
vector<int> preorderTraversal(TreeNode* root) 
{
    vector<int> res;
    if (root == nullptr)
        return res;
    
    stack<TreeNode *> s;
    s.push(root);
    
    while(!s.empty())
    {
        root = s.top();
        s.pop();
        res.push_back(root->val);
        
        if (root->right)
            s.push(root->right);
        if (root->left)
            s.push(root->left);  
    }
    return res;
}


int levelOrder(TreeNode *root, int d)
{
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    TreeNode *last = root;
    TreeNode *nlast = nullptr;
    int res;
    while(!q.empty())
    {
        root = q.front();
        q.pop();
        
        if (level == d-1)
            return root->val;
        
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
            
        
        if(root == last && !q.empty())
        {
            level ++;
            last = nlast;
        }
    }
    
    return res;
    
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
void inOrderTraverse(TreeNode* &root, TreeNode* &pre,TreeNode* &first,TreeNode* &second)
{
    
}


void recoverTree(TreeNode* root)
{
            
    TreeNode *first = nullptr; 
    TreeNode *second = nullptr;
    TreeNode *pre = nullptr;
    if (root == nullptr)
        return;

    stack<TreeNode*> s;
    
    while(!s.empty() || root)
    {
        if(root)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            root = s.top();
            s.pop();
            cout << root->val << endl;
            
            if (pre != nullptr && pre->val > root->val)
            {
                first = first == nullptr ? pre : first;
                second = root;
            }
            pre = root;
            root = root->right;
        }
    }
    
    int temp = first->val;
    cout << "temp";
    second->val = first->val;
    first->val = temp;
    
}

int maxDistance(TreeNode *root, int nMaxdist)
{   
    if (root == nullptr)
        return -1;
    int l = maxDistance(root->left, nMaxdist) + 1;
    int r = maxDistance(root->right, nMaxdist) + 1;

    int dist = l+ r;
    nMaxdist = max(dist, nMaxdist);

    return l > r ? l: r ;
}


int main()
{   
    // string str = "1 2 # 4 # # 3 5 # # # # ";
    string str = "3 5 1 # # # 2 4 # # # ";
    TreeNode *root = deserialize(str);
    // preOrder(root);
    inOrderTraverse(root);
    recoverTree(root);
    inOrderTraverse(root);
    // morrisInOrder(root);

    // cout << levelOrder(root, 3);
    
    return 0; 
}