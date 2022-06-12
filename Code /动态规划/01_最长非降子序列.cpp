//
// Created by panqiang on 2018/1/4.
//

#include<cstdio>
#include<iostream>
using namespace std;


int main1()
{
    int seq[10] = {4,5,7,8,3,2,6,7,33,4};
    int opt[10], i, j, max = 0;

    for (i = 0; i < 10; i++)
        opt[i] = 0;


    opt[0] = 1;

    for (i = 1; i < 10; i++)
    {
        opt[i] = 1;
        for (j = 0; j < i; j++)
        {
            if (seq[j] <= seq[i] && opt[j] + 1 > opt[i])
            {
                opt[i] = opt[j] + 1;
            }
        }
    }
    for(i=0; i<10; i++)
        if(opt[i] > max)
            max = opt[i];
    printf("max:%d\n", max);

    return 0;
}