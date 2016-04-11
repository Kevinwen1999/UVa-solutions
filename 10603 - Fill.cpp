#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>
#include <fstream>
#define INF 0x3f3f3f3f
using namespace std;
int d,sum,inc,now,ta,tb,tc;
int ori[3], tmp[3];
long long dist[210][210];
bool done[210][210];
long long water[210];
long long min(long long a, long long b)
{
    return a < b ? a: b;
}
int main()
{
    int T;
    cin>>T;
    //ofstream myfile;
    //myfile.open("output.txt");
    while (T--)
    {
        cin>>ori[0]>>ori[1]>>ori[2]>>d;
        sum = ori[2];
        memset(dist,63,sizeof dist);
        memset(done,0,sizeof done);
        memset(water, 63, sizeof water);
        dist[0][0] = 0;
        done[0][0] = 1;
        water[ori[2]] = 0;
        water[0] = 0;
        pair <int,int> cur = make_pair(0,0),next;
        queue < pair <int,int> > buff;
        buff.push(cur);
        while(!buff.empty())
        {
            cur = buff.front();
            buff.pop();
            done[tmp[0]][tmp[1]] = false;
            ta = cur.first; tb = cur.second;
            for (int i = 0 ; i < 3; i++)
            {
                for (int j = 0 ; j < 3; j++)
                {
                    if (i==j) continue;
                    tmp[0]  =  cur.first; tmp[1]  = cur.second; tmp[2]  = sum - tmp[0] - tmp[1];
                    if (tmp[j] + tmp[i] > ori[j])
                    {
                        inc = ori[j] - tmp[j];
                    }
                    else
                    {
                        inc = tmp[i];
                    }
                    tmp[i]-=inc; tmp[j]+=inc;
                    now = dist[ta][tb] + inc;
                    if ( now < dist[tmp[0]][tmp[1]])
                    {
                        dist[tmp[0]][tmp[1]] = now;
                        water[tmp[0]] = min(water[tmp[0]], now);
                        water[tmp[1]] = min(water[tmp[1]], now);
                        water[tmp[2]] = min(water[tmp[2]], now);
                        if (!done[tmp[0]][tmp[1]])
                        {
                            done[tmp[0]][tmp[1]] = true;
                            next = make_pair(tmp[0],tmp[1]);
                            buff.push(next);
                        }
                    }
                }
            }
        }
        for (int i = d; i >=0 ; i--)
        {
            if (water[i]!=INF)
            {
                cout<<water[i]<<" "<<i<<endl;
                break;
            }
        }
    }
    //myfile.close();
}
