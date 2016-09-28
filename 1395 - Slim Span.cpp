#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
vector < pair <int, pair <int,int> > > edgelist;
int V, E;
int p[101], rnk[101];
int findp(int x)
{
    return p[x] == x ? x : (p[x] = findp(p[x]));
}
bool sameset(int x, int y)
{
    return findp(x) == findp(y);
}
void mergeset(int x, int y)
{
    if (!sameset(x, y))
    {
        x = findp(x), y = findp(y);
        if (rnk[x] > rnk[y])
            rnk[x] += rnk[y], p[y] = x;
        else
            rnk[y] += rnk[x], p[x] = y;
    }
}
int main()
{
    while (scanf("%d %d", &V, &E) == 2 && V+E)
    {
        edgelist.clear();
        for (int i = 0; i < E; i++)
        {
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            edgelist.push_back(make_pair(w, make_pair(a, b)));
        }
        sort(edgelist.begin(), edgelist.end());
        int ans = INF;
        for (int start = 0; start < E; start++) // start from smallest edge
        {
            int maxe = 0;
            for (int i = 0; i <= V; i++) // reset UFDS
                p[i] = i, rnk[i] = 1;
            int totaledge = 0;
            for (int j = start; j < E; j++) // Kruskal
                if (!sameset(edgelist[j].second.first,edgelist[j].second.second))
                {
                    maxe = max (maxe, edgelist[j].first);
                    totaledge++;
                    mergeset(edgelist[j].second.first,edgelist[j].second.second);
                }
            if (totaledge == V-1) // can build a spanning tree
            {
                ans = min(ans, maxe - edgelist[start].first);
            }
            else
                break; // no spanning tree can be build with edges in range [start, E-1]
        }
        printf("%d\n", ans == INF ? -1 : ans);
    }
}
