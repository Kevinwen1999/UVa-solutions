#include <bits/stdc++.h>
using namespace std;
int T;
unsigned long long a, b;
int n;
int f[1000*1000+500];
unsigned long long pow_mod(unsigned long long a, unsigned long long b, unsigned long long n)
{
    if (b == 0) return 1;
    unsigned long long ans = pow_mod(a, b/2, n);
    ans = ans * ans % n;
    if (b%2 == 1) ans = ans * a % n;
    return ans;
}
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        cin>>a>>b>>n;
        f[0] = 0; f[1] = 1 % n;
        int period = 1;
        for (int i = 2; i < n*n+100; i++)
        {
            f[i] = (f[i-1] +f[i-2]) % n;
            if (f[i-1] == f[0] && f[i] == f[1])
            {
                period = i-1;
                break;
            }
        }
        unsigned long long ans = pow_mod(a%period, b, (unsigned long long)period);
        cout<<f[ans]<<endl;
    }
}
