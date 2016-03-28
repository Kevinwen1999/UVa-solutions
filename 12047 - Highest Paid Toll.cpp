#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
#define INF 99999999;
using namespace std;
inline int max(int a,int b){ return(a>b)?a:b;}
vector < pair <int,int> > adj1[10010];
vector < pair <int,int> > adj2[10010];
int dist1[10010],dist2[10010];
bool done1[10010],done2[10010];
queue <int> buff;
int N,V,E,s,t,p,a,b,c;
void spfa(int st, int dist[],bool done[], vector < pair <int,int> > adj[] )
{
    dist[st] = 0;
    done[st] = true;
    buff.push(st);
    while (!buff.empty())
    {
        int cur = buff.front();
        buff.pop();
        done[cur] = false;
        for (int nex = 0; nex < (int)adj[cur].size(); nex++)
        {
            pair <int,int> node = adj[cur][nex];
            if (dist[cur]+node.second<dist[node.first])
            {
                dist[node.first] = dist[cur]+node.second;
                if (!done[node.second])
                {
                    done[node.second] = true;
                    buff.push(node.first);
                }
            }
        }
    }
}

int main()
{
    cin>>N;
    while(N--)
    {
        cin>>V>>E>>s>>t>>p;
        for (int i = 0; i <= V; i++)
        {
            dist1[i] = INF;
            dist2[i] = INF;
            adj1[i].clear();
            adj2[i].clear();
        }
        for (int i = 0 ; i < E; i++)
        {
            cin>>a>>b>>c;
            adj1[a].push_back(make_pair(b,c));
            adj2[b].push_back(make_pair(a,c));
        }
        memset(done1,0,sizeof done1);
        memset(done2,0,sizeof done2);
        spfa(s,dist1,done1,adj1);
        spfa(t,dist2,done2,adj2);
        int curmax = -1;
        for (int i = 1; i <= V; i++)
        {
            for (int j = 0; j < (int)adj1[i].size(); j++)
            {
                pair <int,int> node = adj1[i][j];
                if (dist1[i]+dist2[node.first]+node.second<=p)
                    curmax = max(curmax,node.second);
            }
        }
        cout<<curmax<<endl;
    }
    return 0;
}
