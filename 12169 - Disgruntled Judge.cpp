#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXD= 200 + 10, MOD = 10001;
ll x[MAXD];
ll a, k, b, d, c;
/*
x2 = (a * x1 + b) % 10001;
x3 = (a * x2 + b) % 10001;
x3 = (a * (a * x1 + b) % 10001 + b ) % 10001;
x3 = (a * (a * x1 + b) + b) % 10001;
x3 + 10001 * k = a * a * x1 + (a + 1) * b;
x3 - a * a * x1 = (a + 1) * b + 10001 * (-k);
then use extend euclid to get b and -k, check if d is valid and check all the odd x[i];
*/
void extendeuclid(ll a, ll b, ll &d, ll &x, ll &y)
{
    if (!b)
    {
        d = a;
        x = 1; y = 0;
        return;
    }
    else
    {
        extendeuclid(b,a%b,d,y,x);
        y -= x * (a/b);
        return;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i < 2*T; i+=2)
        scanf("%lld", &x[i]);
    for (a = 0; a<MOD; a++)
    {
        c = (x[3]-a*a*x[1]);
        extendeuclid(1LL*MOD, a+1, d, k, b);
        if (c % d) continue; // c cannot divide d, invalid solution;
        b = b * c / d;
        bool ok = true;
        for (int i = 2; i <= 2*T; i++)
        {
            if (i & 1) // odd
            {
                if (x[i] != ((a*x[i-1] + b) % MOD))
                {
                    ok = false; break;
                }
            }
            else
            {
                x[i] = ((a*x[i-1] + b) % MOD);
            }
        }
        if (ok)
            break;
    }
    for (int i = 2; i <= 2 * T; i+=2)
    {
        printf("%lld\n", x[i]);
    }
}
