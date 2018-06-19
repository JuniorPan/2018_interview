#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool good(const string& str1, const string& str2)
{
    int diff = 0;
    for (int i = 0; i < str1.size(); ++i) 
    {
        if (str1[i] != str2[i]) 
            ++diff;
        if (diff > 1) 
            return false;  // perhaps quicker
    }
    return diff == 1;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    queue<string> q;
    q.push(beginWord);
    unordered_map<string, bool> visited;
    int len = 1;
    while (!q.empty())
    {
        int n = q.size();
        cout << "n: " << n << endl;
        for (int i = 0; i < n; ++i)  // 每个循环结束表示扩展了一层
        {
            
            string curr = q.front();
            cout << "len: " << len << " " << curr <<endl;
            // cout << curr << endl;
            if (curr == endWord) 
                return len;
            q.pop();
            visited[curr] = true; 
            vector<string>::iterator it;

            for(it = wordList.begin(); it != wordList.end(); it++)
            {
                if (good(curr, *it) && !visited[*it])
                {
                    q.push(*it);
                    visited[*it] = true;
                }
            }
        }
        
        len++;
    }
    return 0;
}

int main()
{   

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << ladderLength(beginWord,  endWord, wordList) << endl;
    
    return 0; 
}