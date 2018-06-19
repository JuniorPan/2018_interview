#include "../../generateRandomArray.h"


vector<int> getNext(string &m)
{
    vector<int> next(m.length(), 0);
    if (m.length() == 1)
    {
        next.push_back(-1);
        return next;
    }

    next[0] = -1;
    next[1] = 0;
    int pos = 2;
    int cn = 0; // cn表示跳的位置
    while(pos < m.length())
    {
        if (m[pos-1] == m[cn])  // 如果当前字符的前一个和跳到的字符一样
        {
            next[pos++] = ++cn;
        }
        else // 如果当前字符的前一个和跳到的字符不一样
        {
            if (cn > 0) // 如果还能往前跳
            {
                cn = next[cn];
            }
            else// 如果不能往前跳
            {
                next[pos++] = 0;
            }
        }
    }

    return next;

}



int KMP(string &s, string &m)
{
    if (m.length() < 1 || s.length() < m.length())
        return -1;

    int si;
    int mi;
    vector<int> next = getNext(m);

    while(si < s.length() && mi < m.length())
    {
        if(s[si] == m[mi])
        {
            si++;
            mi++;
        }
        else if (next[mi] == -1)
        {
            si++;
        }
        else
        {
            mi = next[mi];
        }
    }

    return mi == m.length() ? si - mi : -1;


}

int main()
{
    string str = "abcabcababaccc";
	string match = "ababa";
    cout << KMP(str, match) << endl;


    return 0;
}