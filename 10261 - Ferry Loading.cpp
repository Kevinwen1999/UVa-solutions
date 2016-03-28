#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define LL long long
#define N 2005
#define M 10005
#define inf 0x3fffffff

int dp[N][M], w[N], sum[N];
int pre[N][M], ans[N];

int main()
{
    int t, i, j, k, V, n, vj;
    cin >> t;
    while (t--)
    {
        cin >> V;
        V *= 100;
        memset (dp, 0, sizeof(dp));
        dp[0][0] = 1;
        n = 0;
        sum[0] = 0;
        while(cin >> k, k)
        {
            ++n;
            w[n] = k;
            sum[n] = sum[n-1] + k;
        }
        vj = -1;
        for (i = 1; i <= n; i++)
        {
            for (j = 0; j <= V; j++)
            {
                if (j >= w[i] && dp[i-1][j-w[i]]) {
                    k = i;
                    vj = j;
                    dp[i][j] = 1;
                    pre[i][j] = j-w[i];
                } else if (sum[i]-j <= V && dp[i-1][j]) {
                    k = i;
                    vj = j;
                    dp[i][j] = 1;
                    pre[i][j] = j;
                }
            }
        }
        i = k;
        while (i--)
        {
            j = pre[i+1][vj];
            if (j == vj) ans[i] = 1;
            else ans[i] = 0;
            vj = j;
        }
        cout << k << endl;
        for (i = 0; i < k; i++)
        {
            if (ans[i]) puts ("starboard");
            else puts ("port");
        }
        if (t) puts("");
    }
    return 0;
}
