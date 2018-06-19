#  -*- coding:utf-8 -*-
#  Filename: zs1
#  Project: untitled
#
#  Created by panqiang on 2018/4/10 by PyCharm
#  Copyright © 2018年 panqiang. All rights reserved.


#coding=utf-8
import sys


nums = []
n = 2
ans = 0
for i in range(n):
    # 读取每一行
    line = sys.stdin.readline().strip()
    # 把每一行的数字分隔后转化成int列表
    values = map(int, line.split())
    nums.append(values)

x = nums[1][0]
k = nums[1][1]

arr = nums[0]

arr2 = [abs(num - x) for num in arr]

dir = {}

for (i, n) in enumerate(arr2):
    dir[i] = n

# print dir

dir = sorted(dir.items(), lambda x, y: cmp(x[1], y[1]), reverse=False)
res = []
for x in dir:
    if x[0] not in res and len(res) < k:
        res.append(x[0])

res.sort()
# print res
res = [arr[i] for i in res]
for r in res:
    print r,