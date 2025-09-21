/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 *
 * https://leetcode.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (39.08%)
 * Likes:    1612
 * Dislikes: 60
 * Total Accepted:    150.4K
 * Total Submissions: 384.4K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * Given two strings s and t, return the number of distinct subsequences of s
 * which equals t.
 * 
 * A string's subsequence is a new string formed from the original string by
 * deleting some (can be none) of the characters without disturbing the
 * relative positions of the remaining characters. (i.e., "ACE" is a
 * subsequence of "ABCDE" while "AEC" is not).
 * 
 * It's guaranteed the answer fits on a 32-bit signed integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "rabbbit", t = "rabbit"
 * Output: 3
 * Explanation:
 * As shown below, there are 3 ways you can generate "rabbit" from S.
 * rabbbit
 * rabbbit
 * rabbbit
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "babgbag", t = "bag"
 * Output: 5
 * Explanation:
 * As shown below, there are 5 ways you can generate "bag" from S.
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length, t.length <= 1000
 * s and t consist of English letters.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        // dp[i][j]表示S[0...j-1]中的子序列等于T[0..i-1]
        // 1 如果s[i-1]!=t[j-1] 则s[:i-1]中匹配t[:j-1]子序列个数==s[:i-2]中匹配t[:j-1]子序列个数
        //     dp[i][j] = dp[i-1][j]
        // 2 if s[i-1]==t[j-1]:
        //     dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
        //     2.1 用s[i-1]     dp[i-1][j-1] 则s[:i-1]中匹配t[:j-2]子序列个数 ==s[:i-1]中匹配t[:j-1]子序列个数
        //     2.2 不用s[i-1]   dp[i-1][j]   则s[:i-2]中匹配t[:j-1]子序列个数  ==s[:i-1]中匹配t[:j]子序列个数

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        for (int j = 0; j <= m; j++)
        {
            dp[j][0] = 1;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] != t[j - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
