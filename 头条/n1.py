#  -*- coding:utf-8 -*-
#  Filename: n1
#  Project: 头条
#
#  Created by panqiang on 2018/3/27 by PyCharm
#  Copyright © 2018年 panqiang. All rights reserved.


n = int(raw_input())

path_list = []
len_list = []

for i in range(n):
    len = int(raw_input())
    path = raw_input()
    len_list.append(len)
    path_list.append(path)




res = []
for (l,path) in zip(len_list, path_list):
    dp = [0] * l
    if path[0] != 'X':
        dp[0] = 0
    else:
        dp[0] = 1

    if path[1] == 'X':
        dp[1] = dp[0]
    else:
        dp[1] = 1

    for i in range(2, l):
        if path[i] != 'X':
            dp[i] = min(dp[i - 1] + 1, dp[i - 2] + 1)
        else:
            dp[i] = min(dp[i - 1], dp[i - 2])

    res.append(dp[-1])

for r in res:
    print r




