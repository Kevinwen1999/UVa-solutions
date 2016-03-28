#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <iomanip>
using namespace std;
class UnionFind
{
private:
    vector <int> p;
    vector <int> ranks;
public:
    UnionFind (int N){ranks.resize(N+1); p.resize(N+1); for (int i = 0; i <= N; i++) p[i] = i; for (int i = 0 ; i <=N; i++) ranks[i] = 0;}
    int findset(int i) {return (p[i] == i) ? i: (p[i] = findset(p[i]));}
    bool issameset(int i, int j){return findset(i)==findset(j);}
    void unionset(int i, int j)
    {
        if (!issameset(i,j))
        {
            int x = findset(i), y = findset(j);
            if (ranks[x]>ranks[y])
                p[y] = p[x];
            else
            {
                p[x] = p[y];
                if (ranks[x]==ranks[y])
                    ranks[y]++;
            }
        }
    }
};
int V, E,x,y,w,totalsum,mstsum;
vector < pair <int, pair <int, int > > > edgelist;
int main()
{
    while (1)
    {
        cin>>V>>E;
        if (V==0&&E==0)break;
        totalsum = 0 ; mstsum = 0;
        edgelist.clear();
        for (int i = 0 ; i < E; i++)
        {
            cin>>x>>y>>w;
            edgelist.push_back(make_pair(w,make_pair(x,y)));
            totalsum+=w;
        }
        sort(edgelist.begin(),edgelist.end());
        UnionFind uf(V);
        for (int i = 0 ; i < E; i++)
        {
            pair <int, pair <int, int > > top = edgelist[i];
            if (!uf.issameset(top.second.first,top.second.second))
            {
                uf.unionset(top.second.first,top.second.second);
                mstsum+=top.first;
            }
        }
        cout<<totalsum-mstsum<<endl;
    }
}
