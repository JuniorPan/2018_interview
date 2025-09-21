/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (35.78%)
 * Likes:    4521
 * Dislikes: 0
 * Total Accepted:    829.3K
 * Total Submissions: 2.3M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "a"
 * 输出："a"
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "ac"
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由数字和英文字母（大写和/或小写）组成
 * 
 * 
 */

#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) 
    {
        if (s.empty())
            return "";
        // dp[i][j] 表示 s[i...j]上是否为回文子串
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int len = 0;
        int left = 0;

        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 0; j <= i; j++)
            {
                // 字符 s[i] 和 s[j] 是否相等以及内部子串 s[j+1...i-1] 是否为回文子串
                // i - j < 2 处理长度为 1 和 2 的子串的基本情况。
                cout << "j: " << j << " i: " << i << " j+1: " << j + 1 << " i-1: " << i-1 <<  " i -j: " << i - j << endl;

                dp[j][i] = s[i] == s[j] && (i - j < 2 || dp[j+1][i-1]);
                if (dp[j][i] && i - j + 1 > len)
                {
                    len = i - j + 1;
                    left = j;
                }
            }
        }
        return s.substr(left, len);
    }
};

void testLongestPalindrome() {
    Solution solution;

    // Test cases
    std::string test1 = "babad";
    std::string test2 = "cbbd";
    std::string test3 = "a";
    std::string test4 = "ac";
    
    solution.longestPalindrome(test1);
//     std::cout << "Test 2: " << solution.longestPalindrome(test2) << std::endl;
//     std::cout << "Test 3: " << solution.longestPalindrome(test3) << std::endl;
//     std::cout << "Test 4: " << solution.longestPalindrome(test4) << std::endl;
}

int main() {
    testLongestPalindrome();
    return 0;
}
// @lc code=end

