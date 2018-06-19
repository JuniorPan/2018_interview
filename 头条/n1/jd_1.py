#  -*- coding:utf-8 -*-
#  Filename: jd_1
#  Project: 头条
#
#  Created by panqiang on 2018/4/9 by PyCharm
#  Copyright © 2018年 panqiang. All rights reserved.


import sys

if __name__ == "__main__":
    # 读取第一行的n
    n = int(sys.stdin.readline().strip())
    ans = 0
    nums = []
    for i in range(n):
        line = sys.stdin.readline().strip()
        print line
        nums.append(int(line))

print nums