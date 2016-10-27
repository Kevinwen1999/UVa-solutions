#include <bits/stdc++.h>
#define MAXN 1000001
using namespace std;
int N;
long long a[MAXN];
long long C[MAXN];
int main()
{
    while (scanf("%d", &N) == 1)
    {
        long long sum = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%lld", &a[i]);
            sum += a[i];
        }
        long long avg = sum / N;
        long long tot = 0;
        C[0] = 0;
        for (int i = 1; i < N; i++)
            C[i] = C[i-1] + a[i] - avg;
        sort(C,C+N);
        long long x1 = C[N/2];
        for (int i = 0; i < N; i++)
            tot += abs(x1-C[i]);
        printf("%lld\n", tot);
    }
}
