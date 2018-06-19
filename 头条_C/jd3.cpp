#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
 

#define N 8
 

int row[] = { 2, 1, -1, -2, -2, -1,  1,  2, 2 };
int col[] = { 1, 2,  2,  1, -1, -2, -2, -1, 1 };
 

bool isValid(int x, int y)
{
    if (x < 0 || y < 0 || x > N-1 || y > N-1)
        return false;
    return true;
}


void chess(int visited[N][N], int x, int y, int des_x, int des_y, int k)
{
    visited[x][y] = 1;

//    cout << "visited: "  << visited[x][y] << endl;
    if (x == des_x && y == des_y && k == -1)
    {
        cout << "n: "  <<endl;
        visited[x][y] = 0;
        return;
    }

    for (int j = 0; j < 8; j++)
    {
        int newX = x + row[j];
        int newY = y + col[j];

        cout << newX << " " << newY << " " << k << endl;
//        break;

        if (isValid(newX, newY) && !visited[newX][newY])
            chess(visited, newX, newY, des_x, des_y, k--);
    }
    visited[x][y] = 0;
}

int main()
{
    int visited[N][N];
     

    memset(visited, 0, sizeof visited);
//    int k;
//    cin >> k;
//
//    int x, y;
//    cin >>  x >> y;
//
//    int count = 1;
//    int num = 0;

    chess(visited, 0, 0, 3, 3, 2 );
//    cout << num << endl;
     
    return 0;
}
