#  -*- coding:utf-8 -*-
#  Filename: t4
#  Project: 头条
#
#  Created by panqiang on 2018/3/24 by PyCharm
#  Copyright © 2018年 panqiang. All rights reserved.


intput= raw_input().split(' ')

intput = [int(x) for x in intput]
a = intput[0]
b = intput[1]



set1 = set([int(x) for x in raw_input().split(' ')])
set2 = set([int(x) for x in raw_input().split(' ')])


def mean(a):
    return sum(a) / len(a)

count = 0
len = len(set1)
for i in range(len):
    ma1 = mean(set1)
    a = set1.pop()
    ma2_1 = mean(set1)

    ma2 = mean(set2)
    set2.add(a)
    ma2_2 = mean(set2)
    if (ma2_2 > ma2 and ma2_1 > ma1):
        count += 1

print count