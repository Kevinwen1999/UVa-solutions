#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
int T, N;
int grid[20][20], gen[20][20];
int check(int first)
{
    memset(gen, 0, sizeof gen);
    int sum, tot = 0;
    for (int i = 0; i < N; i++)
    {
        if (first & (1<<i)) gen[0][i] = 1;
        else if (grid[0][i] == 1) return INF;
        if (gen[0][i] != grid[0][i]) tot++;
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum = 0;
            if (j > 0) sum += gen[i-1][j-1];
            if (i > 1) sum += gen[i-2][j];
            if (j < N - 1) sum += gen[i-1][j+1];
            gen[i][j] = sum%2;
            if (!gen[i][j] && grid[i][j]) return INF;
            if (gen[i][j] != grid[i][j]) tot++;
        }
    }
    return tot;
}
int main()
{
    scanf("%d", &T);
    for (int cnt = 1; cnt <= T; cnt++)
    {
        scanf("%d", &N);
        memset(grid, 0, sizeof grid);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &grid[i][j]);
        int ans = INF;
        for (int i = 0; i < (1<<N); i++)
        {
            ans = min(ans, check(i));
        }
        if (ans == INF) ans = -1;
        printf("Case %d: %d\n", cnt, ans);
    }
}
