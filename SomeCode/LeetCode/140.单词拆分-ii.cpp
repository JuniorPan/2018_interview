/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 *
 * https://leetcode-cn.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (49.88%)
 * Likes:    728
 * Dislikes: 0
 * Total Accepted:    94.3K
 * Total Submissions: 162.7K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * 给定一个字符串 s 和一个字符串字典 wordDict ，在字符串 s 中增加空格来构建一个句子，使得句子中所有的单词都在词典中。以任意顺序
 * 返回所有这些可能的句子。
 * 
 * 注意：词典中的同一个单词可能在分段中被重复使用多次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入:s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
 * 输出:["cats and dog","cat sand dog"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入:s = "pineapplepenapple", wordDict =
 * ["apple","pen","applepen","pine","pineapple"]
 * 输出:["pine apple pen apple","pineapple pen apple","pine applepen apple"]
 * 解释: 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入:s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * 输出:[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * 1 <= s.length <= 20
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 10
 * s 和 wordDict[i] 仅有小写英文字母组成
 * wordDict 中所有字符串都 不同
 * 
 * 
 */

// @lc code=index
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;  // 存储结果
        vector<string> path;    // 存储当前拼接的路径
        dfs(s, wordDict, result, path, 0);  // 调用深度优先搜索函数
        return result;  // 返回所有可能的句子
    }

    // 深度优先搜索函数
    void dfs(string& s, vector<string>& wordDict, vector<string>& result, vector<string>& path, int index) {
        if (index == s.size()) {  // 如果已经处理完整个字符串，将当前路径加入结果中
            result.push_back(joinWords(path));
            return;
        }

        for (int i = index; i < s.size(); i++) {  // 从当前位置开始尝试拆分
            string word = s.substr(index, i - index + 1);  // 从index到i位置的子串
            if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                path.push_back(word);  // 将合法单词添加到路径
                dfs(s, wordDict, result, path, i + 1);  // 递归处理余下部分
                path.pop_back();  // 回溯，删除最后一个单词
            }
        }
    }

    // 辅助函数，将单词列表连接成句子
    string joinWords(vector<string>& words) {
        string result = words[0];
        for (int i = 1; i < words.size(); i++) {
            result += " " + words[i];
        }
        return result;
    }
};
// @lc code=end

