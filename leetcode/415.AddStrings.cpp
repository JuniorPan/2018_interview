#include <iostream>
#include <string>
#include <vector>
using namespace std;

void addStrings(string s1, string s2) 
{
    int i = s1.length()-1;
    int j = s2.length()-1;
    int add = 0;
    int cur = 0;
    string res = "";
    while(i >= 0 || j>=0  || add > 0)
    {
        int cur = add;
        cur += (i >= 0 ? s1[i] - '0' :0);
        cur += (j >= 0 ? s2[j] - '0': 0);
        i--;
        j--;
        add = cur / 10; //用来判断是否有进位
        cur %= 10;

        res += ('0'+cur);
    }

    reverse(res.begin(), res.end());
    cout << res << endl;

}

int main()
{

    string s1 = "567855768567856784678465735673452456";
    string s2 = "34057856567856787857567856785600";
    addStrings(s1, s2);


    return 0;
}