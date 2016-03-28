#include <iostream>
#include <cstring>
using namespace std;
inline int maxx(int a, int b){return a>b?a:b;}
int N;
int dp[6][7500];
int coin[] = {0,1,5,10,25,50};
int main()
{
    for (int i = 0 ; i  <7490 ; i++) dp[0][i] = 0;
    for (int i = 0 ; i  < 6 ; i++) dp[i][0] = 1;
    for (int i = 1 ; i <= 5; i++)
    {
        for (int j = 0 ; j < 7490; j++)
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
        cout<<dp[5][N]<<endl;
        cin>>N;
    }
    return 0;
}
