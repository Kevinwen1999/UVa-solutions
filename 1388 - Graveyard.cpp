#include <bits/stdc++.h>
using namespace std;
set<double> s;
set<double> :: iterator itlow;
int main()
{
    int m, n;
    while (scanf("%d%d", &n, &m) == 2)
    {
        s.clear();
        double mm = m+n;
        for (double i = 1; i <= mm; i++)
        {
            double t = i / mm;
            s.insert(t);
        }

        double nn = n;
        double ans = 0;
        for (double i = 1; i <= nn; i++)
        {
            double t = i / nn;
            itlow = s.lower_bound(t);
            double add = *itlow - t;
            if (itlow != s.begin())itlow--;
            add = min(add, t- *itlow);
            ans += add;
        }
        printf("%.4lf\n", ans * 10000);
    }
}
