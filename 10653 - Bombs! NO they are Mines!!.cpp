#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
int R, C,N, row, cow, temp,times,startr,startc,endr,endc,ti,tj;
bool grid[1010][1010];
int dist[1010][1010];
int diri[] = {1,0,-1,0};
int dirj[] = {0,1,0,-1};
void bfs(int startr, int startc)
{
    memset(dist,-1,sizeof dist);
    queue < pair <int,int > > buff;
    buff.push(make_pair(startr,startc));
    dist[startr][startc] = 0;
    while (!buff.empty())
    {
        pair <int,int> node = buff.front();
        buff.pop();
        for (int i = 0 ; i < 4; i++)
        {
            ti = node.first+diri[i];
            tj = node.second+dirj[i];
            if (ti<0||tj<0||ti>=R||tj>=C||grid[ti][tj]==true)
            continue;
            if (dist[ti][tj]==-1)
            {
                dist[ti][tj] = dist[node.first][node.second]+1;
                buff.push(make_pair(ti,tj));
            }
            if (ti==endr&&tj==endc)
                return;
        }

    }
}
int main()
{
    while (1)
    {
        memset(grid,0,sizeof grid);
        cin>>R>>C;
        if (R==0&&C==0)break;
        cin>>N;
        for (int i = 0 ; i < N; i++)
        {
            cin>>row>>times;
            for (int i = 0 ; i < times; i++)
            {
                cin>>cow;
                grid[row][cow] = true;
            }
        }
        cin>>startr>>startc>>endr>>endc;
        bfs(startr,startc);
        cout<<dist[endr][endc]<<endl;
    }
}
