#include <iostream>
#include <cmath>
using namespace std;
long long N, K, MOD, SN;
long long sum;
long long modPow(long long n ,long long k , long long mod)
{
    long long ret = 1;
    while(k)
    {
        if (k&1)
            ret *= n; ret %= mod;
        k >>= 1;
        n = n*n; n%= mod;
    }
    return ret;
}
int main()
{
    int T;
    cin>>T;
    for (int cnt = 1; cnt <= T; cnt++)
    {
        cin>>N>>K>>MOD;
        sum = 0;
        for (int i = 0 ,x; i <N; i++)
        {
            cin>>x;
            sum+=x;
        }
        SN = modPow(N, K-1, MOD);
        sum  = (sum * SN % MOD * K) % MOD;
        cout<<"Case "<<cnt<<": "<<sum<<endl;
    }
}
