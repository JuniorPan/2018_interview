/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (38.24%)
 * Likes:    8083
 * Dislikes: 0
 * Total Accepted:    1.9M
 * Total Submissions: 5M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 *
 *
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxLength = 0;
    int left = 0;
    vector<int> charIndex(256, -1);

    for (int right = 0; right < n; right++) {
        if (charIndex[s[right]] != -1) {
            cout << "Found a repeat character '" << s[right] << "' at index " << right << endl;
            // 如果字符已经在窗口中出现过，将左边界移动到上次出现的位置的右边

            cout << "left " << left << " charIndex[s[right]] + 1: " << charIndex[s[right]] + 1 << endl;
            left = max(left, charIndex[s[right]] + 1);
            
            cout << "Updated left to " << left << endl;
        }

        charIndex[s[right]] = right; // 更新字符的最新位置
        maxLength = max(maxLength, right - left + 1);
        cout << "Current substring: '" << s.substr(left, right - left + 1) << "' with length " << right - left + 1 << endl;
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    cout << "Length of the longest substring: " << result << endl;
    return 0;
}

// @lc code=end
