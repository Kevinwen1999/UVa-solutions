#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
int grid[2010][2010], dp[2010][2010];
int lx[4010], rx[4010], ly[4010], ry[4010];
long long x[4010], y[4010];
int M, N, W;
int cases;
int main()
{
    while (scanf("%d %d %d", &M, &N, &W) == 3 && N+M)
    {
        map <int,int> Rx, Ry;
        Rx[0] = 1; Ry[0] = 1; //push in 0,0 indicating the bottom
        Rx[N] = 1; Ry[M] = 1; //push in N,M as destination (we are using 1 indexing)
        for (int i = 0; i < W; i++)
        {
            scanf("%d %d %d %d", &lx[i], &ly[i], &rx[i], &ry[i]);
            rx[i]++; ry[i]++;
            //the reason for not changing lx and ly to 1 indexing is because we need a place holder to indicate the wR
            //if we change everything into 1 indexing then there will be only 1 point left when pushed into the map
            Rx[lx[i]] = 1; Ry[ly[i]] = 1; // for example, if we don't store ly in Ry,
            Rx[rx[i]] = 1; Ry[ry[i]] = 1;
        }
        int szx = 0, szy = 0;
        for (map <int,int>:: iterator it = Rx.begin(); it != Rx.end(); it++) // iterate through map
        {
            it->second = szx;
            x[szx++] = it->first;
        }
        for (map <int,int>:: iterator it = Ry.begin(); it != Ry.end(); it++)
        {
            it->second = szy;
            y[szy++] = it->first;
        }
        memset(grid, 0, sizeof grid);
        memset(dp,0,sizeof dp);
        // construct graph
        for (int i = 0; i < W; i++)
        {
            int llx = Rx[lx[i]], rrx = Rx[rx[i]];
            int rry = Ry[ry[i]]; // ly doesn't matter since all wall are west-east
            for (int cur = llx + 1; cur <= rrx; cur++) // finally changing lx to 1 indexing
                grid[cur][rry] = 1;
        }
        // Now DP
        dp[szx-1][szy-1] = 1;
        long long ans = 0;
        for (int i = szx - 1; i > 0; i--)
        {
            for (int j = szy - 1; j > 0; j--)
            {
                if (grid[i][j]) continue;
                if (!dp[i][j]) // unreachable
                    ans += (x[i] - x[i-1]) * (y[j] - y[j-1]); // add rectangle area
                if (dp[i][j])
                {
                    dp[i-1][j] = dp[i][j];
                    dp[i][j-1] = dp[i][j];
                }
            }
        }
        /*cout<<"\n";
        for (int i = szx - 1; i > 0; i--)
        {
            for (int j = szy - 1; j > 0; j--)
            {
                cout<<grid[i][j];
            }
            cout<<"\n";
        }
        cout<<"\n";
        for (int i = szx - 1; i > 0; i--)
        {
            for (int j = szy - 1; j > 0; j--)
            {
                cout<<dp[i][j];
            }
            cout<<"\n";
        }*/
        printf("Case %d: %lld\n", ++cases, ans);
    }
}
