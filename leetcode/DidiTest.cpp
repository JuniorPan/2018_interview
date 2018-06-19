//
//  DidiTest.cpp
//  leetcode
//
//  Created by panqiang on 2018/3/15.
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;


void swap_2(string &s, int i, int j)
{
    int n = j-i+1;
    
    for(int k = i; k < n/2; k++)
    {
        char temp = s[k];
        s[k] = s[n-k-1];
        s[n-k-1] = temp;
    }
}

int findLength(vector<int>& A, vector<int>& B) {
    
    int n1 = int(A.size());
    int n2 = int(B.size());
    
    int dp[n1][n2] = {0};
    int m = 0;
    dp[0][0] = 0;
    int i = 0;
    for(i = 0 ; i <= n1; i++)
    {
        if (A[i] == B[0])
            break;
    }
    for(int k = i; k < n1; k++)
    {
        dp[0][k] = 1;
    }
    
    int j = 0;
    for(j = 0 ; j < n2; j++)
    {
        if (A[0] == B[j])
            break;
    }
    for(int k = j; k < n2; k++)
    {
        dp[k][0] = 1;
    }
    
    
    
    
    for(i = 1; i < n1; i++)
    {
        for(j = 1; j < n2; j++)
        {
//            if (A[i] == B[j])
//                dp[i][j] = dp[i-1][j-1] + 1;
//            else
//                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//            m = max(m, dp[i][j]);
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return m;
}

int main()
{
    vector<int> A = {0,0,0,0,1};
    vector<int> B = {1,0,0,0,0};
    findLength(A,  B);
    
    
    return 0;
}


int maindd()
{
    
    string s = " pan qiang ";
    
    
    int i = 0;
    int j = 0;
    int n = int(s.length());
    for(int k = 0; k < n; k++)
    {
        if (s[k] != ' ' )
        {
            j++;
        }
        else
        {
            cout << "i: " << i << endl;
            cout << "j: " << j << endl;
            
           
            swap_2(s, i, j-1);
            i = j;
            j = j+1;
            
        }
    }
    
    cout << s << endl;
    
    
    return 0;
}
