#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
ll sieve_size;
bitset <10010> bs;
vi primes;
int e[10010]; // exponents of each prime number in vi primes
// Sieve of E
void sieve(ll upper)
{
    sieve_size = upper +1;
    bs.set();
    for (ll i = 2; i <= sieve_size; i++)
        if (bs[i])
        {
            for (ll j = i*i; j < sieve_size; j+=i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
}
int p, q, r, s;
void addint(int n, int d) // loop through prime factors of each interger n, d is the exponent. d > 0 means multiplication, otherwise it's division
{
    for (int i = 0; i < primes.size(); i++)
    {
        while (n % primes[i] == 0)
        {
            n /= primes[i];
            e[i] += d;
        }
        if (n==1) break; // no need to loop anymore
    }
}
void addfactorial(int n, int d) // ans times (n!) ^ d
{
    for (int i = 1; i <= n; i++)
        addint(i,d);
}
int main()
{
    sieve(10000);
    while (cin>>p>>q>>r>>s)
    {
        memset(e, 0, sizeof e);
        addfactorial(p,1);
        addfactorial(q,-1);
        addfactorial(p-q, -1);
        addfactorial(r,-1);
        addfactorial(s,1);
        addfactorial(r-s, 1);
        double ans = 1;
        for (int i = 0; i < primes.size(); i++)
            ans *= pow(primes[i], e[i]);
        printf("%.5lf\n", ans);
    }
}
