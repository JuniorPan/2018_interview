#include <iostream>
#include <string>

using namespace std;


void reverseWord(string &s, int i, int j)
{
    while(i < j)
    {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }
}
    
void reverseWords(string &s) 
{
    
    for (int i = 0, j = 0; j <= s.length(); j++)
    {
        if (s[j] == ' ' || s[j] == '\0')
        {
            reverseWord(s, i, j-1);
            i = j + 1;
        }
    }
    reverseWord(s, 0, s.length()-1);
}

int main()
{
    string s = "the sky is blue";

    reverseWords(s);
    cout << s << endl;



    return 0;
}