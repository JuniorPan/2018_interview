#  -*- coding:utf-8 -*-
#  Filename: 360_1
#  Project: 头条
#
#  Created by panqiang on 2018/4/3 by PyCharm
#  Copyright © 2018年 panqiang. All rights reserved.


# print 6 % 2
#-*- coding:utf-8
n = int(raw_input())


len_lista = []

for i in range(n):
    l = [int(x) for x in raw_input().strip().split()]
    len_lista.append(l)


res = []
for l in len_lista:
    if sum(l) % 5 == 0:
        res.append(sum(l) / 5)
    else:
        res.append(-1)

for r in res:
    print r



