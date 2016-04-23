#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 10;
const int INF = 99999999;
int m, n, a[MAXN][MAXN], dp[MAXN][MAXN], nr[MAXN][MAXN];
int main()
{
    while(scanf("%d%d" , &m, &n) == 2 && m)
    {
        for (int i = 0 ; i < m; i++)
            for (int j = 0 ; j < n; j++)
                scanf("%d", &a[i][j]);

        int ans = INF, first = 0, v;
        int row[3];
        for (int j = n-1; j >= 0; j--)
            for (int i = 0; i < m; i++)
            {
                if (j == n-1) dp[i][j] = a[i][j];
                else
                {
                    row[0] = i; row[1] = i-1; row[2] = i+1;
                    if (row[1] < 0) row[1] = m-1;
                    if (row[2] == m) row[2] = 0;
                    sort(row, row+3);
                    dp[i][j] = INF;
                    for (int k = 0; k < 3; k++)
                    {
                        v = dp[row[k]][j+1] + a[i][j];
                        if (v < dp[i][j])
                        {
                            dp[i][j] = v;
                            nr[i][j] = row[k];
                        }
                    }
                }
                if (j==0 && dp[i][j] < ans)
                {
                    ans = dp[i][j];
                    first = i;
                }
            }
        printf("%d", first+1);
        for (int i = nr[first][0], j = 1; j < n; i = nr[i][j], j++) //smart
            printf(" %d", i+1);
        printf("\n%d\n", ans);
    }
}
