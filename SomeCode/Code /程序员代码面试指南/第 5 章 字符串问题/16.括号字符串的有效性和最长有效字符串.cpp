#include "../../generateRandomArray.h"


bool isValid(string s)
{

    int length = s.length();

    int status = 0;
    for(int i = 0; i < length; i++)
    {
        if (s[i] == ')' && --status < 0)// 遍历到')'时， status-1, 如果减1之后小于0，说明）要多 直接返回false
            return false;
        if (s[i] == '(') // 遍历到'('时， status加1
            status ++;
    }

    return status == 0;
}

int maxLength(string &s)
{
    int n = s.length();
    vector<int> dp(n, 0);  //dp[i]表示以s[i]结尾的最长有效字符串长度
    int res = 0;
    for(int i = 1; i < n; i++)
    {
        if (s[i] == '(')
            dp[i] = 0;
        
        if (s[i] == ')')
        {
            int pre = i - dp[i-1] - 1;
            if (pre >= 0 && s[pre] == '(')
            {
                dp[i] = dp[i-1] + 2 + (pre > 0 ? dp[pre-1] : 0);
            }
        }
        res = max(res, dp[i]);
    }
    return res;



}

int main()
{

    string str1 = "((())())";;
    cout << isValid(str1) << endl;


}