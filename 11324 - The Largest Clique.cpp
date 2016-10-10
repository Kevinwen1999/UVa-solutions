#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
using namespace std;
#define UNVISITED 0
#define MAXN 1010
vector <int> buff; // for SCC
vector <int> adj[MAXN],DAG[MAXN];
int dfs_num[MAXN], dfs_low[MAXN];
bool in_stack[MAXN];
int dfsnumcount, scc_count;
int scc_set[MAXN], num[MAXN];
int dp[MAXN];
int N,M;
void init()
{
    buff.clear();
    for (int i = 0; i <= N; i++)
        adj[i].clear(), DAG[i].clear();
    memset(dfs_num, 0, sizeof dfs_num);
    memset(dfs_low,0,sizeof dfs_low);
    memset(in_stack,0,sizeof in_stack);
    memset(scc_set,0,sizeof scc_set);
    memset(num,0,sizeof num);
    memset(dp,0,sizeof dp);
    dfsnumcount = 0;
    scc_count = 0;
}
void SCC(int cur)
{
    dfs_num[cur] = dfs_low[cur] = ++dfsnumcount;
    buff.push_back(cur); // push onto SCC stack
    in_stack[cur] = true;
    for (int i = 0; i < adj[cur].size(); i++)
    {
        int v = adj[cur][i];
        if (dfs_num[v] == UNVISITED)
            SCC(v);
        if (in_stack[v]) // condition for update
            dfs_low[cur] = min(dfs_low[cur], dfs_low[v]);
    }
    if (dfs_num[cur] == dfs_low[cur]) // if cur is the start of a SCC
    {
        scc_count++;
        while (1)
        {
            int v = buff.back(); buff.pop_back(); in_stack[v] = false;
            scc_set[v] = scc_count;
            num[scc_count]++;
            if (v == cur) break;
        }
    }
}
void buildgraph() // build DAG based on SCC sets
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < (int)adj[i].size(); j++)
        {
            int v = adj[i][j];
            if (scc_set[i]!=scc_set[v]) // if vertices are in different SCC sets
                DAG[scc_set[i]].push_back(scc_set[v]);
        }
    }
}
int DP (int u) // Longest Path on DAG
{
    if (dp[u]) return dp[u];
    else if (DAG[u].size()==0) return num[u];

    int ans = 0;
    for (int i = 0; i < (int)DAG[u].size(); i++)
    {
        int v = DAG[u][i];
        ans = max(ans, DP(v));
    }
    return dp[u] = ans + num[u];
}
int main()
{
    ios::sync_with_stdio(0);
    int T; cin>>T;
    while (T--)
    {
        cin>>N>>M;
        init();
        for (int i = 0; i < M; i++)
        {
            int a, b; cin>>a>>b;
            adj[a].push_back(b);
        }
        for (int i = 1; i <= N; i++)
            if (dfs_num[i]==UNVISITED)
                SCC(i);
        buildgraph();
        int ans = 0;
        for (int i = 1; i <= scc_count; i++)
            ans = max(ans, DP(i));
        cout<<ans<<"\n";
    }
}
