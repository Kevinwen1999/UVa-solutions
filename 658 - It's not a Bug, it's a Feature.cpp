#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <utility>
#define MAXN 20
#define MAXM 105
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
    int time;
    string in, out;
} edges[MAXM], tedge;
int dist[1<<MAXN];
bool done[1<<MAXN];
int N, M;
queue <int> buff;
int spfa()
{
    while (!buff.empty()) buff.pop();
    for (int i = 0; i < (1<<N); i++)
    {
        dist[i] = INF;
        done[i] = 0;
    }
    dist[(1<<N)-1] = 0;
    done[(1<<N)-1] = true;
    buff.push((1<<N)-1);
    while (!buff.empty())
    {
        int mask = buff.front();
        buff.pop();
        done[mask] = false;
        for (int i = 0; i < M; i++) // loop through all patches, better than generating the whole graph
        {
            tedge = edges[i];
            bool OK = true;
            for (int j = 0; j < N && OK; j++) // check if all conditions satisfied to allpy patch
            {
                if (tedge.in[j] == '+' && !(mask & (1<<j))) OK = false;
                if (tedge.in[j] == '-' && (mask & (1<<j))) OK = false;
            }
            if (OK) // patch can be applied
            {
                int next = mask;
                for (int j = 0; j < N; j++) //calculate next state
                {
                    if (tedge.out[j] == '+') next |= (1<<j);
                    if (tedge.out[j] == '-') next &= ~(1<<j);
                }
                if (dist[mask] + tedge.time < dist[next])// SPFA
                {
                    dist[next] = dist[mask] + tedge.time;
                    if (!done[next])
                    {
                        buff.push(next);
                        done[next] = true;
                    }
                }
            }
        }
    }
    if (dist[0] == INF) return -1;
    return dist[0];
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    while (cin>>N>>M)
    {
        if (!(N+M)) break;
        for (int i = 0; i < M; i++)
        {
            int time; cin>>time;
            string in, out; cin>>in>>out;
            tedge.time = time; tedge.in = in; tedge.out = out;
            edges[i] = tedge;
        }
        int ans = spfa();
        cout<<"Product "<<++cnt<<"\n";
        if (ans == -1)
            cout<<"Bugs cannot be fixed.\n\n";
        else
            cout<<"Fastest sequence takes "<<ans<<" seconds.\n\n";
    }
}
