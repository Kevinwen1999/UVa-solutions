#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, m;
vector <int> q, e, ans;
bool addint(int k, int p)
{
    int len = q.size();
    bool ok = true;
    for (int i = 0; i < len; i++)
    {
        while(k&&k%q[i]==0)
        {
            e[i]-=p;
            k/=q[i];
        }
        if (e[i]>0) ok = false;
    }
    return ok;
}
int main()
{
    while (cin>>n>>m)
    {
        n-=1;
        q.clear(); e.clear();
        ans.clear();
        int len = sqrt(m) + 1;
        for (int i = 2; i <= len; i++)
        {
            if (m%i==0)
            {
                e.push_back(0);
                while (m%i==0)
                {
                    e[e.size()-1]++;
                    m /= i;
                }
                q.push_back(i);
                if (!m || m == 1) break;
            }
        }
        if (m!=1)
        {
            e.push_back(1);
            q.push_back(m);
        }
        int cnt = 0;
        for (int i = 1; i < n; i++) // C kn = n-k+1/k * C (k-1)n
        {
            addint(n-i+1,1);
            if (addint(i,-1))
            {
                cnt++;
                ans.push_back(i+1);
            }
        }
        cout<<cnt<<endl;
        for (int i = 0; i < ans.size(); i++)
        {
            if (!i) cout<<ans[i];
            else cout<<" "<<ans[i];
        }
        cout<<endl;
    }
}
