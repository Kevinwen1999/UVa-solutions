#include <bits/stdc++.h>
using namespace std;
class UnionFind
{
    private:
        vector < int > p;
        vector <int> rankx;
    public:
        UnionFind(int N) { rankx.assign(N, 0); p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
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
    vector < pair <int, pair <int,int> > > EdgeList, ANS;
    int E, V;
    while (1)
    {
        scanf("%d%d",&V,&E);
        if (E==0 && V==0) break;
        EdgeList.clear();
        ANS.clear();
        for (int i = 0 ; i < E ; i++)
        {
            int u,v,w;
            scanf("%d %d %d", &u,&v,&w);
            EdgeList.push_back(make_pair(w,make_pair(u,v)));
        }
        sort (EdgeList.begin(),EdgeList.end());
        UnionFind UF(V);
        for (int i = 0 ; i < E; i++)
        {
            pair <int, pair <int, int > > frontt = EdgeList[i];
            if (!UF.isSameSet(frontt.second.first, frontt.second.second))
            {
                UF.unionSet(frontt.second.first, frontt.second.second);
            }
            else
            {
                ANS.push_back(frontt);
            }
        }
        //comment
        if (ANS.size()==0) puts("forest");
        else
        {
            printf("%d", ANS[0].first);
            for (int i = 1 ; i < ANS.size(); i++)
                printf("% d", ANS[i].first);
            printf("\n");
        }
    }
}
