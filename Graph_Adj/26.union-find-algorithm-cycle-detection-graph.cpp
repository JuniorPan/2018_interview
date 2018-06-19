//
//  Filename: 26.union-find-algorithm-cycle-detection-graph
//  Project: Graph_Adj
//
//  Created by panqiang on 2018/4/11 by CLion
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int Parent[13];


int findSet(int x)
{

    if(Parent[x] == -1){
        return x; // x is root
    }
    return findSet(Parent[x]);

}

void UnionSet(int x, int y){

    int xp = findSet(x);
    int yp = findSet(y);
    Parent[xp] = yp;

}


int main()
{


//    int N, E;
//    cin >> N >> E; // 节点数和边数
    int E = 12;
    int N = 13;
    int E1[12] = {1,1,1,2,2,3,3,8,8,9,9,11};
    int E2[12] = {2,7,8,3,6,4,5,9,12,10,11,12};
//    int E1[12] = {1,1,2,3};
//    int E2[12] = {2,3,3,4};
//    int v1,v2;
//    for(int i = 0; i < E; i++){
//        cin >> v1 >> v2;
//        E1[i] = v1;
//        E2[i] = v2;
//    }

    for(int i = 0; i < E; i++)
    {
        cout << "E1: " << E1[i] << " " ;
    }
    cout << endl;

    for(int i = 0; i < E; i++)
    {
        cout << "E2: " << E2[i] << " " ;
    }
    cout << endl;


    for(int i = 1; i < N; i++)
    {
        Parent[i] = -1;
    }

    for(int i = 1; i < N; i++)
    {
        cout << Parent[i]  << " ";
    }
    cout << endl;
//
    for(int i = 0; i < E; i++)
    {
        int v = E1[i];
        int w = E2[i];

        int xp = findSet(v);
        int yp = findSet(w);

        if (xp == yp)
        {
            cout << "未合并前同根，说明有环。" << endl;
            cout << "xp: " << xp << endl;
            cout << "v: " << v << endl;
            cout << "w: " << w << endl;

            for(int k = 1; k < N; k++)
            {
                cout << Parent[k]  << " ";
            }
            cout << endl;
            cout << "findSet(v): " << findSet(v) << endl;
            cout << "findSet(w): " << findSet(w) << endl;
            return 1;
        }
        UnionSet(v,w);
    }




    cout << "无环" << endl;


    return 0;

}