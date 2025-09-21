#include <iostream>
#include <string>
#include <vector>
using namespace std;


void multiply(string s1, string s2) 
{

    int m = s1.length();
    int n = s2.length();
    vector<int> res(m + n , 0);


    for(int i = m-1; i >= 0; i--)
    {
        for(int j = n-1; j >= 0; j--)
        {
            res[i+j+1] += (s1[i] - '0') * (s2[j] - '0' );

            res[i+j] += res[i+j+1] / 10;
            res[i+j+1] = res[i+j+1] % 10; 
        }
    }

    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        
    }
    cout << endl;


}


int main()
{

    string s1 = "12";
    string s2 = "34";
    multiply(s1, s2);


    return 0;
}