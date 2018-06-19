#include <iostream>
#include <fstream>
using namespace std;
#define MAXLEN 200000

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

void split(char *str, int *node)
{


    char *p1 = str;
    char *p2 = str;
    int j = 0;
    while(*p2 != '\0')
    {
        if(*p2 != ' ')
        {
            p2++;

        }
        else{
            int digit_num = p2 - p1;
            node[j] = str2int2(p1, p2);
            j++;
            p2++;
            p1 = p2;

        }
    }
}

int getNumber(const char *str)
{
    int i = 0;
    int num = 0;

    while(str[i] != '\0')
    {
        if (str[i] == ' ' )
            num ++;
        i++;
    }
    return num;
}

void printArray(int *lineArray, int num)
{
      for (int i = 0; i < num; i++)
      {
          std::cout << lineArray[i] << " ";
      }
      cout << endl;
}


int main()
{
    ifstream infile;
//    infile.open("/Users/panqiang/Desktop/三星上机题/test.txt");
    infile.open("/Users/panqiang/Desktop/三星上机题/2-sample_input.txt");
    if(!infile) cout<<"error"<<endl;



    int count = 0;

    char *str = new char[MAXLEN];
    infile.getline(str,MAXLEN);
    cout << str2int(str) << endl;


    while(!infile.eof())  //按行读取,遇到换行符结束
    {

        char *str1 = new char[MAXLEN];
        char *str2 = new char[MAXLEN];
        infile.getline(str1,MAXLEN);
        int num = getNumber(str1);
        int *lineArray = new int[num];
        split(str1, lineArray);
        printArray(lineArray, num);


        int numVertexes = lineArray[0];
        int numEdges = lineArray[1];
        delete []lineArray;



        infile.getline(str2,MAXLEN);
        int num2 = getNumber(str2);
        int *lineArray2 = new int[num2];
        split(str2, lineArray2);
        printArray(lineArray2, num2);





        delete []lineArray2;
        delete [] str1;
        delete [] str2;


        count += 2;
        cout << "-----------------------------------------------------------" << endl;
        // break;


    }
    cout << "行数: " << count << endl;
    return 0;
}