//
//  Filename: demo1
//  Project: _
//
//  Created by panqiang on 2018/4/2 by CLion
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#define MAXLEN 200000
#define MAXVEX 1001   //定义一个最大的节点个数
#define MAXNUM 65535
#define FALSE 0
#define TRUE  1
typedef int Boolean;

typedef int Pathmatrix[MAXVEX];			//用于存储最短路径下标的数组
typedef int ShortPathTable[MAXVEX];		//用于存储到各顶点最短路径的权值和

typedef int Pathmatrix_2[MAXVEX][MAXVEX];		//用于存储最短路径下标的数组
typedef int ShortPathTable_2[MAXVEX][MAXVEX];	//用于存储到各顶点最短路径的权值和





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
          cout << lineArray[i] << " ";
      }
      cout << endl;
}


typedef struct MGraph
{
	int *vexes;		 //顶点表
	int **arc;	 //邻接矩阵
	int numVertexes, numEdges;		 //顶点数和边数
}MGraph;

void InitMGraph(MGraph *G, int numVertexes, int numEdges)
{
    G->numVertexes = numVertexes;
    G->numEdges = numEdges;
    G->vexes = new int[G->numVertexes];

    G->arc = new int*[numVertexes];
    for(int i = 0; i < numVertexes; i++)
    {
        G->arc[i] = new int[numVertexes];
    }
}

void DestoryMGraph(MGraph *G)
{
    for(int i = 0; i < G->numVertexes; i++)
    {
        delete[] G->arc[i];
    }
    delete [] G->vexes;
    delete[] G->arc;
}


void CreateMGraph(MGraph *G, int *edgeArray)//创建图
{
	int i, j;
	for (i = 0; i < G->numVertexes; i++) //输入顶点信息，建立顶点表
    {
        G->vexes[i] = i+1;
        cout << " G->vexes[i]: " <<  G->vexes[i] << endl;
	}
    for (i = 0; i < G->numVertexes; i++) //矩阵初始化
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = 0;
		}
	}
	for (int k = 0; k < (G->numEdges) * 2; k += 2)
	{
        G->arc[edgeArray[k]-1][edgeArray[k+1]-1] = 1; // 有向图
	}
}

void ShowMGraph(MGraph G)
{
	int i, j;
    int count = 0;
	for (i = 0; i < G.numVertexes; i++)
	{
		printf("%d-->", G.vexes[i]);
		for (j = 0; j < G.numVertexes; j++)
		{
			if (G.arc[i][j] != 0)
            {
                printf("%d--->", G.vexes[j]);
                count += 1;
            }
		}
		printf("\n");
	}
    cout << "边数: " << count << endl;
}
void Topological_Order(MGraph G)
{
    int n = G.numVertexes; // 图的节点个数
    cout << "n: " << n << endl;

    int indegree[n];
    for(int i = 0; i < n; i++)
    {
        indegree[i] = 0;
    }

    // 构建入度表
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (G.arc[i][j] == 1)
                ++indegree[j];
        }
    }
    int res[n];
    int Q[n];
    for(int i = 0; i < n; i++)
    {
        Q[i] = 0;
    }
	int front = 0, rear = 0;

    for(int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            rear = (rear + 1) % (n);
	        Q[rear] = i;
        }

    }
    int counter = 0;
    while(front != rear)
    {

        front = (front + 1) % (n);
		int u = Q[front];
        res[counter] = u;
        ++counter;

        for(int j = 0; j < n; j++)
        {
            if (G.arc[u][j] == 1)
                if (--indegree[j] == 0)
                {
                    rear = (rear + 1) % (n);
	                Q[rear] = j;
                }
        }
    }
    cout << "拓扑排序: " << endl;
    for(int i = 0; i < counter; i++)
    {
        cout << res[i]+1 << " ";
    }
    cout <<endl;

    cout << "counter: " << counter << endl;
}




int main()
{
    ifstream infile;
//    infile.open("/Users/panqiang/Desktop/三星上机题/test.txt");
    infile.open("/Users/panqiang/Desktop/三星上机题/test2.txt");
    if(!infile) cout<<"error"<<endl;

    ofstream outfile;
    outfile.open("/Users/panqiang/Desktop/三星上机题/3-sample_input2.txt");
    if(!outfile)
    {//未成功打开文件
        throw runtime_error("file cannot open");
        return -1;
    }


    int count = 0;

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


        MGraph G;
        InitMGraph(&G,numVertexes, numEdges);
        CreateMGraph(&G,lineArray2);//创建图
        cout << "-------------" << endl;
        Topological_Order(G);





//        ShowMGraph(G);
//        for(int i = 0; i < G.numVertexes; i++)
//        {
//            for(int j = 0; j < G.numVertexes; j++)
//            {
//                cout << G.arc[i][j] << " ";
//            }
//            cout << endl;
//        }
        cout << endl;
        DestoryMGraph(&G);
        outfile << "# "  << count / 2 << " " ;
        for (int i = 0; i < 5; i++)
        {
            outfile  << lineArray2[i] << " ";
        }
        outfile << endl;
        delete []lineArray2;
        delete [] str1;
        delete [] str2;


//        count += 2;
//        cout << "count " << count << endl;
//        cout << "-----------------------------------------------------------" << endl;


    }
//    cout << "行数: " << count << endl;
    return 0;
}

