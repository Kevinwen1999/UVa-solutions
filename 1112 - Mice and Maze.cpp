#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
#define INF 999999999
using namespace std;
int testcase;
int V, E, des, timelim,a,b,c,sum;
long dist[200];
bool done[200];
vector < pair <int , int> > adjacencyList[200];
void spfa(int st)
{
    for (int i = 0 ; i <= V; i++)
        dist[i] = INF;
    memset(done,0,sizeof done);
    queue <int> buff;
    dist[st] = 0;
    buff.push(st);
    done[st] = true;
    while (!buff.empty())
    {
        int temp = buff.front();
        buff.pop();
        done[temp] = false;
        for (int i = 0; i < (int)adjacencyList[temp].size(); i++)
        {
            pair<int,int> v = adjacencyList[temp][i];
            if ((dist[temp]+ v.second) < dist[v.first])
            {
                dist[v.first] = dist[temp]+v.second;
                if (done[v.first]==false)
                {
                    buff.push(v.first);
                    done[v.first] = true;
                }
            }
        }

    }
}

int main()
{
    cin>>testcase;
    while (testcase--)
    {
        for (int i = 0 ; i <200; i++)
            adjacencyList[i].clear();
        cin>>V>>des>>timelim>>E;
        for (int i = 0 ; i < E; i++)
        {
            cin>>a>>b>>c;
            adjacencyList[b].push_back(make_pair(a,c));
        }
        spfa(des);
        sum = 0;
        for (int i = 1;i <= V; i++)
        {
            if (dist[i]<=timelim)
            sum++;
        }
        cout<<sum<<endl;
        if (testcase)cout<<endl;
    }
}
