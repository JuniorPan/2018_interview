#include <iostream>
#include <string>
using namespace std;


void Reverse(string &str, int i, int j)
{

    while(i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }
}
string ReverseSentence(string &str)
{
    int len = str.length();
    //Reverse(str, 0, str.length());

    int i = 0;
    
    
    int j = i;

    while(str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            i++;
            j++;
        }
        else if (str[j] == ' ' || str[j] == '\0')
        {
            Reverse(str, i, --j);
            i = ++j;
        }
        else
        {
            j++;
        }
    }
    return str;
}

string reverse2(string &s)
{
    int len = s.length();
    for(int i, j = 0; j <= len; j++)
    {
        if (s[j] == ' ' || s[j] == '\0')
        {
            Reverse(s, i, j-1);
            i = j + 1;
        }
    }
    Reverse(s, 0, len -1);
    return s;
}

int main()
{
    string str = "hello world panqinag hh";
    cout << reverse2(str) << endl;

    return 0;
}