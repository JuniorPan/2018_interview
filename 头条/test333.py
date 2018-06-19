#  -*- coding:utf-8 -*-
#  Filename: test333
#  Project: 头条
#
#  Created by panqiang on 2018/3/27 by PyCharm
#  Copyright © 2018年 panqiang. All rights reserved.

l = 12
path = list('...XX.....XX')

# l = 3
# path_list = list('.X.')


dp = [0] * l

if path[0] != 'X':
    dp[0] = 0
else:
    dp[0] = 1


if path[1] == 'X':
    dp[1] = dp[0]
else:
    dp[1] = 1

for i in range(2,l):
    print i
    if path[i] != 'X':
        dp[i] = min(dp[i-1]+1, dp[i-2]+1)
    else:
        dp[i] = min(dp[i-1], dp[i-2])



print dp