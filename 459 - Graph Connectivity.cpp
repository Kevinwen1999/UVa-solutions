#include <iostream>
#include <cstring>
using namespace std;
int N;
int adj[26][26], V, visited[26],ii,jj,cnt = 0;
string temp;
void dfs( int v)
{
    visited[v] = true;
    for (int i = 0 ; i <= V; i++)
    {
        if (adj[v][i]&&!visited[i])
            dfs(i);
    }
}
int main()
{
    cin>>N;
    cin>>temp;
    for (int times = 0 ; times < N; times++)
    {
        cnt = 0;
        memset(adj,0,sizeof adj);
        memset(visited,0,sizeof visited);
        V = temp[0] - 'A';
        cin>>temp;
        while(temp.size()>1&&!cin.eof())
        {
            ii = temp[0] - 'A'; jj = temp[1] - 'A';
            adj[ii][jj] = 1; adj[jj][ii] = 1;
            cin>>temp;
        }
        for (int i = 0 ; i <= V ; i++)
        {
            if (!visited[i])
            {
                cnt++;
                dfs(i);
            }
        }
        if (times==0)cout<<cnt;
        else cout<<endl<<cnt;

    }
}
