#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;


void findFirstNotRepeating(string s)
{
    int n = s.length();

    vector<int> dict(255,-1);

    for(int i = 0; i < n; i++)
    {
        dict[s[i]] ++;
    }
    int i = 0;
    for(i = 0; i < n; i++)
    {
        if (dict[s[i]] == 0)
            break;
    }
    cout << s[i] << endl;
}

int main()
{
    findFirstNotRepeating("abbaeccddef");
    return 0;
}