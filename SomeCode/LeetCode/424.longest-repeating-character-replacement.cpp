/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (47.77%)
 * Likes:    1848
 * Dislikes: 96
 * Total Accepted:    88.9K
 * Total Submissions: 185.9K
 * Testcase Example:  '"ABAB"\n2'
 *
 * Given a string s that consists of only uppercase English letters, you can
 * perform at most k operations on that string.
 * 
 * In one operation, you can choose any character of the string and change it
 * to any other uppercase English character.
 * 
 * Find the length of the longest sub-string containing all repeating letters
 * you can get after performing the above operations.
 * 
 * Note:
 * Both the string's length and k will not exceed 10^4.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "ABAB", k = 2
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * Replace the two 'A's with two 'B's or vice versa.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "AABABBA", k = 1
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int res = 0, maxCnt = 0, left = 0;
        vector<int> m(128, 0); // 用来记录窗口中每个字符出现的次数
        for (int i = 0; i < s.size(); i++)
        {
            maxCnt = max(maxCnt, ++m[s[i]]);
            // 判断当前窗口 left...i 是否满足条件
            if (i - left + 1 - maxCnt > k) // 不满足 从左开始收缩窗口
            {
                --m[s[left]];
                left++;
            }

            res = max(res, i - left + 1);
        }
        return res;
    }
};
// @lc code=end
