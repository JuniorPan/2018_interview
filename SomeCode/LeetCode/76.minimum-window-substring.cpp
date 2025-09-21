/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (35.36%)
 * Likes:    5501
 * Dislikes: 378
 * Total Accepted:    461K
 * Total Submissions: 1.3M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t, return the minimum window in s which will contain
 * all the characters in t. If there is no such window in s that covers all
 * characters in t, return the empty string "".
 * 
 * Note that If there is such a window, it is guaranteed that there will always
 * be only one unique minimum window in s.
 * 
 * 
 * Example 1:
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Example 2:
 * Input: s = "a", t = "a"
 * Output: "a"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, t.length <= 10^5
 * s and t consist of English letters.
 * 
 * 
 * 
 * Follow up: Could you find an algorithm that runs in O(n) time?
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) 
    {
        vector<int> m(128,0);
        // 记录t中每个字符出现的次数
        for (char c : t)
            m[c]++;
        int count = 0;
        int left = 0;
        int min_len = INT_MAX; // 记录窗口的最小值，
        int min_left = -1; // 记录窗口的最小值对应的左边界
        for(int i = 0; i < s.size(); i++)
        {   
            //减1后的映射值仍大于等于0，说明当前遍历到的字母是T串中的字母
            if (--m[s[i]] >= 0) 
                count ++;
            while (count == t.size()) // 形成窗口了, 并且当前窗口包含t中的所有字符
            {
                if (i - left + 1 < min_len)
                {
                    min_len = i - left + 1;
                    min_left = left;
                }

                // 开始收缩左边界
                if (++m[s[left]] > 0)
                {   
                    count--;
                }
                ++left;                
            }
        }
        return  min_left == -1 ? "" : s.substr(min_left, min_len); 
    }
};
// @lc code=end

