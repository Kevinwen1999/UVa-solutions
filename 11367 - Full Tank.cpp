#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define INF 99999999
inline int min(int a, int b){return a<b?a:b;}
int V, E, price[1010], Q, st, ed, capa,a,b,c;
vector < pair <int,int> > adjlist[1010];
int dist[1010][110];
bool done[1010][110];
void spfa(int st)
{
    for (int i = 0 ; i <= V; i++)
        for (int j = 0 ; j <= 110 ; j++)
            dist[i][j] = INF;
    memset(done,0,sizeof done);
    queue < pair <int,int> > buff;
    dist[st][0] = 0;
    done[st][0] = true;
    buff.push(make_pair(st,0));
    while (!buff.empty())
    {
        pair <int,int> top = buff.front();
        buff.pop();
        int curnode = top.first, curfull = top.second;
        done[curnode][curfull] = false;
        if (curfull+1<=capa)
            {
                if (dist[curnode][curfull]+price[curnode]<dist[curnode][curfull+1])
                {
                    dist[curnode][curfull+1] = dist[curnode][curfull]+price[curnode];
                    if (!done[curnode][curfull+1])
                    {
                        done[curnode][curfull+1] = true;
                        buff.push(make_pair(curnode,curfull+1));
                    }
                }
            }
        for (int i = 0 ; i < (int)adjlist[curnode].size(); i++)
        {
            pair <int,int> next = adjlist[curnode][i];
            int nextnode = next.first, nextfull= next.second;
            if (curfull>=nextfull)
            {
                if (dist[curnode][curfull]<dist[nextnode][curfull-nextfull])
                {
                    dist[nextnode][curfull-nextfull] = dist[curnode][curfull];
                    if (!done[nextnode][curfull-nextfull])
                    {
                        done[nextnode][curfull-nextfull]=true;
                        buff.push(make_pair(nextnode,curfull-nextfull));
                    }
                }
            }
        }
    }
}
int main()
{
    cin>>V>>E;
    for (int i = 0; i < V; i++)
        cin>>price[i];
    for (int i = 0 ; i < E; i++)
    {
        cin>>a>>b>>c;
        adjlist[a].push_back(make_pair(b,c));
        adjlist[b].push_back(make_pair(a,c));
    }
    cin>>Q;
    for (int i = 0 ; i < Q; i++)
    {
        cin>>capa>>st>>ed;
        spfa(st);
        int curmin = INF;
        for (int j = 0; j <= 100; j++)
            curmin = min(curmin,dist[ed][j]);
        if (curmin==INF) cout<<"impossible"<<endl;
        else cout<<curmin<<endl;
    }
    return 0;
}
