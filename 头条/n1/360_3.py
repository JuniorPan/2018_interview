#  -*- coding:utf-8 -*-
#  Filename: 360_3
#  Project: 头条
#
#  Created by panqiang on 2018/4/3 by PyCharm
#  Copyright © 2018年 panqiang. All rights reserved.


# dp[n][m]=m*dp[n-1][m]+dp[n-1][m-1],1<=m<n
# dp[k][n]=n*dp[k-1][n]+dp[k-1][n-1],1<=n<k
# dp[k][k]=1,k>=0
# dp[k][0]=0,k>=1






def f(m, n):
    if n == 0:
        return 0
    if n == 1:
        return 1;
    if m == n:
        return 1;
    if m < n:
        return 0;
    return n * f(m - 1, n) + f(m - 1, n - 1)

def fact(x):
    result = 1
    for i in xrange(2, x + 1):
        result *= i
    return result

def c_n_k(n, k):
    return (fact(n) / (fact(k) * fact(n-k)))

l = [int(x) for x in raw_input().strip().split()]

n = l[0]
k = l[1]

print f(n,k) * fact(k)






