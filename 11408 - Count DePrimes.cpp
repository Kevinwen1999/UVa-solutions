#include <bitset>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 5000000 + 9;
long long prime[MAXN];
int a, b;
long long sum[MAXN];
int main()
{
    //memset(nDiffPM, 0, sizeof nDiffPM);
    long long i, j;
    for (i = 2; i < MAXN; i++)
    {
        sum [i] = sum[i-1];
        if (!prime[i])
        {
            sum[i]++;
            for (j = i+i; j < MAXN; j+=i)
                prime[j]+=i;
        }
        else if (!prime[prime[i]]) sum[i]++;
    }
    while (scanf("%d", &a) && a)
    {
        scanf("%d", &b);
        printf("%lld\n", sum[b] - sum[a-1]);
    }
}
