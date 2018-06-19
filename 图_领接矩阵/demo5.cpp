//
//  Filename: demo5.cpp
//  Project: _
//
//  Created by panqiang on 2018/4/2 by CLion
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include<iostream>
#include <algorithm>
using namespace std;

int repeat(int pos, int *arr[5], int bomb,int place,int n,int coins)
{ //System.out.println(pos+" "+place+" "+bomb+" "+coins);
    if(pos < 0 || place >= 5 || place<0)
        return coins;

    if(pos!=n){
    if(arr[pos][place]==2)
    {
        return coins;
    }
    if(arr[pos][place]==1)
        coins++;
    }

    // int **brr=new int[n][n];
    // int brr[6][5];
    int **brr= new int*[6];
    for(int i = 0; i < 6; i++)
    {
        brr[i] = new int[5];

    }
    if(bomb==1)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<5;j++)
            {
                brr[i][j]=arr[i][j];
            }
        }
        int count=5;
        int index=pos;
        while(index-- > 0 && count-- > 0)
        {
            for(int j=0;j<5;j++)
            {
                if(brr[index][j]==2)
                {
                    brr[index][j]=0;
                }
            }
        }

    }


    if(bomb==1)
    {
        int position=pos-1;
        int nm=place;
        int lm=place-1;
        int rm=place+1;
        int x=repeat(position,arr,1,lm, n,coins);
        int y=repeat(position,arr,1,nm, n,coins);
        int z=repeat(position,arr,1,rm,n,coins);
        int a=repeat(position,brr,0,lm,n,coins);
        int b=repeat(position,brr,0,nm,n,coins);
        int c=repeat(position,brr,0,rm,n,coins);
        int d=max(max(max(x, y), max(z, a)),max(b, c));
        return d;
    }
    else
    {
        int position=pos-1;
        int nm=place;
        int lm=place-1;
        int rm=place+1;
        int z=max(repeat(position,arr,0,lm,n,coins), repeat(position,arr,0,nm,n,coins));
    return max(z, repeat(position,arr,0,rm,n,coins));

    }



}


int main()
{
    int **arr= new int*[6];


	int ans=0;

    for(int i = 0; i < 6; i++)
    {
        arr[i] = new int[5];
        for(int j=0;j<5;j++)
            cin>>arr[i][j];

    }

    // int arr[6][5] =
    // {
    //     {0,1,0,2,0},
    //     {0,2,2,2,1},
    //     {0,2,1,1,1},
    //     {1,0,1,0,0},
    //     {0,0,1,2,1},
    //     {1,1,0,0,1},
    // };

       cout << repeat(6,arr,1,2,6,0);
    }

