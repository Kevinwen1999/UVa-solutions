#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2000 + 5;
int val[MAXN][MAXN];
int dp[MAXN];
int T, t, h,f, k;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>t>>h>>f;
        memset(val, 0, sizeof val);
        memset(dp,0,sizeof dp);
        for (int i = 0 ; i < t; i++)
        {
            cin>>k;
            for (int j = 0,tmp ; j < k; j++)
            {
                cin>>tmp;
                val[tmp][i]++;
            }
        }
        for (int i = 0, other, self; i <= h; i++)
            for(int j = 0 ; j < t; j++)
            {
                other = 0; //fly from another tree
                if (i >= f)
                    other = dp[i-f];
                self = 0; //climb up
                if (i >= 1)
                    self = val[i-1][j];
                val[i][j]+=max(other,self);
                dp[i] = max(dp[i],val[i][j]);
            }
        cout<<dp[h]<<endl;
    }
    cin>>T;
}
