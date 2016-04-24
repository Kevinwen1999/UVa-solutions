#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 30 + 5
using namespace std;
int blocks[MAXN][3];
int d[MAXN][3];
int N;
void get_dimension(int *v, int i, int j)
{
    for (int a = 0 ,idx = 0; a < 3; a++)
    {
        if (a!=j)
            v[idx++] = blocks[i][a];
    }
}
int dp(int i, int j) // i is the current block, j is the dimension set as height
{
    int &ans = d[i][j];
    if (ans > 0) return ans;
    ans = 0;
    int cur[2], nex[2];
    get_dimension(cur, i, j);
    for (int a = 0 ; a < N; a++)
        for (int b = 0; b < 3; b++)
        {
            get_dimension(nex, a, b);
            if (nex[0] < cur[0] && nex[1] < cur[1])
                ans = max(ans, dp(a,b));
        }
    ans += blocks[i][j];
    return ans;
}
int main()
{
    int cnt = 0;
    while (scanf("%d", &N) == 1 && N)
    {
        for (int i = 0 ; i < N; i++)
        {
            for (int j = 0 ; j < 3; j++)
                scanf("%d", &blocks[i][j]);
            sort(blocks[i],blocks[i]+3);
        }
        memset(d,0,sizeof d);
        int ans = 0;
        for (int i = 0 ; i < N; i++)
            for (int j = 0 ; j < 3; j++)
                ans = max(ans, dp(i, j));
        printf("Case %d: maximum height = %d\n", ++cnt, ans);
    }
}
