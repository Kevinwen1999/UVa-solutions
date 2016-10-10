#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 10;
int N;
int tot, start;
int grid[MAXN][MAXN], dist[MAXN][MAXN], span[MAXN][MAXN];
int dp[1<<MAXN][MAXN];
int di[8] = {1,1,-1,-1,2,2,-2,-2};
int dj[8] = {2,-2,2,-2,1,-1,1,-1};
void bfs(int si, int sj)
{
    queue <int> ic, jc;
    int curi, curj, ni, nj, src = grid[si][sj];
    memset(span, -1, sizeof span);
    ic.push(si), jc.push(sj);
    span[si][sj] = 0;
    while (!ic.empty())
    {
        curi = ic.front(); ic.pop();
        curj = jc.front(); jc.pop();
        for (int i = 0; i < 8; i++)
        {
            ni = curi+di[i]; nj = curj+dj[i];
            if (ni<0||nj<0||ni>=8||nj>=8) continue;
            if (grid[ni][nj] == -2) continue;
            if (span[ni][nj] == -1)
            {
                span[ni][nj] = span[curi][curj] + 1;
                ic.push(ni); jc.push(nj);
                if (grid[ni][nj] > -1)
                    dist[src][grid[ni][nj]] = span[ni][nj];
            }
        }
    }
}
int DP(int mask, int cur)
{
    if (!mask)
        return 0;
    if (dp[mask][cur]!=-1) return dp[mask][cur];
    int ans = INF;
    for (int i = 0; i < tot; i++)
    {
        if (mask & (1<<i))
            ans = min(ans, DP(mask ^ (1<<i), i) + dist[cur][i]);
    }
    return dp[mask][cur] = ans;
}
int main()
{
    ios::sync_with_stdio(0);

    int T; cin>>T;
    while (T--)
    {
        cin>>N;
        tot = 1;
        char tmp;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cin>>tmp;
                if (tmp=='P')
                    grid[i][j] = tot++;
                else if (tmp=='k')
                {
                    grid[i][j] = 0;
                }
                else if (tmp=='.')
                    grid[i][j] = -1;
                else
                    grid[i][j] = -2;
            }
        }
        memset(dist, 63, sizeof dist);
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (grid[i][j] >-1 )
                    bfs(i,j);
        memset(dp,-1,sizeof dp);
        int ans = DP((1<<tot)-1-1, 0);
        if (ans <= N)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
