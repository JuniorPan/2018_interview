#include <iostream>
#include <vector>
using namespace std;



void printEdge(vector<vector<int> > arr, int left_x, int left_y, int right_x, int right_y)
{

    if (left_y == right_y)
    {
        for(int i = left_x; i < right_x; i++)
        {
            cout << arr[i][left_y] << " ";
        }
    }
    else if (left_x == right_x)
    {
        for(int i = left_y; i < right_y; i++)
        {
            cout << arr[left_x][i] << " ";
        }
    }
    else
    {
        int x = left_x;
        int y = left_y;

        while(y != right_y)
        {
            cout << arr[left_x][y] << " ";
            y++;
        }
        while(x != right_x)
        {
            cout << arr[x][right_y] << " ";
            x++;
        }

        while(y != left_y)
        {
            cout << arr[right_x][y] << " ";
            y--;
        }

        while(x != left_x)
        {
            cout << arr[x][left_y] << " ";
            x--;
        }
    }
}


int main()
{
    vector<vector<int> > matrix = 
    {
        {1,10,3,8},
        {12,2,9,6},
        {5,7,4,11},
        {3,7,16,5}
    };
    printEdge(matrix, 1,1,2,2);

    return 0;
}