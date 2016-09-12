#include <bits/stdc++.h>
using namespace std;
int N, M;
int cost[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
int dp[110][3010]; // [# of match][current num % M], store the max length of number
int ans[110][3010]; // for backtracking
int cnt;
int main()
{
    while (~scanf("%d%d", &N, &M) && N)
    {
        memset(dp,-1,sizeof dp);
        memset(ans,-1,sizeof ans);
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <M; j++)
            {
                if (j==0) dp[i][j] = 0;
                for (int k = 9; k >= 0; k--)
                    if (i >= cost[k])
                        if (dp[i-cost[k]][(j*10+k) % M]>=0 && dp[i][j] < dp[i-cost[k]][(j*10+k) % M] + 1)
                        {
                            dp[i][j] = dp[i-cost[k]][(j*10+k) % M] + 1;
                            ans[i][j] = k;
                        }
            }
        printf("Case %d: ", ++cnt);
        if (dp[N][0]<=0)
            printf("-1");
        else
        {
            int i = N, j = 0;
            for (int k = ans[i][j]; k >=0; k = ans[i][j])
            {
                printf("%d", k);
                i -= cost[k];
                j = ((j*10) + k) % M;
            }

        }
        printf("\n");
    }
}
