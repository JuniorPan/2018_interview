#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) 
{
    // 抄的别人的。。。
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i != s.length(); i++) {
        if (dict[s[i]] > start) // 如果当前字符在前面出现过，则更新位置
            start = dict[s[i]];
        dict[s[i]] = i;  // 每次都需要记录当前字符出现的位置
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}


int main()
{
    cout << lengthOfLongestSubstring("abacadaf") << endl;
    return 0;
}