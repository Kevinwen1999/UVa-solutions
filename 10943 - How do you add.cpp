#include <iostream>
#include <cstring>

using namespace std;
int N, K;
long long dp[110][110];
long long DP(int n, int k)
{
    if (dp[n][k]!=-1)return dp[n][k];
    if (k==0)return 0;
    dp[n][k] = 0;
    for (int i = n; i>=0; i--)
        dp[n][k]=(dp[n][k]+DP(i,k-1))%1000000;
    return dp[n][k];
}
int main()
{
    while(1)
    {
        cin>>N>>K;
        if (N==0&&K==0)break;
        memset(dp,-1,sizeof dp);
        for (int i = 0 ; i <= N; i++)
            dp[i][1] = 1;
        cout<<(DP(N,K))<<endl;
    }
    return 0;
}
