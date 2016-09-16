#include <bits/stdc++.h>
#define MAX 2147483647
#define N 46340 //sqrt(INT_MAX)
using namespace std;
typedef long long ll;
typedef vector <int> vi;
ll sieve_size;
bitset <1000010> bs;
vi primes;
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
int main()
{
    int cse = 0, n, p;
    sieve(N);
    while (cin>>n && n)
    {
        cse++;
        if (n == INT_MAX)//2147483647 is prime
            printf("Case %d: 2147483648\n", cse);//2147483647 + 1
        else if (n == 1)
            printf("Case %d: 2\n", cse);
        else
        {
            int sum = 0, m = n;
            for (int i = 0; i < primes.size() && primes[i] <= n; i++)
            {
                int cnt = 1;
                while (n % primes[i] == 0)
                {
                    cnt*=primes[i];
                    n/=primes[i];
                }
                if (cnt != 1)
                    sum+=cnt;
            }
            if (sum == m) sum++;
            else if (n!=1) sum+=n;
            printf("Case %d: %d\n", cse, sum);
        }
    }
}
