/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (28.90%)
 * Likes:    3622
 * Dislikes: 1264
 * Total Accepted:    463.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list.
 * 
 * 
 * Note:
 * 
 * 
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output: 5
 * 
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: 0
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    inline bool good(const string &str1, const string &str2)
    {
        int diff = 0;
        for (int i = 0; i < str1.size(); ++i)
        {
            if (str1[i] != str2[i])
                ++diff;
            if (diff > 1)
                return false; // perhaps quicker
        }
        return diff == 1;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord))
            return 0;
        queue<string> q;
        q.push(beginWord);
        int res = 0;
        while (!q.empty())
        {
            for (int k = q.size(); k > 0; --k)
            {
                string word = q.front();
                q.pop();
                if (word == endWord)
                    return res + 1;
                for (int i = 0; i < word.size(); ++i)
                {
                    string newWord = word;
                    for (char ch = 'a'; ch <= 'z'; ++ch)
                    {
                        newWord[i] = ch;
                        if (wordSet.count(newWord) && newWord != word)
                        {
                            q.push(newWord);
                            wordSet.erase(newWord);
                        }
                    }
                }
            }
            ++res;
        }
        return 0;
    }
};
// @lc code=end
