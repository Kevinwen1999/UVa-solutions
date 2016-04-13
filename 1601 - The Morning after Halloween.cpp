#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
struct node
{
    int ia=0, ib=0, ic=0;
    node(int q, int w, int e){ia = q; ib = w; ic = e;}
};
int w, h, n;
char graph[20][20];
int idx[20][20];
int start[3], goal[3];
int di[5] = {1,0,-1,0,0}, dj[5] = {0,1,0,-1,0};
int visited[301][301][301];
int oa, ob, oc, ta, tb, tc,ti,tj;
int main()
{
    int srt = 1;
    for (int i = 0 ; i < 16; i++)
        for (int j = 0 ; j < 16; j++)
        {
            idx[i][j] = srt;
            srt++;
        }
    while(cin>>w>>h>>n)
    {
        //input
        if (w==0&&h==0&&n==0) break;
        string in;
        vector<int> adj[301];
        getline(cin,in);
        for (int i = 0 ; i < h; i++)
        {
            getline(cin,in);
            for(int j = 0 ; j < w; j++)
                graph[i][j] = in[j];
        }
        //graph processing
        memset(start,0,sizeof start);
        memset(goal,0,sizeof goal);
        for (int i = 0 ; i < h; i++)
            for(int j = 0 ; j < w; j++)
                if (graph[i][j]!='#')
                {
                    for (int a = 0 ; a < 5;a++)
                    {
                        ti = i+di[a]; tj = j+dj[a];
                        if (ti<0||tj<0||ti>=h||tj>=w) continue;
                        if (graph[i+di[a]][j+dj[a]]!='#')
                            adj[idx[i][j]].push_back(idx[i+di[a]][j+dj[a]]);
                    }
                    if (isupper(graph[i][j]))
                    {
                        if (graph[i][j]=='A') goal[0] = idx[i][j];
                        if (graph[i][j]=='B') goal[1] = idx[i][j];
                        if (graph[i][j]=='C') goal[2] = idx[i][j];
                    }
                    if (islower(graph[i][j]))
                    {
                        if (graph[i][j]=='a') start[0] = idx[i][j];
                        if (graph[i][j]=='b') start[1] = idx[i][j];
                        if (graph[i][j]=='c') start[2] = idx[i][j];
                    }
                }
        int inf = 290;
        for (int i = 0 ; i < 3; i++) // for the letters that don't exist, assign to a big value
        {
            if (start[i]==0)
            {
                start[i] = inf;
                goal[i] = inf;
                adj[inf].push_back(inf);
                inf++;
            }
        }
        //BFS
        memset(visited,-1,sizeof visited);
        visited[start[0]][start[1]][start[2]] = 0;
        node cur (start[0],start[1],start[2]);
        queue<node> buff;
        buff.push(cur);
        while(!buff.empty())
        {
            cur = buff.front();
            buff.pop();
            oa = cur.ia; ob = cur.ib; oc = cur.ic;
            for (int i = 0 ; i < adj[oa].size(); i++)
                for (int j = 0 ; j < adj[ob].size(); j++)
                    for (int k = 0 ; k < adj[oc].size(); k++)
                    {
                        ta = adj[oa][i]; tb =  adj[ob][j]; tc =  adj[oc][k];
                        if (ta==tb||ta==tc||tb==tc) continue;
                        if (ta==ob&&tb==oa) continue;
                        if (ta==oc&&tc==oa) continue;
                        if (tb==oc&&tc==ob) continue;
                        if (visited[ta][tb][tc]==-1)
                        {
                            visited[ta][tb][tc] = visited[oa][ob][oc] + 1;
                            if (ta==goal[0]&&tb==goal[1]&&tc==goal[2])
                            {
                                cout<<visited[ta][tb][tc]<<endl;
                                break;
                            }
                            cur.ia = ta; cur.ib = tb; cur.ic = tc;
                            buff.push(cur);
                        }
                    }
        }
    }
}
