/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (29.25%)
 * Likes:    7850
 * Dislikes: 567
 * Total Accepted:    1M
 * Total Submissions: 3.5M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        
        // dp[i, j] = 1                                   if i == j
        //          = s[i] == s[j]                        if j = i + 1
        //          = s[i] == s[j] && dp[i + 1][j - 1]    if j > i + 1

        if (s.empty())
            return "";

        int len = 0;
        int left = 0;
        int right = 0;
        // dp[i][j] 表示字符串区间 [i, j] 是否为回文串
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int j = 0; j < s.size(); j++) // 遍历所有的子串
        {
            for (int i = 0; i < j; i++)
            {
                dp[i][j] = s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]);
                if (dp[i][j] && len < j - i + 1)
                {
                    len = j - i + 1;
                    left = i;
                    right = j;
                }
            }
            dp[j][j] = true;
        }
        return s.substr(left, right - left + 1);
    }
};
// @lc code=end
