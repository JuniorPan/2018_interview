#  -*- coding:utf-8 -*-
#  Filename: jd1
#  Project: untitled
#
#  Created by panqiang on 2018/4/9 by PyCharm
#  Copyright © 2018年 panqiang. All rights reserved.


import sys

n = int(sys.stdin.readline().strip())
ans = 0
nums = []
for i in range(n):
    line = sys.stdin.readline().strip()
    nums.append(int(line))


res =[]
for n in nums:
    if (n%2 == 1):
        print("No")
    else:
        a = n / 2
        while(a % 2 == 0 ):
            a = a / 2
        b = n / a
        c = n / b
        print c, b

