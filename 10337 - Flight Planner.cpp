#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
inline int min(int a, int b) {return a < b? a: b;}
inline int min(int a, int b, int c) {return min(min(a,b),c);}
int N,X;
int wind[1010][10], dp[1010][10];
int main()
{
    cin>>N;
    while (N--)
    {
        cin>>X;
        X/=100;
        for (int i = 9 ; i >=0; i--)
            for (int j = 1; j <= X; j++)
                cin>>wind[j][i];
        memset(dp,63,sizeof dp);
        dp[0][0] = 0 ;
        for (int i = 1 ; i <= X; i++)
        {
            for (int j = 0; j < 10 ; j++)
            {
                int down = INF, hold = INF, up = INF;
                if (j-1>=0) up = dp[i-1][j-1] + 60 - wind[i][j-1];
                if (j+1<10) down = dp[i-1][j+1] + 20 - wind[i][j+1];
                hold = dp[i-1][j] + 30 - wind[i][j];
                dp[i][j] = min(down,hold,up);
            }
        }
        cout<<dp[X][0]<<endl<<endl;
    }
}
