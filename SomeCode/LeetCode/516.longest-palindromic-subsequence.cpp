/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (52.28%)
 * Likes:    2501
 * Dislikes: 201
 * Total Accepted:    140.5K
 * Total Submissions: 258.2K
 * Testcase Example:  '"bbbab"'
 *
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * Input:
 * 
 * 
 * "bbbab"
 * 
 * Output:
 * 
 * 
 * 4
 * 
 * One possible longest palindromic subsequence is "bbbb".
 * 
 * 
 * 
 * Example 2:
 * Input:
 * 
 * 
 * "cbbd"
 * 
 * Output:
 * 
 * 
 * 2
 * 
 * One possible longest palindromic subsequence is "bb".
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consists only of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        // dp[i][j]表示[i,j]区间内的字符串的最长回文子序列
        vector<vector<int>> dp(n, vector<int>(n,0));
        dp[0][0]=1;

        //如果s[i]==s[j]，那么i和j就可以增加2个回文串的长度，我们知道中间dp[i + 1][j - 1]的值，那么其加上2就是dp[i][j]的值。如果s[i] != s[j]，那么我们可以去掉i或j其中的一个字符，然后比较两种情况下所剩的字符串谁dp值大，就赋给dp[i][j]

        for (int i = 1; i < n; i++)
        {
            dp[i][i] = 1;
            for (int j = i-1; j >= 0; j--)
            {
                if (s[i] == s[j])
                {
                    dp[j][i] = dp[j+1][i-1] + 2;
                }
                else
                {
                    dp[j][i] = max(dp[j][i-1], dp[j+1][i]);
                }
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end
