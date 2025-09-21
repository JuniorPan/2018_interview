#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

int FindUgly(int n) //    
{       
    int* ugly = new int[n];       
    ugly[0] = 1;       
    int index2 = 0;       
    int index3 = 0;       
    int index5 = 0;       
    int index = 1;       
    while (index < n)       
    {       
        int val = min(ugly[index2]*2, min(ugly[index3]*3, ugly[index5]*5)); //竞争产生下一个丑数 （最小）      
        if (val == ugly[index2]*2) //将产生这个丑数的index*向后挪一位；      
            ++index2;       
        if (val == ugly[index3]*3)   //这里不能用elseif，因为可能有两个最小值，这时都要挪动；    
            ++index3;       
        if (val == ugly[index5]*5)       
            ++index5;       
        ugly[index++] = val;       
    } 

    return ugly[n-1];
}

int nthUglyNumber(int n)
 {
        vector<int> ugly(n, 0);       
        ugly[0] = 1;       
        int index2 = 0;       
        int index3 = 0;       
        int index5 = 0;       
        int index = 1;       
        while (index < n)       
        {       
            int val = min(ugly[index2]*2, min(ugly[index3]*3, ugly[index5]*5)); //竞争产生下一个丑数 （最小）      
            if (val == ugly[index2]*2) //将产生这个丑数的index向后挪一位；      
                ++index2;       
            if (val == ugly[index3]*3)   //这里不能用elseif，因为可能有两个最小值，这时都要挪动；    
                ++index3;       
            if (val == ugly[index5]*5)       
                ++index5;       
            ugly[index++] = val;       
        } 

        return ugly[n-1];
    }

int main()
{
    cout << FindUgly(100) << endl;
    return 0;
}