#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50 + 5;
int N, t, len[MAXN], dp[2][MAXN*180+678];
int main()
{
    int T;
    cin>>T;
    for (int cnt = 1; cnt <= T; cnt++)
    {
        cin>>N>>t;
        for (int i = 1; i <= N; i++)
            cin>>len[i];
        for (int i = 0 ; i < t; i++)
            dp[0][i] = -1;
        dp[0][0] = 0;
        int flag = 1, ans = 0;
        for (int i = 1 ; i <= N; i++)
        {
            for (int j = 0; j < t; j++)
            {
                dp[flag][j] = dp[flag^1][j]; //smart
                if (j >=len[i] && dp[flag^1][j - len[i]] >= 0)
                    dp[flag][j] = max(dp[flag][j], dp[flag^1][j - len[i]] + 1);
                ans = max(ans, dp[flag][j]);
            }
            flag ^= 1;
        }
        for (int i = t-1 ;i >= 0; i--)
        {
            if (dp[flag^1][i] == ans)
                {cout<<"Case "<<cnt<<": "<<ans+1<<" "<<i + 678<<endl; break;}
        }
    }
}
