#  -*- coding:utf-8 -*-
#  Filename: 360_2
#
#  Created by panqiang on 2018/4/3 by PyCharm
#  Copyright © 2018年 panqiang. All rights reserved.


count = int(raw_input())

n_list = []
v_list = []

for i in range(count * 2):
    if (i % 2 == 0):
        n = int(raw_input())
        n_list.append(n)
    else:
        v_l = [int(x) for x in raw_input().strip().split()]
        v_list.append(v_l)


res = []

for (n, v_l) in zip(n_list, v_list):

    print n, v_l
    v_l.sort()
    print n, v_l
    if (v_l[n-1] < v_l[n]):
        res.append("YES")
    else:
        res.append("NO")

for r in res:
    print r