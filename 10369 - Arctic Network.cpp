#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <iomanip>
using namespace std;
int T,S,V,need;
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
    cin>>T;
    while(T--)
    {
        cin>>S>>V;
        need = V-1-(S-1);
        vector < pair<int,int> > node;
        vector < pair <double, pair <int,int> > > EdgeList;
        for (int i = 0,a,b ; i < V; i++)
        {
            cin>>a>>b;
            node.push_back(make_pair(a,b));
        }
        for (int i = 0 ; i < V; i++)
            for (int j = i+1; j < V; j++)
                EdgeList.push_back(make_pair(hypot(node[i].first-node[j].first,node[i].second-node[j].second),make_pair(i,j)));
        sort(EdgeList.begin(),EdgeList.end());
        UnionFind UF(V);
        double curcost; int counter = 0;
        for (int i = 0 ; i < (int)EdgeList.size(); i++)
        {
            pair <double, pair <int, int > > frontt = EdgeList[i];
            if (!UF.isSameSet(frontt.second.first, frontt.second.second))
            {
                curcost = frontt.first;
                UF.unionSet(frontt.second.first, frontt.second.second);
                counter++;
            }
            if (counter==need)
            {
                cout<<fixed;
                cout<<setprecision(2);
                cout<<curcost<<endl;
                break;
            }
        }
    }
}
