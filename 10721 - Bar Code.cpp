#include <iostream>
#include <cstring>
using namespace std;
int n, k , m;
long long dp[55][55];
int main()
{
    while(cin>>n>>k>>m)
    {
        memset(dp,0,sizeof dp);
        for (int i = 1 ; i <= n&&i<=m; i++) dp[1][i] = 1;
        for (int i = 2; i <= k; i++)
            for (int j = i; j <= n; j++)
                for (int k = 1; k <= m && k < j; k++)
                    dp[i][j]+=dp[i-1][j-k];
        cout<<dp[k][n]<<endl;
    }
}
