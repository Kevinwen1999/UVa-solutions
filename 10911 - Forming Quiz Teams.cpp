#include <bits/stdc++.h>

using namespace std;

const int MAXN = 16;
const double INF = 2e9;
int N;
int x[MAXN], y[MAXN];
double dp[(1<<MAXN)];
char in[30];
double dist(int i, int j)
{
    return hypot(x[i]-x[j], y[i]-y[j]);
}
double recur(int b)
{
    if (dp[b] || b == (1<<N)-1) return dp[b];
    dp[b] = INF;
    int bnext = b;
    for (int i = 0 ; i < N; i++)
    {
        if (b & (1<<i)) continue;
        for (int j = i + 1; j < N; j++)
        {
            if (b & (1<<j)) continue;
            bnext = b | (1<<i) | (1<<j);
            dp[b] = min(dp[b], recur(bnext) + dist(i,j));
        }
    }
    return dp[b];
}
int main()
{
    int cnt = 0;
    while (scanf("%d", &N))
    {
        if (!N) break;
        N*=2;
        for (int i = 0 ; i < N; i++)
        {
            scanf("%s %d %d", &in, &x[i], &y[i]);
        }
        memset(dp,0,sizeof dp);
        printf("Case %d: %.2lf\n", ++cnt, recur(0));
    }
    return 0;
}
