#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
#define MAXN 1000 + 10
int x[MAXN], y[MAXN];
double dp[MAXN][MAXN], dist[MAXN][MAXN];
int N;
double di(int a, int b)
{
    return hypot(x[a]-x[b], y[a] - y[b]);
}
double recur(int a, int b)
{
    if (dp[a][b]!=-1.0) return dp[a][b];
    if (a==N-1)
    {
        return dp[a][b] = dp[b][a] = dist[b][N-1];
    }
    return dp[a][b] = dp[b][a] = min(recur(a+1,b) + dist[a][a+1] , recur(a+1, a) + dist[b][a+1]);
}
int main()
{
    cout<<fixed<<setprecision(2);
    while(cin>>N)
    {
        for (int i = 0 ; i < N; i++)
            for (int j = 0 ; j < N; j++)
                dp[i][j] = -1.0;
        for (int i = 0,a,b ; i < N; i++)
            cin>>x[i]>>y[i];
        for (int i = 0; i < N-1; i++)
            for (int j = i + 1; j < N; j++)
                dist[i][j] = dist[j][i] = di(i,j);
        cout<<recur(0,0)<<endl;
    }
}
