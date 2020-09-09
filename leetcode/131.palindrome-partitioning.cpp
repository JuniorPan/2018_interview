/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (46.47%)
 * Likes:    2117
 * Dislikes: 74
 * Total Accepted:    241.2K
 * Total Submissions: 501.8K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution
{

    bool isPalindrome(const string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    // dfs含义是 表示s 从index开始的子串拆成回文的方式
    void dfs(string &s, int index, vector<string> &temp, vector<vector<string>> &res)
    {
        if (index == s.size())
        {
            res.push_back(temp);
            return;
        }

        for (int i = index; i < s.size(); i++)
        {
            if (isPalindrome(s, index, i)) // 取子串 这个地方可以用动态规划去优化
            {
                temp.push_back(s.substr(index, i - index + 1));
                dfs(s, i + 1, temp, res);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        if (s.empty())
            return res;

        vector<string> temp;
        dfs(s, 0, temp, res);

        return res;
    }
};
// @lc code=end
