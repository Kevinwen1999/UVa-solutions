#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 100+10;
int dp[MAXN][2*MAXN], diff[MAXN];
int adj[MAXN][MAXN];
vector <int> team[MAXN][2];
int color[MAXN];
int totcol, N;
bool dfs(int cur, int col) //bipartite graph check
{
    color[cur] = col; // 1 and 2
    team[totcol][col-1].push_back(cur);
    for (int i = 0; i < N; i++)
    {
        if (i!=cur && !(adj[cur][i] && adj[i][cur])) // i and cur does not know each other
        {
            if (color[i] > 0 && color[i] == color[cur])
                return false; //color on adjacent sides should be different
            if (!color[i] && !dfs(i,3-col))
                return false;
        }
    }
    return true;
}
bool build() // build graph based on connected component
{
    totcol = 0;
    memset(color, 0, sizeof color);
    for (int i = 0 ; i < N; i++)
    {
        if (!color[i])
        {
            team[totcol][0].clear();
            team[totcol][1].clear();
            if (!dfs(i,1)) return false;
            diff[totcol] = team[totcol][0].size()-team[totcol][1].size(); //difference between nodes of two colors
            totcol++; // increace # of connected components
        }
    }
    return true;
}
void printans(int ans)
{
    vector <int> team1, team2;
    for (int i = totcol-1; i >=0; i--) // for each connected component
    {
        int t;
        if (dp[i][ans-diff[i]+N]) //  find out which color is chosen
            {t = 0; ans -= diff[i];}
        else
            {t = 1; ans += diff[i];}
        for (int j = 0; j < team[i][t].size(); j++)
            team1.push_back(team[i][t][j]);
        for (int j = 0; j < team[i][1^t].size(); j++)
            team2.push_back(team[i][1^t][j]);
    }
    printf("%d", team1.size());
    for(int i = 0; i < team1.size(); i++) printf(" %d", team1[i]+1);
    printf("\n");
    printf("%d", team2.size());
    for(int i = 0; i < team2.size(); i++) printf(" %d", team2[i]+1);
    printf("\n");
}
void DP()
{
    //dp[i][j+N] rep the existance of state when on ith connected component and the difference between two groups is j
    memset(dp,0,sizeof dp);
    dp[0][0+N]=1; //j need to +N because j can be down to -N
    for (int i = 0; i < totcol; i++)
    {
        for (int j = -N; j <=N; j++)
        {
            if (dp[i][j+N])
            {
                dp[i+1][j+N+diff[i]] = 1;
                dp[i+1][j+N-diff[i]] = 1;
            } // partition two colors to different groups
        }
    }
    for (int ans = 0; ans <= N; ans++)
    {
        if (dp[totcol][ans+N])
            {printans(ans); return;}
        if (dp[totcol][-ans+N])
            {printans(-ans); return;}
    }
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        memset(adj,0,sizeof adj);
        for (int cur = 0; cur < N; cur++)
        {
            int nex;
            while (scanf("%d", &nex) && nex)
                adj[cur][nex-1] = 1;
        }
        if (!build()) printf("No solution\n");
        else  DP();
        if (T) printf("\n");
    }
    return 0;
}
