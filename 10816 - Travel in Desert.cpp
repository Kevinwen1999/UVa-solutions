#include <iostream>
#include <queue>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#define MAXE 10010
#define MAXN 110
#define EPS 1e-9
using namespace std;
const double INF = 9999999.0;
struct path
{
    int to;
    double length, maxtemp;
} cur;
double dist[MAXN];
bool done[MAXN];
vector <path> adj[MAXE];
int N, E, S, T, par[MAXN];
queue <int> buff;
void spfa(double mt)
{
    while (!buff.empty()) buff.pop();
    for (int i = 0; i <= N; i++)
    {
        dist[i] = INF;
        done[i] = 0;
        par[i] = -1;
    }
    dist[S] = 0; done[S] = 1; buff.push(S);
    int u;
    while (!buff.empty())
    {
        u = buff.front();
        buff.pop();
        done[u] = 0;
        for (int i = 0; i < (int)adj[u].size(); i++)
        {
            cur = adj[u][i];
            if (cur.maxtemp > mt) continue;
            if (dist[u] + cur.length >= dist[cur.to]) continue;
            dist[cur.to] = dist[u] + cur.length;
            par[cur.to] = u;
            if (!done[cur.to])
            {
                buff.push(cur.to);
                done[cur.to] = 1;
            }
        }
    }
}
void print(int u)
{
    if (u==-1) return;
    print(par[u]);
    cout<<u;
    if (u != T) cout<<" ";
    else cout<<"\n";
}
int main()
{
    //ios::sync_with_stdio(0);
    while (cin>>N>>E)
    {
        cin>>S>>T;
        double c, d;
        for (int i = 0; i <= N; i++)
            adj[i].clear();
        for (int i= 0, a; i < E; i++)
        {
            cin>>a>>cur.to>>cur.maxtemp>>cur.length;
            adj[a].push_back(cur);
            a = a^cur.to; cur.to = a^cur.to; a = a ^ cur.to;
            adj[a].push_back(cur);
        }
        double l = 20, r = 50;
        while (fabs(l-r) > EPS) // binary search the mininum maxtemp
        {
            double mid = (l+r)/2;
            spfa(mid);
            if (dist[T]!=INF)
                r = mid;
            else
                l = mid;
        }
        spfa(r); // VERY IMPORTANT, dont use l
        print(T);
        printf("%.1f %.1f\n",dist[T],r);
    }
}
