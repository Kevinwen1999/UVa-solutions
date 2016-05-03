#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 10, MAXM = 9 + 1;
double dp[MAXN][MAXM]; // ith number is j
int N, K;
int main()
{
    while(scanf("%d%d", &K, &N) != EOF)
    {
        memset(dp,0,sizeof dp);
        for (int i = 0 ; i <= K; i++)
            dp[1][i] = 1.0 / (K+1);
        for (int i = 2; i <= N; i++)
        {
            for (int j = 0; j<= K; j++)
            {
                if (j > 0) dp[i][j]+=dp[i-1][j-1] / (K+1); //choose one before j
                if (j < K) dp[i][j]+=dp[i-1][j+1] / (K+1); //choose one after j
                dp[i][j] += dp[i-1][j] / (K+1); //choose j
            }
        }
        double ans = 0;
        for (int i = 0 ; i <= K; i++)
            ans+=dp[N][i];
        printf("%.5lf\n", ans*100);
    }
}
