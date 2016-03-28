#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
int N,R,C;
string name;
int grid[110][110];
int dp[110][110];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int DP(int i, int j)
{
    if (dp[i][j]!=-1) return dp[i][j];
    int &ans = dp[i][j] = 1;
    for (int a = 0,ti,tj; a < 4; a++)
    {
        ti = i+dx[a]; tj = j+dy[a];
        if (ti<0||tj<0||ti>=R||tj>=C) continue;
        if (grid[ti][tj]>=grid[i][j]) continue;
        ans = max(ans, DP(i+dx[a],j+dy[a])+1);
    }
    return ans;
}
int main()
{
    cin>>N;
    while(N--)
    {
        cin>>name>>R>>C;
        for (int i = 0 ; i < R; i++)
            for (int j = 0 ; j < C; j++)
                cin>>grid[i][j];
        int ans = 0;
        memset(dp,-1,sizeof dp);
        for (int i = 0 ;i < R; i++)
            for (int j = 0 ; j < C; j++)
                ans = max(ans, DP(i,j));
        cout<<name<<": "<<ans<<endl;
    }
}
