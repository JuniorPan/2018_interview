#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void dfs(int A_size_row, int A_size_cow, int i, int j, int A[][4], int &res)
{
    if (i < 0 || i >= A_size_row || j < 0 || j >= A_size_cow || A[i][j] == -1 || A[i][j] == 0 ) {
		return;
	}

    res += A[i][j];
    A[i][j] = -1;
    for(int k = 0; k < 8; k++)
    {
        int x = i + row[k];
        int y = j + col[k];
        if (x < 0 || x >= A_size_row || y < 0 || y >= A_size_cow || A[x][y] == -1 || A[x][y] == 0 ) {
		    return;
	    }
        dfs(A_size_row, A_size_cow, x, y, A, res);
    }
}


void getMilitaryStrength(int A_size_row, int A_size_cow, int A[][4])
{

    int res = 0;
    int ma = INT_MIN;
    int mn = INT_MAX;
    for(int i = 0; i < A_size_row; i++)
    {
        for(int j = 0; i < A_size_row; j++ )
        {
            if (A[i][j] != 0 && A[i][j] != -1)
            {
                dfs(A_size_row, A_size_cow, i, j, A, res);
                if (res < mn)
                    mn = res;
                if (res > ma)
                    ma = res;
            }

        }
    }
    cout <<  ma << endl;
    cout << mn << endl;
 
}

int main()
{
    int A[4][4] = {{0,0,0,1},
                    {1,2,3,4},
                    {0,0,0,0},
                    {0,0,1,0}};


    getMilitaryStrength(4, 4, A);             

    cout << "hello wolrd" << endl;
    return 0;
}