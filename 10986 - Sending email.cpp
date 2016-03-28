#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define INF 0x3f3f3f3f
using namespace std;
vector < vector < pair <int,int> > > adjlist;
bool done[20001];
int dist[20001];
int n,m,s,t;
int main()
{
    int N; cin>>N;
    for (int cnt = 1; cnt <= N; cnt++)
    {
        cin>>n>>m>>s>>t;
        memset(done, 0 , sizeof done);
        memset(dist, INF, sizeof dist);
        adjlist.clear();
        adjlist.resize(n+1);
        queue <int> buff;
        for (int i = 0 ;i < m; i++)
        {
            int a, b, w;
            cin>>a>>b>>w;
            adjlist[a].push_back(make_pair(b,w));
            adjlist[b].push_back(make_pair(a,w));
        }
        //---------------------------------------
        dist[s] = 0;
        done[s] = true;
        buff.push(s);
        while (!buff.empty())
        {
            int temp = buff.front();
            buff.pop();
            done[temp] = false;
            for (int i = 0 ; i < (int)adjlist[temp].size(); i++)
            {
                pair <int,int> v = adjlist[temp][i];
                if (dist[temp]+v.second < dist[v.first])
                {
                    dist[v.first] = dist[temp]+v.second;
                    if (!done[v.first])
                    {
                        done[v.first] = true;
                        buff.push(v.first);
                    }
                }
            }
        }
        cout<<"Case #"<<cnt<<": ";
        if (dist[t]==INF)
            cout<<"unreachable"<<endl;
        else
            cout<<dist[t]<<endl;
    }
}
