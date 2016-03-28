#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
int E, N, T,temp;
bool adj[2550][2550],visited[2550],isone = false;
int day[2550];
void bfs(int start)
{
    isone = true;
    memset(visited,0,sizeof visited);
    memset(day,0,sizeof day);
    visited[start] = true;
    queue < pair <int,int> > buff;
    buff.push(make_pair(start,1));
    while (!buff.empty())
    {
        pair <int,int> cur = buff.front();
        buff.pop();
        for (int i = 0 ; i < E; i++)
        {
            if (adj[cur.first][i]&&!visited[i])
            {
                isone = false;
                visited[i] = true;
                day[cur.second] +=1;
                buff.push(make_pair(i,cur.second+1));
            }
        }
    }
}
int main()
{
    cin>>E;
    for (int i = 0; i <E; i++)
    {
        cin>>N;
        for (int j = 0 ; j < N; j++)
        {
            cin>>temp;
            adj[i][temp] = true;
        }
    }
    cin>>T;
    for (int i = 0 ; i < T; i++)
    {
        cin>>temp;
        bfs(temp);
        int curmax = -1, index = 1;
        for (int i = 1; i <=E; i++)
        {
            if (day[i]>curmax)
            {
                curmax = day[i];
                index = i;
            }
        }
        if (isone)
        cout<<"0"<<endl;
        else
        cout<<curmax<<" "<<index<<endl;
    }
    return 0;
}
