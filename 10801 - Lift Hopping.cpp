#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <sstream>
#define INF 99999999
using namespace std;
int n, k, T[6];
int dist[110],weight[110][110],floor[110];
int main()
{
    while(cin>>n>>k)
    {
        for (int i = 1; i<= n; i++)
            cin>>T[i];
        for (int i = 0; i <100; i++)
        {
            dist[i] = INF;
            for (int j = 0 ; j <100; j++)
            {
                weight[i][j] = INF;
            }
        }
        cin.ignore();
        for (int i = 1; i <= n; i++)
        {
            string temp;
            getline(cin,temp);
            stringstream ss(temp);
            int cnt = 0;
            while(ss>>floor[cnt])++cnt;
            for (int x = 0 ; x < cnt; x++)
                for (int y = x+1; y<cnt; y++)
                {
                    int f1 = floor[x],f2 = floor[y];
                    if ((f2-f1)*T[i]<weight[f1][f2])
                    {
                        weight[f1][f2] = weight[f2][f1] = (f2-f1)*T[i];
                    }
                }
        }
        queue <int> buff;
        bool done[110] = {0};
        dist[0] = 0;
        done[0] = true;
        buff.push(0);
        while (!buff.empty())
        {
            int top = buff.front();
            buff.pop();
            done[top] = false;
            for (int i = 0 ; i < 100; i++)
            {
                if (dist[top]+weight[top][i] + 60 < dist[i])
                {
                    dist[i] = dist[top]+weight[top][i]+60;
                    if (!done[i])
                    {
                        buff.push(i);
                        done[i] = true;
                    }
                }
            }
        }
        if (k==0) cout<<0<<endl;
        else if (dist[k]==INF) cout<<"IMPOSSIBLE"<<endl;
        else cout<<dist[k]-60<<endl;
    }
    return 0;
}
