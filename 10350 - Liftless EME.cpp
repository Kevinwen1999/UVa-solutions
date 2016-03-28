#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string name;
int lift[150][20][20];
int dp[150][20];
int N, M;
int main()
{
    while(1)
    {
        cin>>name;
        if (cin.eof()) break;
        cin>>N>>M;
        for (int i = 0 ; i < N-1; i++)
            for (int j = 0 ; j < M; j++)
                for (int k = 0; k < M; k++)
                    cin>>lift[i][j][k];
        memset(dp,63,sizeof dp);
        memset(dp[0],0,sizeof dp[0]);
        for (int i = 0 ; i < N-1; i++)
            for (int j = 0 ; j < M; j++)
                for (int k = 0 ; k < M; k++)
                    dp[i+1][k] = min(dp[i+1][k],dp[i][j]+lift[i][j][k]+2);
        int ans = 0x3f3f3f3f;
        for (int i = 0 ;i < M; i++)
            ans = min(ans, dp[N-1][i]);
        cout<<name<<endl<<ans<<endl;
    }
}
