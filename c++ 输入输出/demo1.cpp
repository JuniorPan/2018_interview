#include <iostream>
#include <fstream>
using namespace std;


int str2int(const char *str)
{
    int temp = 0;
    const char *ptr = str;  //ptr保存str字符串开头
    while(*str != 0)
    {
        if ((*str < '0') || (*str > '9'))  //如果当前字符不是数字
        {                       //则退出循环
            break;
        }
        temp = temp * 10 + (*str - '0'); //如果当前字符是数字则计算数值
        str++;      //移到下一个字符
    }  
    return temp;
}


int str2int2(const char *p1, const char *p2)
{
    int temp = 0;
    const char *ptr = p1;  //ptr保存str字符串开头
    while(p1 != p2)
    {
        if ((*p1 < '0') || (*p1 > '9'))  //如果当前字符不是数字
        {                       //则退出循环
            break;
        }
        temp = temp * 10 + (*p1 - '0'); //如果当前字符是数字则计算数值
        p1++;      //移到下一个字符
    }  
    return temp;
}

void split(char *str, int num, int length)
{
    int node[num];
    char *p1 = str;
    char *p2 = str;
    int l = 0;
    for(int i = 0; i < length; i++)
    {
        cout << "i: " << i << endl;
        if(*p2 != ' ')
        {
            p2 ++;
            l++;
            // cout << "l: " << l << endl;
        }
        else{
            int digit_num = p2 - p1;
            // cout << "digit_num: " << digit_num << endl;
            cout << str2int2(p1, p2) << endl;

            p2++;
            p1 = p2;
        }
    }
}




int main()
{
    ifstream infile;
    infile.open("1- sample_input.txt");
    if(!infile) cout<<"error"<<endl;
    int a[1000];
    char str[200000];
    int t1;
    int count = 0;
    while(infile.getline(str,sizeof(str)))  //按行读取,遇到换行符结束
    {   
        // cout<<str<<endl;
        count ++;
        if (count == 5)
        {
            cout << str << endl;
            int num = 0;
            int i = 0;
            
            while(i < 200000)
            {
                if (str[i] == ' ')
                    num ++;
                i++;
                
                // cout << str[i] << endl;
                // i++;
            }
            cout << "个数: " << num+1 << endl;
            


            char *p1 = str;
            char *p2 = str;
            int l = 0;
            for(int i = 0; i < 20000; i++)
            {
                if(*p2 != ' ')
                {
                    p2 ++;
                    l++;
                    cout << "l: " << l << endl;
                    if (l == num+1)
                        break;
                }
                else{
                    int digit_num = p2 - p1;
                    // cout << "digit_num: " << digit_num << endl;
                    p2++;
                    p1 = p2;
                }
                
            }
        }
    }
    cout << "行数: " << count << endl;
    return 0;
}