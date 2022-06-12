#include <iostream>
using namespace std;

// 改进的版本  
// int HeightOfBinaryTree(BinaryTreeNode*pNode, int&nMaxDistance){  
//     if (pNode == NULL)  
//         return 0;   //空节点的高度为-1  
//     //递归  
//     int nHeightOfLeftTree = HeightOfBinaryTree(pNode->m_pLeft, nMaxDistance);   //左子树的的高度 
//     int nHeightOfRightTree = HeightOfBinaryTree(pNode->m_pRight, nMaxDistance);   //右子树的高度  
//     int nDistance = nHeightOfLeftTree + nHeightOfRightTree + 1 ;    //距离等于左子树的高度加上右子树的高度+1  
//     nMaxDistance = nMaxDistance > nDistance ? nMaxDistance : nDistance;            //得到距离的最大值  
//     return nHeightOfLeftTree > nHeightOfRightTree ? nHeightOfLeftTree : nHeightOfRightTree;  
// }  