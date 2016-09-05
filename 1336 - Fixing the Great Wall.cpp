/*#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int N, V, X;
const int MAXN = 1005;
struct node                       //This code will TLE, cannot do memoization
{
    int x, c, i; //cost == c + t*i
}p1;
vector <node> pos, neg;
bool cmp (const node &a,const node &b)
{
    return a.x < b.x;
}
bool ncmp (const node &a,const node &b)
{
    return a.x > b.x;
}
int nsum[MAXN], psum[MAXN];
long long sum(int i, int j, bool flag)
{
    if(!flag)
    {return nsum[j] - nsum[i-1];}
    else
    {return psum[j] - psum[i-1];}
}
long long dp[MAXN][MAXN][2];
int vis[MAXN][MAXN][2];
int kase = 1;
long long D(int i, int j, int flag)
{
    long long &ans = dp[i][j][flag];
    if (vis[i][j][flag]==kase) return ans;
    vis[i][j][flag]=kase;
    int cur;
    if (flag == 0) cur = neg[i].x;
    else if (flag == 1) cur = pos[j].x;
    int t;
    if (i==(int)neg.size()-1 && j==(int)pos.size()-1) return ans = 0;
    if (i == (int)neg.size()-1)
    {
        t = abs(cur - pos[j+1].x) / V;
        return ans = D(i,j+1,1) + sum(j+1,(int)pos.size()-1,1)*t + pos[j+1].c;
    }
    if (j == (int)pos.size()-1)
    {
        t = abs(cur - neg[i+1].x) / V;
        return ans = D(i+1,j,0) + sum(i+1,(int)neg.size()-1,0)*t + neg[i+1].c;
    }
    ans = INF;
    t = abs(cur - pos[j+1].x) / V;
    ans = min(ans, D(i,j+1,1) + ( sum(j+1,(int)pos.size()-1,1) + sum(i+1,(int)neg.size()-1,0) )*t + pos[j+1].c);
    t = abs(cur - neg[i+1].x) / V;
    ans = min(ans, D(i+1,j,0) + ( sum(j+1,(int)pos.size()-1,1) + sum(i+1,(int)neg.size()-1,0) )*t + neg[i+1].c);
    return ans;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    while(1)
    {
        cin>>N>>V>>X;
        if (!(N&&V&&X)) break;
        kase++;
        p1.x = -INF;
        pos.clear(); pos.push_back(p1); // dummies
        p1.x = INF;
        neg.clear(); neg.push_back(p1);
        for (int i = 0; i < N; i++)
        {
            cin>>p1.x>>p1.c>>p1.i;
            if (p1.x <= X) neg.push_back(p1);
            else pos.push_back(p1);
        }
        sort(neg.begin(), neg.end(), ncmp);
        //reverse(neg.begin(), neg.end());
        sort(pos.begin(), pos.end(), cmp);
        nsum[0] = 0;
        for (int i = 1 ; i <neg.size(); i++)
        {
            nsum[i] = nsum[i-1] + neg[i].i;
        }
        psum[0] = 0;
        for (int i = 1 ; i <pos.size(); i++)
        {
            psum[i] = psum[i-1] + pos[i].i;
        }
        neg[0].x = pos[0].x = X;
        cout<<D(0,0,0)<<"\n";
    }
}
*/
// Credit from http://www.hardbird.net/uva-1336-fixing-the-great-wall/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1100;

long long d[maxn][maxn][2], sum, pre[maxn];
int n, v, st;

struct Node
{
    int x, c, d;
    bool operator < (const Node a)const
    {
        return x<a.x;
    }
} nd[maxn], tmp;

int main()
{
    while(~scanf("%d%d%d", &n, &v, &st) && n)
    {
        memset(d, 0x3f, sizeof d);
        nd[n+1].x=st, nd[n+1].c=0, nd[n+1].d=0;
        tmp.x=st, tmp.c=0, tmp.d=0;
        for(int i=1; i<=n; i++)
            scanf("%d%d%d", &nd[i].x, &nd[i].c, &nd[i].d);
        ++n;
        sort(nd+1, nd+n+1);
        sum=0, pre[0]=0;
        for(int i=1; i<=n; i++)
        {
            sum+=nd[i].c;
            pre[i]=pre[i-1]+nd[i].d;
        }
        int k=lower_bound(nd+1, nd+n+1, tmp)-nd;
        d[k][k][0]=d[k][k][1]=0;
        for(int i=k; i; i--)
            for(int j=k; j<=n; j++)
            {
                long long tmp=pre[n]-pre[j]+pre[i-1];
                if(i>1)
                {
                    d[i-1][j][0]=min(d[i-1][j][0],
                                     min(d[i][j][0]+abs(nd[i].x-nd[i-1].x)*tmp,
                                         d[i][j][1]+abs(nd[j].x-nd[i-1].x)*tmp));
                }
                if(j<n)
                {
                    d[i][j+1][1]=min(d[i][j+1][1],
                                     min(d[i][j][0]+abs(nd[j+1].x-nd[i].x)*tmp,
                                         d[i][j][1]+abs(nd[j+1].x-nd[j].x)*tmp));
                }
            }
        printf("%lld\n", min(d[1][n][0], d[1][n][1])/v+sum);
    }
    return 0;
}
