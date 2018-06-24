#include <iostream>
#include <vector>
using namespace std;



// 一排有N个位置，一个机器人在最开始停留在P位置上，如果 p==O位置，下一分钟机器人一定向右移动到1位置；
// 如果p==N-1， 下一分钟机器人一定向左移动到N-2位置。如果P在0和N-1之间， 下一分钟机器人一定会向左或者向右移动。
// 求K分钟的时候，机 器人到达T位置有多少种走法。

// 函数为：int f(int N, int P, int K, int T)，返回值为走法 的数量。


int f1(int N, int P, int K, int T)
{

    if (N  < 2 || P < 0 || K < 1 || T < 0 || P >= N || T >= N)  // 判断边界
        return 0;

    if (K == 1)
        return T == P ? 1 : 0;

    if (T == 0)
        return f1(N, P, K-1, 1);
    if (T == N-1)
        return f1(N, P, K-1, T-1);
    else
        return f1(N, P, K-1, T-1) + f1(N, P, K-1, T+1);

}

int f2(int N, int P, int K, int T)
{

    if (N  < 2 || P < 0 || K < 1 || T < 0 || P >= N || T >= N)  // 判断边界
        return 0;

    vector<vector<int> > dp(K, vector<int>(N, 0));
    dp[0][P] = 1;

    for(int i = 1; i < K; i++)
    {
        dp[i][0] = dp[i-1][1];
        dp[i][N-1] = dp[i-1][N-2];
        for(int j = 1; j < N-1; j++)
        {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
        }
    }
    return dp[K-1][T];
 
}



int main()
{
    cout << f1(8, 3, 5, 2) << endl;
    cout << f2(8, 3, 5, 2) << endl;

    return 0;
}