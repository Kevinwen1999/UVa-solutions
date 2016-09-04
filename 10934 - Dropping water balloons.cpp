#include <bits/stdc++.h>
using namespace std;
unsigned long long N, K;
unsigned long long dp[105][65]; // number of floors that can be evaluated with given amount of balloons and experiments
/*unsigned long long DP(int nk, int ne) // number of ballons and number of experiments
{
    if (dp[nk][ne]!=-1) return dp[nk][ne];
    unsigned long long &ans = dp[nk][ne];
    if (nk == 0 || ne == 0) return ans = 0;
    return ans = DP(nk-1, ne-1) + 1 + DP(nk, ne-1);
}*/
int main()
{
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j < 64; j++)
        {
            if (j==1)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + 1 + dp[i][j-1];
        }
    }
    while (scanf("%llu%llu", &K, &N)==2 && K)
    {
        //memset(dp, -1, sizeof dp);
        //DP(K,63);
        bool OK = true;
        for (int i = 1; i <= 63 && OK; i++)
        {
            if (dp[K][i] >= N)
            {
                OK = false;
                printf("%d\n", i);
            }
        }
        if (OK) puts("More than 63 trials needed.");
    }
}
