#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
#define UNVISITED 0
using namespace std;
const int MAXN = 30;
int N, M;
int tot;
vector <string> names;
map <string , int> m;
vector <int> buff; // for SCC
vector <int> adj[MAXN];
int dfs_num[MAXN], dfs_low[MAXN];
bool in_stack[MAXN];
int dfsnumcount;
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
        while (1)
        {
            int v = buff.back(); buff.pop_back(); in_stack[v] = false;
            cout<<names[v];
            if (v == cur) break;
            cout<<", ";
        }
        cout<<"\n";
    }
}
int main()
{
    int cnt = 0;
    while (scanf("%d%d", &N, &M) == 2)
    {
        tot = 0;
        names.clear();
        m.clear();
        if (!(N+M)) break;
        for (int i = 0; i < M; i++)
        {
            string u, v;
            cin>>u>>v;
            if (m.count(u)==0) m[u] = tot++, names.push_back(u);
            if (m.count(v)==0) m[v] = tot++, names.push_back(v);
            adj[m[u]].push_back(m[v]);
        }
        memset(dfs_num,0,sizeof dfs_num);
        memset(dfs_low,0,sizeof dfs_low);
        memset(in_stack,0,sizeof in_stack);
        dfsnumcount = 0;
        cout<<"Calling circles for data set "<<++cnt<<":\n";
        for (int i = 0; i < N; i++)
        {
            if (dfs_num[i] == UNVISITED)
                SCC(i);
        }
        cout<<"\n";
    }
}
