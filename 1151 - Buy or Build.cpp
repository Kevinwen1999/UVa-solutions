#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
struct point
{
    int x, y;
}points[1010];
int cost[10];
vector <int> subnet[10];
vector <pair <int, pair <int, int > > > edgelist;
vector <pair <int, pair <int, int > > > MST;
int N, Q;
int p[1010], rnk[1010];
long long ans;
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
        x = findp(x), y = findp(y); // EXTREMELY IMPORTANT !!!!!!!!!
        if (rnk[x] > rnk[y])
            rnk[x] += rnk[y], p[y] = x;
        else
            rnk[y] += rnk[x], p[x] = y;
    }
}
long long kruskal() // first call, generate original MST without using any subnet
{
    MST.clear();
    for (int i = 0; i <= N; i++)
        p[i] = i, rnk[i] = 1;
    sort(edgelist.begin(), edgelist.end());
    int cnt = 0;
    long long tot = 0;
    for (int i = 0; i < edgelist.size(); i++)
    {
        if (!sameset(edgelist[i].second.first, edgelist[i].second.second))
        {
            MST.push_back(edgelist[i]);
            cnt ++;
            tot += edgelist[i].first;
            mergeset(edgelist[i].second.first, edgelist[i].second.second);
            if (cnt == N-1) return tot;
        }
    }
    return tot;
}
long long kruskal2() // second call, only consider edges in MST
{
    long long ans = 0;
    for (int i = 0; i < MST.size(); i++)
    {
        if (!sameset(MST[i].second.first, MST[i].second.second))
        {
            ans += MST[i].first;
            mergeset(MST[i].second.first, MST[i].second.second);
        }
    }
    return ans;
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &N, &Q);
        for (int i = 0; i < Q; i++)
        {
            int n, c;
            scanf("%d%d", &n, &c);
            cost[i] = c;
            subnet[i].clear();
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &c);
                subnet[i].push_back(c);
            }
        }
        for (int i = 1 ; i <= N; i++)
        {
            int x; int y;
            scanf("%d%d", &x, &y);
            points[i].x = x; points[i].y = y;
        }
        edgelist.clear();
        for (int i = 1; i <= N; i++)
        {
            for (int j = i+1; j <= N; j++)
            {
                edgelist.push_back(make_pair((points[i].x-points[j].x)*(points[i].x-points[j].x)+(points[i].y-points[j].y)*(points[i].y-points[j].y), make_pair(i,j)));
            }
        }
        ans = kruskal();
        for (int mask = 1; mask < (1<<Q); mask++) // ierate through all subset of subnet
        {
            for (int i = 0; i <= N; i++)
                p[i] = i, rnk[i] = 1;
            long long totc = 0;
            for (int j = 0; j < Q; j++)
            {
                if (mask & (1<<j))
                {
                    totc += cost[j];
                    for (int k = 1; k < subnet[j].size(); k++)
                    {
                        mergeset(subnet[j][k], subnet[j][k-1]);
                    }
                }
            }
            ans = min(ans, totc + kruskal2());
        }
        printf("%d\n", ans);
        if (T) printf("\n");
    }
}
