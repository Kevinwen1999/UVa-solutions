#include <iostream>
using namespace std;
const int MAXN = 50010;
int phi[MAXN];
int sum[MAXN];
void phitable(int n, int *phi)
{
    for (int i = 2; i <= n; i++)
        phi[i] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!phi[i])
        {
            for (int j = i; j <= n; j += i)
            {
                if (!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i-1);
            }
        }
    }
}

int main()
{
    int N;
    phitable(MAXN, phi);
    for (int i = 2; i <= MAXN; i++)
        sum[i] = sum[i-1] + phi[i];
    while(scanf(" %d",&N)==1 && N)
        printf("%d\n",2*sum[N]+1);
}
