#include <bitset>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
const int MAXN = 1000001;
ll sieve_size;
bitset <1000010> bs;
vi primes;
int a[MAXN];
void sieve()
{
    sieve_size = sqrt(MAXN+0.5);
    bs.set();
    for (ll i = 5; i <= sieve_size; i+=4)
        if (bs[i])
        {
            for (ll j = i*i; j <= MAXN; j+=i)
                bs[j] = 0;
            //primes.push_back((int)i);
        }
    for (int i = 5; i <= MAXN; i+=4)
        if (bs[i]) primes.push_back(i);
    memset(a,0,sizeof a);
    for (int i = 0; i < primes.size(); i++)
    {
        for (int j = i; j < primes.size(); j++)
        {
            ll k = (ll)primes[i] * (ll)primes[j];
            if (k > (ll)MAXN) break;
            a[k] = 1;
        }
    }
    for (int i = 25; i <= MAXN; i++)
        a[i] = a[i-1] + a[i];
}
int main()
{
    sieve();
    int N;
    while(scanf("%d", &N) == 1 && N) printf("%d %d\n", N, a[N]);
}
