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
int N,V;
double x, y,a,b,w,sum;
vector < pair <double,double> > vinfo;
vector < pair <double, pair <int, int> > > edgelist;
int main()
{
    cin>>N;
    while (N--)
    {
        cin>>V;
        sum = 0.0;
        vinfo.clear();
        edgelist.clear();
        for (int i = 0 ; i < V; i++)
        {
            cin>>x>>y;
            vinfo.push_back(make_pair(x,y));
        }
        for (int i = 0 ; i < V; i++)
            for (int j = 0 ; j < V; j++)
        {
            if (i==j)continue;
            pair <double,double> ii = vinfo[i], jj = vinfo[j];
            a = abs(ii.first-jj.first); b = abs(ii.second-jj.second);
            w = sqrt(a*a+b*b);
            edgelist.push_back(make_pair(w,make_pair(i,j)));
        }
        sort(edgelist.begin(),edgelist.end());
        UnionFind uf(V);
        for  (int i = 0 ; i < (int) edgelist.size(); i++)
        {
            pair < double, pair <int, int> > edge = edgelist[i];
            if (!uf.issameset(edge.second.first,edge.second.second))
            {
                sum+=edge.first;
                uf.unionset(edge.second.first, edge.second.second);
            }
        }
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        cout<<sum<<endl;;
        if(N>0) cout<<endl;
    }
}
