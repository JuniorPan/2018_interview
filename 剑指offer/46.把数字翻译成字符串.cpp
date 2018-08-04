#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int numDecodings(string s) {
        
        int n = s.size();
    
        if (n <= 0  || s[0] == '0')
            return 0;
    
        int dp[n+1];
        dp[0] = 1;
    
        dp[1] = s[0] != '0' ? 1 : 0;
    
        for(int i = 2; i <= n; i++)
        {
            int d1 = s[i-1] - '0';
            int d2 = s[i-2] - '0';
            int num = d2*10 + d1;
            if(d1 >= 1 && d1 <= 9) {
               dp[i] = dp[i-1];  
            }
            if(num >= 10 && num <= 26) {
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }


 int main()
 {

     string s = "128";
     cout << numDecodings(s);

     return 0;
 }