#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <iomanip>
using namespace std;
inline int max(int x, int y){return x > y? x: y;}
int V, E,Q,x,y,w,cnt=1,curmax1,curmax2;
vector < pair <int, pair <int, int > > > edgelist;
int adj[120][120];
int visited[120];
class UnionFind
{
private:
    vector <int> p;
    vector <int> ranks;
public:
    UnionFind (int N){ranks.resize(N+1); p.resize(N+1); for (int i = 0; i <= N; i++) p[i] = i; for (int i = 0 ; i <=N; i++) ranks[i] = 0;}
    int findset(int i) {return (p[i] == i) ? i: (p[i] = findset(p[i]));}
    bool issameset(int i, int j){return findset(i)==findset(j);}
    void unionset(int i, int j)
    {
        if (!issameset(i,j))
        {
            int x = findset(i), y = findset(j);
            if (ranks[x]>ranks[y])
                p[y] = p[x];
            else
            {
                p[x] = p[y];
                if (ranks[x]==ranks[y])
                    ranks[y]++;
            }
        }
    }
};
int bfs(int start,int end)
{
    queue <int> buff;
    buff.push(start);
    visited[start] = 0;
    while (!buff.empty())
    {
        int cur = buff.front();buff.pop();
        for (int i = 1; i <= V; i++)
        {
            if (adj[cur][i]!=-1&&visited[i]==-1)
            {
                if (adj[cur][i]>visited[cur])
                    visited[i] = adj[cur][i];
                else
                    visited[i] = visited[cur];
                if (i==end) break;
                buff.push(i);
            }
        }
    }
    return visited[end];
}

int main()
{
    while (1)
    {
        cin>>V>>E>>Q;
        if (V==0&&E==0&&Q==0)break;
        edgelist.clear();
        memset(adj,-1,sizeof adj);
        for (int i = 0 ; i < E; i++)
        {
            cin>>x>>y>>w;
            edgelist.push_back(make_pair(w,make_pair(x,y)));

        }
        sort(edgelist.begin(),edgelist.end());
        UnionFind uf(V);
        for (int i = 0 ; i < E; i++)
        {
            pair <int, pair <int, int > > top = edgelist[i];
            if (!uf.issameset(top.second.first,top.second.second))
            {
                uf.unionset(top.second.first,top.second.second);
                adj[top.second.first][top.second.second] = top.first;
                adj[top.second.second][top.second.first] = top.first;
            }
        }
        if (cnt>1)cout<<endl;
        cout<<"Case #"<<cnt<<endl;
        for (int i = 0 ; i < Q; i++)
        {
            curmax1 = 0;
            memset(visited,-1,sizeof visited);
            cin>>x>>y;
            curmax1 = bfs(x,y);
            if (!uf.issameset(x,y))cout<<"no path"<<endl;
            else cout<<curmax1<<endl;
        }
        cnt++;
    }
}
