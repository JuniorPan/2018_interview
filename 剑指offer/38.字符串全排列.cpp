#include <iostream>
#include <vector>
#include <string>
using namespace std;

void CharSort(char *str, int start, int end)
{
    char data;
    int i;

    if (start == end)
    {
        for (i = 0; i < end; i++)
            cout << str[i];
        cout << endl;
    }
    else
    {
        for (i = start; i < end; i++)
        {
            data = str[start];
            str[start] = str[i];
            str[i] = data;

            CharSort(str, start + 1, end);

            data = str[start];
            str[start] = str[i];
            str[i] = data;
        }
    }
}

void dfs(string &str, int begin,vector<string> &res)
    {
        if (begin == str.length()-1)
        {
            res.push_back(str);
            return ;
        }
        
        for (int i = begin; i < str.length(); i++) {
		    swap(str[begin], str[i]);
		    dfs(str, begin + 1, res);
		    // reset
		    swap(str[begin], str[i]);
		}
    }
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.size() < 1)
            return res;
        dfs(str, 0,res);
        return res;
    }

int main()
{
    char str[5] = "aa";
    string s = "abc";
    vector<string> res = Permutation(s);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }

    

    // CharSort(str, 0, strlen(str));

    return 0;
}