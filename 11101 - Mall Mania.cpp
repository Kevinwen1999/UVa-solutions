#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
int p1, p2;
bool grid[2048][2048];
int dist[2048][2048];
int dirx[4] = {1,0,-1,0};
int diry[4] = {0,1,0,-1};
int tempx, tempy;
struct point
{
    int x; int y;
} temp,temp1;
int main()
{
    while(scanf("%d", &p1) && p1 )
    {
        memset(grid,0,sizeof grid);
        memset(dist, -1, sizeof dist);
        queue <point> buff;
        for (int i = 0,x,y; i < p1; i++)
        {
            scanf("%d%d",&x,&y);
            dist[x][y] = 0;
            temp.x = x; temp.y = y;
            buff.push(temp);
        }
        scanf("%d", &p2);
        for (int i = 0,x,y; i < p2; i++)
        {
            scanf("%d%d", &x,&y);
            grid[x][y] = true;
        }
        bool f = false;
        while (!buff.empty()&&!f)
        {
            temp = buff.front();
            buff.pop();
            if (grid[temp.x][temp.y])
            {
                printf("%d\n", dist[temp.x][temp.y]);
                f = true;
                break;
            }
            for (int i = 0 ; i <4; i++)
            {
                tempx = temp.x+dirx[i];
                tempy = temp.y+diry[i];
                if (tempx>=0&&tempy>=0&&tempx<=2000&&tempy<=2000)
                {
                    if (dist[tempx][tempy]==-1)
                    {
                        dist[tempx][tempy] = dist[temp.x][temp.y]+1;
                        temp1.x = tempx;
                        temp1.y = tempy;
                        buff.push(temp1);
                    }
                }
            }
        }
/*
        cout<<endl;
        for (int i = maxx ; i >=0; i--)
        {
            for (int j = 0 ; j <= maxy; j++)
                cout<<grid[i][j];
            cout<<endl;
        }
        cout<<endl;
        for (int i = maxx ; i >=0; i--)
        {
            for (int j = 0 ; j <= maxy; j++)
                cout<<dist[i][j];
            cout<<endl;
        }*/
        //printf("%d\n", ans);
    }
}
