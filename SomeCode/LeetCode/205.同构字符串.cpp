/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 *
 * https://leetcode-cn.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (49.94%)
 * Likes:    698
 * Dislikes: 0
 * Total Accepted:    247.9K
 * Total Submissions: 503.1K
 * Testcase Example:  '"egg"\n"add"'
 *
 * 给定两个字符串 s 和 t ，判断它们是否是同构的。
 * 
 * 如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
 * 
 * 
 * 每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入：s = "egg", t = "add"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "foo", t = "bar"
 * 输出：false
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "paper", t = "title"
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * 1 <= s.length <= 5 * 10^4
 * t.length == s.length
 * s 和 t 由任意有效的 ASCII 字符组成
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        int m1[256] = {-1}, m2[256] = {-1}, n = s.size();
        for (int i = 0; i < n; ++i) {
            std::cout << "\ni: " << i << " m1: " << m1[s[i]] << " m2: " << m2[t[i]] << std::endl;

            if (m1[s[i]] != m2[t[i]]) 
                return false;
            m1[s[i]] = i;
            m2[t[i]] = i;
            
            
        }
        return true;
    }
};

void runTests() {
    Solution sol;

    std::vector<std::pair<std::string, std::string>> testCases = {
        {"ab", "aa"},           // false

    };

    for (const auto& testCase : testCases) {
        std::cout << "Test: " << testCase.first << ", " << testCase.second << " Result: " 
                  << std::boolalpha << sol.isIsomorphic(testCase.first, testCase.second) << std::endl;
    }
}

int main() {
    runTests();
    return 0;
}

// @lc code=end

