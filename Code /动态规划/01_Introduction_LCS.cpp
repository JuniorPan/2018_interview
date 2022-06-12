//
//  01_Introduction_LCS.cpp
//  动态规划
//
//  Created by panqiang on 2018/1/11.
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


int LCSLength(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (x[m-1] == y[n-1])
        return LCSLength(x, y, m-1, n-1) + 1;
    else
        return max(LCSLength(x, y, m-1, n), LCSLength(x, y, m, n-1));
}

int LCSLength_2(string X, string Y, int m, int n, unordered_map<string, int> &lookup)
{
    // return if we have reached the end of either string
    if (m == 0 || n == 0)
        return 0;
    
    // construct a unique map key from dynamic elements of the input
    string key = to_string(m) + "|" + to_string(n);
    cout << "key: " << key << endl;
    
    // if sub-problem is seen for the first time, solve it and
    // store its result in a map
    if (lookup.find(key) == lookup.end()) // 在map中没找到
    {
        // if last character of X and Y matches
        if (X[m - 1] == Y[n - 1])
        {
            lookup[key] = LCSLength_2(X, Y, m - 1, n - 1, lookup) + 1;
            cout << "lookup[" << key << "]: " << lookup[key] << endl;
        }
        
        
        else
            // else if last character of X and Y don't match
            lookup[key] = max(LCSLength_2(X, Y, m, n - 1, lookup),
                              LCSLength_2(X, Y, m - 1, n, lookup));
    }
    
    // return the subproblem solution from the map
    
    
    return lookup[key];
}




int main()
{
    string x = "abcbdab";
    string y = "bdcaba";
//    cout << LCSLength(x, y, x.length(), y.length()) << endl;
//
    unordered_map<string, int> lookup;
    cout << LCSLength_2(x, y, 7, 6, lookup) << endl;
    
    
    
    return 0;
}
