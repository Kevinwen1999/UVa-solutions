#include <iostream>
#include <cstring>
using namespace std;
inline int maxx(int a, int b){return a>b?a:b;}
int T,G,W,N,curmax ;
int price[1025], weight[1025];
int dp[1025][35];
int main()
{
    cin>>T;
    while (T--)
    {
        memset(price,0,sizeof price);
        memset(weight,0,sizeof weight);
        cin>>N;
        for (int i = 1 ; i <= N ; i++)
            cin>>price[i]>>weight[i];
        cin>>G;
        curmax = 0;
        for (int cnt = 0; cnt < G; cnt++)
        {
            cin>>W;
            memset(dp,0,sizeof dp);
            for (int item = 1; item <= N; item++)
            {
                for (int w = 0 ; w <= W ; w++)
                {
                    if (w<weight[item])
                        dp[item][w] = dp[item-1][w];
                    else
                        dp[item][w] = maxx(dp[item-1][w],dp[item-1][w-weight[item]]+price[item]);
                }
            }
            curmax+=/*maxx(curmax,*/dp[N][W]/*)*/;
        }
        cout<<curmax<<endl;
    }
    return 0;
}
