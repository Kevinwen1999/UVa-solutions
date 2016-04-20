#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 80
#define MAXK 10
#define NINF -99999999
using namespace std;
int N, k;
int ori[MAXN][MAXN];
long long dp[MAXN][MAXN][MAXK][3];
bool visited[MAXN][MAXN][MAXK][3];
long long dfs(int r, int c, int kk, int stat)
{
    int tk = kk; long long t1, t2, t3, ans;
    if (visited[r][c][kk][stat])
        return dp[r][c][kk][stat];
    visited[r][c][kk][stat] = true;
    if (kk == k && ori[r][c]<0)
        return dp[r][c][kk][stat] = NINF;
    if (r==N-1&&c==N-1)
        return dp[r][c][kk][stat] = ori[r][c];
    if (ori[r][c]<0) tk++;
    if (stat ==0)
    {
        t1 = t2 = t3 = NINF;
        if (r < N-1)
            t1 = dfs(r+1, c, tk, 0);
        if (c>=1)
            t2 = dfs(r, c-1, tk, 2);
        if (c < N-1)
            t3 = dfs(r,c+1, tk, 1);
        ans = max(t1, max(t2, t3));
        if (ans!=NINF&&ans + ori[r][c] > dp[r][c][kk][stat])
            dp[r][c][kk][stat] = ans + ori[r][c];
    }
    else if (stat == 1)
    {
        t1 = t2 = t3 = NINF;
        if (r < N-1)
            t1 = dfs(r+1, c, tk, 0);
        if (c < N-1)
            t3 = dfs(r,c+1, tk, 1);
        ans = max(t1, max(t2, t3));
        if (ans!=NINF&&ans + ori[r][c] > dp[r][c][kk][stat])
            dp[r][c][kk][stat] = ans + ori[r][c];
    }
    else if (stat == 2)
    {
        t1 = t2 = t3 = NINF;
        if (r < N-1)
            t1 = dfs(r+1, c, tk, 0);
        if (c>=1)
            t2 = dfs(r, c-1, tk, 2);
        ans = max(t1, max(t2, t3));
        if (ans!=NINF&&ans + ori[r][c] > dp[r][c][kk][stat])
            dp[r][c][kk][stat] = ans + ori[r][c];
    }
    return dp[r][c][kk][stat];
}
int main()
{
    int T  = 0;
    while(cin>>N>>k)
    {
        if (N==0&&k==0) break;
        T++;
        for (int i = 0 ; i < N; i++)
            for (int j = 0 ; j < N; j++)
                cin>>ori[i][j];
        for (int i = 0 ;i < N; i++)
            for (int j = 0 ; j < N; j++)
                for (int kk = 0 ; kk <= k; kk++)
                    for (int l = 0; l < 3; l++)
                        dp[i][j][kk][l] = NINF;
        memset(visited,0,sizeof visited);
        long long a = dfs(0,0,0,0);
        if (a== NINF)
            cout<<"Case "<<T<<": "<<"impossible"<<endl;
        else
            cout<<"Case "<<T<<": "<<a<<endl;
    }
}
