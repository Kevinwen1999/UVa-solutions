#include <iostream>
#include <cstring>
using namespace std;
int N,M,C;
int price[25][25];
bool dp[25][210], hass = false;
int main()
{
    cin>>N;
    while (N--)
    {
        hass = false;
        memset(dp,0,sizeof dp);
        memset(price,0, sizeof price);
        cin>>M>>C;
        for (int i = 0 ; i < C; i++)
        {
            cin>>price[i][0];
            for (int j = 1; j <= price[i][0]; j++)
                cin>>price[i][j];
        }
        for (int i = 1 ; i <= price[0][0]; i++)
        {
            if (price[0][i]<=M)
            {
                dp[0][M-price[0][i]] = true;
            }
        }
        for (int i = 0; i < C-1; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (dp[i][j])
                {
                    for (int k = 1 ; k <= price[i+1][0]; k++)
                    {
                        if (j-price[i+1][k]>=0)
                            dp[i+1][j-price[i+1][k]]=true;
                    }
                }
            }
        }
        for (int i = 0; i <= M; i++)
        {
            if (dp[C-1][i])
            {
                hass = true;
                cout<<M-i<<endl;
                break;
            }
        }
        if (!hass)
            cout<<"no solution"<<endl;
    }
    return 0;
}
