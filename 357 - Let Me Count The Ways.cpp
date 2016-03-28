/*#include <iostream>
#include <cstring>
using namespace std;
inline int maxx(int a, int b){return a>b?a:b;}
int N;
long long  dp[6][30050];
int coin[] = {0,1,5,10,25,50};
int main()
{
    for (int i = 0 ; i  <=30020 ; i++) dp[0][i] = 0;
    for (int i = 0 ; i  < 6 ; i++) dp[i][0] = 1;
    for (int i = 1 ; i <= 5; i++)
    {
        for (int j = 0 ; j <= 30020; j++)
        {
            if (coin[i]>j)
                dp[i][j] = dp[i-1][j];
            else
                {
                    dp[i][j] = dp[i-1][j]+dp[i][j-coin[i]];
                }
        }
    }
    cin>>N;
    while(!cin.eof())
    {
        cout<<"There ";
        if (dp[5][N]!=1)cout<<"are "<<dp[5][N]<<" ways ";
        else cout<<"is only 1 way ";
        cout<<"to produce "<<N<<" cents change."<<endl;
        cin>>N;
    }
    return 0;
}
*/

#include<cstdio>

int m, coins[] = { 1, 5, 10, 25, 50 };
long ways[30010] = { 0 };

int main() {
    ways[0] = 1;
    for(int i = 0; i < 5; i++)
        for(int j = coins[i]; j <= 30000; j++)
            ways[j] += ways[j - coins[i]];
    while(scanf("%d", &m) == 1)
        printf(ways[m] == 1? "There is only %ld way to produce %d cents change.\n" :
            "There are %ld ways to produce %d cents change.\n", ways[m], m);
}

