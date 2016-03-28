#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
class UnionFind
{
    private:
        vector < int > p;
        vector <int> rankx;
    public:
        UnionFind(int N) { rankx.assign(N+1, 0); p.assign(N+1, 0); for (int i = 0; i < N+1; i++) p[i] = i; }
        int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        void unionSet(int i, int j)
        {
            if (!isSameSet(i,j))
            {
                int x = findSet(i), y = findSet(j);
                if (rankx[x] > rankx[y])
                    p[y] = x;
                else
                {
                    p[x] = y;
                    if (rankx[x] == rankx[y])
                        rankx[y]++;
                }
            }
        }
};
int main()
{
    int times;
    scanf("%d",&times);
    while(times--)
    {
        vector < pair <int, pair <int,int> > > EdgeList;
        int E, V;
        scanf("%d%d",&V,&E);
        int mst_cost = 0, smst = 99999999;
        for (int i = 0 ; i < E ; i++)
        {
            int u,v,w;
            scanf("%d %d %d", &u,&v,&w);
            EdgeList.push_back(make_pair(w,make_pair(u,v)));
        }
        vector < pair <int,int> > flags;
        sort (EdgeList.begin(),EdgeList.end());
        UnionFind UF(V);
        for (int i = 0 ; i < E; i++)
        {
            pair <int, pair <int, int > > frontt = EdgeList[i];
            if (!UF.isSameSet(frontt.second.first, frontt.second.second))
            {
                mst_cost+=frontt.first;
                UF.unionSet(frontt.second.first, frontt.second.second);
                flags.push_back(make_pair(frontt.second.first,frontt.second.second));
            }
        }
        for (int i = 0 ; i < (int)flags.size(); i++)
        {
            pair <int,int> forbids = flags[i];
            UnionFind UF2(V);UnionFind forb(V);
            forb.unionSet(forbids.first,forbids.second);
            int smstt = 0;
            for (int i = 0 ; i < E; i++)
            {
                pair <int, pair <int, int > > frontt = EdgeList[i];
                if (!UF2.isSameSet(frontt.second.first, frontt.second.second)&&!forb.isSameSet(frontt.second.first, frontt.second.second))
                {
                    smstt+=frontt.first;
                    UF2.unionSet(frontt.second.first, frontt.second.second);
                }
            }
            bool discon = false;
            for (int i = 1; i <= V; i++)
                if (!UF2.isSameSet(1,i))
                {
                    discon = true;
                    break;
                }
            if (discon) continue;
            smst = min(smst,smstt);
        }
        if (smst == 99999999) smst = mst_cost;
        printf("%d %d\n", mst_cost, smst);
    }
}
