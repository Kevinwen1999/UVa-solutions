#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 600 + 10
#define INF 0x3f3f3f3f
int N, K;
int dist[MAXN];
int dp[MAXN][MAXN];
int main()
{
    while(cin>>N)
    {
        memset(dp,0,sizeof dp);
        cin>>K;
        N++; K++;
        for (int i = 1 ; i <= N; i++)
            cin>>dist[i];
        for (int i = 1 ; i <= N; i++)
            dp[i][1] = dp[i-1][1] + dist[i]; // can use as a prefix sum array
        for (int i = 1; i <= K; i++)
            dp[1][i] = dist[1];
        for (int i = 2; i <= N; i++)
            for (int j = 2; j <= K; j++)
            {
                dp[i][j] = INF;
                for (int m = 1; m < i; m++)
                    dp[i][j] = min(dp[i][j], max(dp[m][j-1],dp[i][1] - dp[m][1]));
            }
        cout<<dp[N][K]<<"\n";
    }
}
