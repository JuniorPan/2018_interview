#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int dirs[8][2] = {1,1,1,0,1,-1,0,1,0,-1,-1,1,-1,0,-1,-1};

void dfs(const vector<vector<int> >& nums, vector<vector<bool> >& visit, int i, int j, int& value)
{
    if ( nums[i][i] == 0 || visit[i][j])
        return;
    
    visit[i][j] = true;

    value += nums[i][j];
    for(int k = 0; k < 8; k++)
    {
        int x = i + dirs[k][0];
        int y = j + dirs[k][1];

        if (x < 0 || x > nums.size() || y < 0 || y > nums[0].size() || visit[x][y])
            continue;
        dfs(nums, visit, x, y, value);
    }
    
}

int main()
{
    int row = 0, col = 0;
    scanf("%d %d", &row, &col);
    vector<vector<int> > nums( row, vector<int>(col, 0) );

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        scanf("%d", &nums[i][j]);
    }

    vector<vector<bool> > visit(row, vector<bool>(col, false));
    int value = 0;
    int minV = INT_MAX;
    int maxV = INT_MIN;


    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            value = 0;
            if (!visit[i][j])
                dfs(nums, visit, i, j, value);
            if (value < minV)
                minV = value;
            if (value > maxV)
                maxV = value;
        }
    }

    cout << maxV << endl;
    cout << minV << endl;

    return 0;
}