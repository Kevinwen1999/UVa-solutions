#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;
int N;
bool used[5010];
struct node
{
    int xl,xr,yl,yr;
    int x,y,order;
};
bool compx(node &a, node &b)
{
    return a.xr<b.xr || (a.xr==b.xr&&a.xl<b.xl);
}
bool compy(node &a, node &b)
{
    return a.yr<b.yr || (a.yr==b.yr&&a.yl<b.yl);
}
bool compi(node &a, node &b)
{
    return a.order<b.order;
}
vector <node> range;
int main()
{
    while(1)
    {
        cin>>N;
        if (N==0)  break;
        bool impossible ;
        range.clear();
        memset(used,0,sizeof used);
        node t;
        for (int i = 0 ; i < N; i++)
        {
            cin>>t.xl>>t.yl>>t.xr>>t.yr;
            t.order = i;
            range.push_back(t);
        }
        sort(range.begin(),range.end(),compx);
        for(int i = 0 ; i < range.size(); i++)
        {
            impossible = true;
            t = range[i];
            for (int j = t.xl; j <= t.xr; j++)
            {
                if (!used[j])
                {
                    impossible = false;
                    used[j] = true;
                    range[i].x = j;
                    break;
                }
            }
            if (impossible) break;
        }
        if (impossible)
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        memset(used,0,sizeof used);
        sort(range.begin(),range.end(),compy);
        for(int i = 0 ; i < range.size(); i++)
        {
            impossible = true;
            t = range[i];
            for (int j = t.yl; j <= t.yr; j++)
            {
                if (!used[j])
                {
                    impossible = false;
                    used[j] = true;
                    range[i].y = j;
                    break;
                }
            }
            if (impossible) break;
        }
        if (impossible)
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        sort(range.begin(),range.end(),compi);
        for (int i = 0 ; i < range.size(); i++)
        {
            t = range[i];
            cout<<t.x<<" "<<t.y<<endl;
        }
    }
}
