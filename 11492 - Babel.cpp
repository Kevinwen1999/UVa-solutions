#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define MP make_pair
#define INF 0x3f3f3f3f
using namespace std;
struct node
{
    string left;
    string right;
    string value;
};
int V;

string st, fin;
node temp,temp2;
int dist[2020];
bool done[2020];
int main()
{
    while (cin>>V&&V)
    {
        cin>>st>>fin;
        vector <node> graph;
        vector < pair <int,int> > adj[2020];
        memset(dist,63,sizeof dist);
        memset(done,0,sizeof done);
        for (int i = 0 ; i < V; i++)
        {
            cin>>temp.left>>temp.right>>temp.value;
            graph.push_back(temp);
        }
        for (int i = 0 ; i < V; i++)
            for (int j = i+1 ; j < V; j++)
            {
                temp = graph[i];
                temp2 = graph[j];
                if (temp.left==temp2.left||temp.left==temp2.right||temp.right==temp2.left||temp.right==temp2.right)
                {
                    if (temp.value[0]!=temp2.value[0])
                    {
                        adj[i].push_back(MP(j,temp2.value.size()));
                        adj[j].push_back(MP(i,temp.value.size()));
                    }
                }
            }

        for (int i = 0 ; i <V; i++)
        {
            temp = graph[i];
            if (temp.left==st||temp.right==st)
            {
                adj[2015].push_back(MP(i,temp.value.size()));
                //adj[i].push_back(MP(2015,temp.value.size()));
            }
            if (temp.left==fin||temp.right==fin)
            {
                //adj[2016].push_back(MP(i,temp.value.size()));
                adj[i].push_back(MP(2016,0));
            }
        }
        dist[2015] = 0;
        done[2015] = true;
        queue <int> buff;
        buff.push(2015);
        int top;
        pair <int,int> next;
        while(!buff.empty())
        {
            top = buff.front();
            buff.pop();
            done[top] = false;
            for (int i = 0 ; i < adj[top].size(); i++)
            {
                next = adj[top][i];
                if (dist[top]+next.second < dist[next.first])
                {
                    dist[next.first] = dist[top]+ next.second;
                    if (!done[next.first])
                    {
                        buff.push(next.first);
                        done[next.first] = true;
                    }
                }
            }
        }
        if (dist[2016]==INF)
            cout<<"impossivel"<<endl;
        else
            cout<<dist[2016]<<endl;
    }
}
