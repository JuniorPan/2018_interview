/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (61.39%)
 * Likes:    3273
 * Dislikes: 129
 * Total Accepted:    222.3K
 * Total Submissions: 362.1K
 * Testcase Example:  '"abc"'
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 * 
 * Example 1:
 * 
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        if (n <= 0)
            return 0;
        int res = 0;
        // dp[i][j] 表示区间s[i...j]上是否为回文子串
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
        {
            // dp[i][i] = true;
            for (int j = 0; j <= i; j++)
            {
                dp[j][i] = s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]);
                if (dp[j][i])
                    res++;
            }
            
        }
        return res;
    }
};
// @lc code=end
