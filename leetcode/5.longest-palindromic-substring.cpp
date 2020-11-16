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
        if (s.empty())
            return "";
        int len = 0;  // 记录最长回文子串的长度
        int left = 0, right = 0; // 记录最长回文子串的左右边界
        // dp[i][j] 表示 s[i...j]上是否为回文子串
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[j][i] = s[i] == s[j] && ( i - j < 2 || dp[j+1][i-1]); 
                if (dp[j][i] && i - j + 1 > len)
                {
                    len = i - j +1;
                    left = j;
                    right = i;
                }
            }
            dp[i][i] = true;
        }
        return s.substr(left,right - left + 1);
    }
};
// @lc code=end
