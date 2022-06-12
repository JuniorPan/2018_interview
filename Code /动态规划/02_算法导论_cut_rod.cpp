//
// Created by panqiang on 2018/1/8.
//

#include<cstdio>
#include<iostream>
using namespace std;




int cud_rod_1(int *p, int n)
{
    int r[10] = {-1};
    r[0] = 0;

    for (int j = 0; j < n; j++)
    {
        int q = -1;
        for (int i = 0; i <= j; i++)
        {
            q = max(q, p[i] + r[j-i-1]);
        }
        r[j] = q;
    }

    return r[n-1];
}


void cud_rod_2(int *p,  int n)
{
    int r[n];
    int s[n];
    r[0] = 0;

    for (int j = 0; j < n; j++)
    {

        int q = -128;
        for (int i = 0; i < j+1; i++)
        {
//            cout << "j: " << j << " i： " << i << endl;
            if (q < p[i] + r[j-i-1])
            {

                q = p[i] + r[j-i-1];
                s[j] = i;

            }

        }
        r[j] = q;
    }

    cout << r[n-1] << endl;

//    for (int i = 0; i < n; i++)
//    {
//        cout << "i: "  << s[i] << endl;
//    }

//    while( n > 0)
//    {
//        cout << s[n-1] << endl;
//        n = n - s[n-1];
////        cout << "n: " << n << endl;
//    }

    for (int j = n-1; j > 0; j -= s[j]+1)
    {
        cout << s[j] << endl;
    }
}


int main2()
{
    int seq[10] = {1,5,8,9,10,17,17,20,24,30};


    cud_rod_2(seq, 8);



//    cout << cud_rod_1(seq, 10) << endl;


    return 0;
}