#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 20
int n, a[MAXN],maxd;
bool sorted()
{
    for (int i = 1; i <= n; i++)
        if (a[i]!=i)
            return false;
    return true;
}
int H()
{
    int h = 0;
    for (int i = 1; i < n; i++)
        if (a[i]+1!=a[i+1])
            h++;
    if (a[n]!=n)
        h++;
    return h;
}
bool dfs(int d)
{
    if (d==maxd)
    {
        if (sorted())
            return true;
        return false;
    }
    if (3*d + H() > maxd*3) // key of A* , you can only change endpoint of 3 numbers maximum at a time. It's important to note that it's a best case analysis.
        return false;
    int save[MAXN], temp[MAXN];
    for (int i = 1; i <= n-1; i++)
        for (int j = i; j <= n-1; j++)
            for (int k = j+1; k <= n; k++) // i , j,  k are the dividing points , for example 1 2 | 3 4| 5 6 | 7 8 9 = 1 2 | 5 6 | 3 4 | 7 8 9
            {
                int cur = 0;
                memcpy(save, a, sizeof a);
                for (int c = 1; c < i; c++)
                    temp[++cur] = a[c];
                for (int c = j+1; c<=k; c++)
                    temp[++cur] = a[c];
                for (int c =i ; c <= j; c++)
                    temp[++cur] = a[c];
                for(int c = k+1; c<= n; c++)
                    temp[++cur] = a[c];
                memcpy(a,temp,sizeof temp);
                if (dfs(d+1))
                    return true;
                memcpy(a,save, sizeof save);
            }
    return false;
}
int main()
{
    int cnt = 0;
    while (cin>>n && n)
    {
        for (int i = 1; i <= n; i++)
            cin>>a[i];
        if (sorted())
        {
            cout<<"Case "<<++cnt<<": "<<0<<endl;
            continue;
        }
        for (maxd = 1;; maxd++)
        {
            if (dfs(0))
                break;
        }
        cout<<"Case "<<++cnt<<": "<<maxd<<endl;
    }
}
