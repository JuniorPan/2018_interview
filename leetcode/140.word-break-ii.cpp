/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (31.11%)
 * Likes:    1875
 * Dislikes: 375
 * Total Accepted:    231K
 * Total Submissions: 739.5K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        return helper(s, wordSet, 0, memo);
    }
    vector<string> helper(string s, unordered_set<string> &wordSet, int start, unordered_map<int, vector<string>> &memo)
    {
        if (memo.count(start) > 0)
        {
            return memo[start];
        }
        if (start == s.size())
        {
            return {""};
        }
        vector<string> res;
        for (int end = start + 1; end <= s.size(); ++end)
        {
            if (wordSet.count(s.substr(start, end - start)) > 0)
            {
                vector<string> tmp = helper(s, wordSet, end, memo);
                for (auto str : tmp)
                {
                    res.push_back(s.substr(start, end - start) + (str.empty() ? "" : " ") + str);
                }
            }
        }
        memo[start] = res;
        return res;
    }
};
// @lc code=end
