#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int T;
int C, N1, N5, N10;
int total;
int dp[151][151][51];
int recur (int c, int n5, int n10)
{
    if (dp[c][n5][n10]!=-1) return dp[c][n5][n10];
    if (c == C) return dp[c][n5][n10] = 0;
    int n1 = total - c*8 - n5 * 5 - n10 * 10;
    int minn = 1<<30;
    if (n1>=8) minn = min(minn, 8 + recur(c+1, n5, n10));

    if (n5>=1 && n1 >= 3) minn = min(minn, 4 + recur(c+1, n5-1, n10));

    if (n10>=1 && n1 >=3) minn = min(minn, 4 + recur (c+1, n5+1, n10-1));

    if (n5>=2) minn = min(minn, 2 + recur(c+1, n5-2, n10));

    if (n10 >= 1) minn = min(minn, 1 + recur(c+1, n5, n10-1));

    return dp[c][n5][n10] = minn;
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d %d", &C, &N1, &N5, &N10);
        total = N1 + N5*5 + N10 * 10;
        memset(dp, -1, sizeof dp);
        printf("%d\n", recur(0, N5, N10));
    }
}
