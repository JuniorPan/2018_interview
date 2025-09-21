//
//  Filename: 6
//  Project: offer
//
//  Created by panqiang on 2018/1/22 by CLion
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
{



    int len = vin.size();

    if (len == 0)
        return NULL;

    vector<int> left_pre, right_pre, left_vin, right_vin;

    int rootValue = pre[0];

    TreeNode *rootNode = new TreeNode(rootValue);

    int index = 0;

    for(int i =0; i < vin.size(); i++)
    {
        if (vin[i] == pre[0])
        {
            index = i;
            break;
        }
    }

    cout << "index: " << index << endl;



    for(int i = 0; i < index; i++)
    {
        left_vin.push_back(vin[i]);
        left_pre.push_back(pre[i+1]);

    }

    for(int i = index+1; i < len; i++)
    {
        right_vin.push_back(vin[i]);
        right_pre.push_back(pre[i]);
    }


    rootNode->left = reConstructBinaryTree(left_pre, left_vin);
    rootNode->right = reConstructBinaryTree(right_pre, right_vin);

    return rootNode;
}



int main() {

    vector<int> pre = {1,2,3,4,5,6,7};
    vector<int> vin = {3,2,4,1,6,5,7};

    reConstructBinaryTree(pre, vin);

    cout << "hello world" << endl;
    return 0;
}