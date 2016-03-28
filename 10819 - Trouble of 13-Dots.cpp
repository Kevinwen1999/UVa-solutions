#include <iostream>
#include <cstring>
using namespace std;
inline int max(int a, int b) {return a > b ? a : b;}
int m, mm, n, weight[110], value[110];
int dp[10201];

int main()
{
    while(1)
    {
        cin>>m>>n;
        if (cin.eof()) break;
        mm = (m+200>2000)? m+200 : m;
        for (int i = 1 ; i <= n; i++)
            cin>>weight[i]>>value[i];
        memset(dp,-1,sizeof dp);
        dp[0] = 0;
        for (int i = 1 ; i <= n; i++)
            for (int j = mm; j >= weight[i]; j--)
                if (dp[j-weight[i]]!=-1)
                    dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
        int maxx = -1;
        for (int i = 0 ; i <= mm; i++)
        {
            if (i > m && i > 1800 && i <= 2000) continue;
            else maxx = max(maxx,dp[i]);
        }
        cout<<maxx<<endl;


    }
}
