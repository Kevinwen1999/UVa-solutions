#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int N, M;
int x, y, x2, y2;
vector < pair <int,int> > h,v;
long long ans = 0;
bool comp(const pair <int,int> &l , const pair<int,int> &r)
{
    if (l.second != r.second) return l.second < r.second;
    return l.first < r.first;
}
int main()
{
    cin>>N;
    for (int i = 0 ; i < N; i++)
    {
        cin>>x>>y;
        h.push_back(make_pair(x,y));
    }
    v = h;
    sort(h.begin(),h.end());
    sort(v.begin(),v.end(),comp);
    cin>>M>>x2>>y2;
    for (int i = 0 ; i < M-1; i++)
    {
        x = x2;
        y = y2;
        cin>>x2>>y2;
        if (x==x2)
        {
            ans+=upper_bound(h.begin(),h.end(),make_pair(x,max(y,y2))) - lower_bound(h.begin(),h.end(),make_pair(x,min(y,y2)));
        }
        else
        {
            ans+=upper_bound(v.begin(),v.end(),make_pair(max(x,x2),y),comp) - lower_bound(v.begin(),v.end(),make_pair(min(x,x2),y),comp);
        }
    }
    cout<<ans<<endl;
    return 0;
}
