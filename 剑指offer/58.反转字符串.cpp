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


int main()
{
    string str = "  hello   world  ";
    cout << ReverseSentence(str) << endl;

    return 0;
}