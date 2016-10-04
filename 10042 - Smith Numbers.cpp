#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <bitset>
using namespace std;
const int MAXN = 100000;
typedef long long ll;
typedef vector <int> vi;
ll sieve_size;
bitset <1000010> bs;
vi primes;
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


int digitcount(int i) // digit sum
{
    int sum = 0;
    while(i)
    {
        sum += i % 10;
        i /= 10;
    }
    return sum;
}
bool isprime(ll N)
{
    if (N <= sieve_size) return bs[N];
    for (int i = 0; i < (int)primes.size(); i++)
    {
        if (N % primes[i]==0)return false;
    }
    return true;
}
bool check(int o)
{
    if (isprime(o)) return false;
    int sum1 = digitcount(o), sum2 = 0;
    for (int j = 0; j < primes.size() && primes[j]*primes[j] <= o; j++)
    {
        if (o % primes[j] == 0)
        {
            int d = digitcount(primes[j]);
             while (o % primes[j] == 0)
                sum2 += d, o /= primes[j];
        }
        if (o==1) break;
    }
    if (o !=1 ) sum2 += digitcount(o);
    return sum1 == sum2;
}
int main()
{
    sieve(MAXN);
    ios::sync_with_stdio(0);
    int cnt; cin>>cnt;
    int ori;
    while (cnt--)
    {
        cin>>ori;
        while (true)
        {
            if (check(++ori))
            {
                cout<<ori<<"\n";
                break;
            }
        }
    }
}
