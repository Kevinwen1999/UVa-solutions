#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 1e9
using namespace std;
const int MAXN = 1010;

int di[4] = {1,0,-1,0};
int dj[4] = {0,1,0,-1};
bool grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int M, N;
int B, S;
int mostdown[MAXN], mostup[MAXN];
int dp[MAXN][110];
void dfs_up(int i, int j)
{
    if (i<0||i>=N||j<0||j>=M) return;
    if (visited[i][j]) return;
    visited[i][j] = 1;
    if (!grid[i][j]) return;
    if (i+1<N && !grid[i+1][j])
        mostdown[j] = max(mostdown[j], i+1);
    for (int d = 0; d < 4; d++)
        dfs_up(i+di[d], j+dj[d]);
}
void dfs_down(int i, int j)
{
    if (i<0||i>=N||j<0||j>=M) return;
    if (visited[i][j]) return;
    visited[i][j] = 1;
    if (!grid[i][j]) return;
    if (i-1>=0 && !grid[i-1][j])
        mostup[j] = min(mostup[j], i-1);
    for (int d = 0; d < 4; d++)
        dfs_down(i+di[d], j+dj[d]);
}
int mincost(int j, int b)
{
    if (j>=M)
    {
        if (b==0) return 0;
        else return INF;
    }
    if (b<0) return INF;
    if (b==0) return 0;
    if (dp[j][b]!=-1) return dp[j][b];
    return dp[j][b] = min(mincost(j+1,b), mincost(j+S+1, b-1)+mostup[j]-mostdown[j]+1);
}
int main()
{
    while (scanf("%d%d", &N, &M)!=EOF)
    {
        scanf("%d%d", &B, &S);
        char tmp;
        memset(grid,0,sizeof grid);
        memset(visited,0,sizeof visited);
        memset(mostdown,0,sizeof mostdown);
        memset(mostup,63,sizeof mostup);
        memset(dp,-1,sizeof dp);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                scanf(" %c", &tmp);
                if (tmp=='#') grid[i][j] = 1;
            }
        }
        dfs_up(0,0);
        dfs_down(N-1,0);
        /*for (int i = 0; i < M; i++)
            cout<<mostup[i]<<" "<<mostdown[i]<<"\n";*/
        printf("%d\n", mincost(0,B));
    }
}
