
#include <bits/stdc++.h>

#define MAXN 15
#define INF 0x3f3f3f3f
#define MOD 20437
using namespace std;

int N;
string in;
char grid[MAXN][MAXN];
int dist[30][MAXN][MAXN];
bool done[30][MAXN][MAXN];
int way[30][MAXN][MAXN];
int bi, bj, ei, ej, maxa;
int di[4] = {1,0,-1,0};
int dj[4] = {0,1,0,-1};
int cnt = 0;
bool out(int i, int j)
{
    return i < 0 || i >= N || j < 0 || j >= N;
}
struct node
{
    int  c = 0, i = 0, j = 0;
    node(int b,int d,int f)
    {
        c = b; i = d; j = f;
    }
};
int dp(int ca, int ci, int cj)
{
    int &ans = way[ca][ci][cj];
    if (~ans) return ans;
    ans = 0;
    int ti, tj,ta;
    for (int i = 0 ; i < 4; i++)
    {
        ti = ci + di[i]; tj = cj + dj[i];
        if (out(ti,tj)) continue;
        if (grid[ti][tj]=='.' || grid[ti][tj]-'A'+1 <= ca)//tricky , you can revisited them
        {
            if (dist[ca][ci][cj] + 1 == dist[ca][ti][tj]) // there is an edge
                ans = (ans + dp(ca,ti,tj)) % MOD;
        }
        else
        {
            ta = grid[ti][tj] - 'A' + 1;
            if (ta!=ca+1) continue;
            if (dist[ca][ci][cj] + 1 == dist[ta][ti][tj])
                ans = (ans + dp(ta,ti,tj)) % MOD;
        }
    }
    return ans = way[ca][ci][cj];
}
void SPFA()
{
    memset(dist,INF,sizeof dist);
    memset(done,0,sizeof done);
    queue <node> buff;
    buff.push(node(1, bi, bj));
    dist[1][bi][bj] = 0;
    done[1][bi][bj] = true;
    node tnode(0,0,0);
    int ca, ci, cj,ti, tj,ta;
    while (!buff.empty())
    {
        tnode = buff.front();
        buff.pop();
        ca = tnode.c; ci = tnode.i; cj = tnode.j;
        done[ca][ci][cj] = false;
        for (int i = 0; i < 4; i++)
        {
            ti = ci + di[i]; tj = cj + dj[i];
            if (out(ti,tj)) continue;
            if (grid[ti][tj]=='#') continue;
            if (grid[ti][tj]=='.' || grid[ti][tj]-'A'+1 <= ca) //tricky , you can revisited previous fruit spot
            {
                if (dist[ca][ti][tj] > dist[ca][ci][cj]+1)
                {
                    dist[ca][ti][tj] = dist[ca][ci][cj] + 1;
                    if (!done[ca][ti][tj])
                    {
                        done[ca][ti][tj] = true;
                        buff.push(node(ca,ti,tj));
                    }
                }
            }
            else
            {
                ta = grid[ti][tj] - 'A' + 1;
                if (ta!=ca+1) continue;
                if (dist[ta][ti][tj] > dist[ca][ci][cj]+1)
                {
                    dist[ta][ti][tj] = dist[ca][ci][cj] + 1;
                    if (!done[ta][ti][tj])
                    {
                        done[ta][ti][tj] = true;
                        buff.push(node(ta,ti,tj));
                    }
                }
            }
        }
    }
    if (dist[maxa][ei][ej]==INF)
    {
        cout<<"Impossible"<<endl; // uppercase ... waste a submission
        return;
    }
    memset(way,-1,sizeof way);
    way[maxa][ei][ej] = 1;
    cout<<dist[maxa][ei][ej]<<" "<<dp(1,bi,bj)<<endl;
}
int main()
{
    while(cin>>N&&N)
    {
        maxa = 0;
        for (int i = 0 ; i < N; i++)
        {
            cin>>grid[i];
        }
        for (int i = 0 ; i < N; i++)
        {
            for (int j = 0 ; j < N; j++)
            {
                if (isupper(grid[i][j]))
                {
                    if (grid[i][j] == 'A')
                    {
                        bi = i; bj = j;
                    }
                    if (grid[i][j] - 'A' + 1 > maxa)
                    {
                        maxa = grid[i][j] - 'A' + 1;
                        ei = i; ej = j;
                    }
                }
            }
        }
        if (maxa == 0) // this case really does not make sense
        {
            cout<<"Case "<<++cnt<<": 0 1"<<endl;
            continue;
        }
        cout<<"Case "<<++cnt<<": ";
        SPFA();
    }
}
