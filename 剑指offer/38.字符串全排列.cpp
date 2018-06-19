#include <iostream>
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

int main()
{
    char str[5] = "abcd";
    

    CharSort(str, 0, strlen(str));

    return 0;
}