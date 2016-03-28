#include <iostream>
#include <cstring>
#include <string>
#define MOD 1000007
using namespace std;
string in;
int T;
int N;
char grid[110][110];
long long dp[110][110];
int main()
{
    cin>>T;
    for (int t = 1; t <= T; t++)
    {
        cin>>N;
        memset(dp,0,sizeof dp);
        for (int i = 0 ; i < N; i++)
        {
            cin>>in;
            for (int j = 0 ; j < N; j++)
            {
                grid[i][j] = in[j];
                if (in[j]=='W') dp[i][j] = 1;
            }
        }
        int lefti, leftj, righti, rightj;
        for (int i = N-1; i>0; i--)
        {
            for (int j = 0 ; j < N; j++)
            {
                if (dp[i][j]!=0&&grid[i][j]!='B')
                {
                    lefti = i-1;
                    leftj = j-1;
                    if (lefti>=0&&leftj>=0&&lefti<=N&&leftj<=N)
                    {
                        if (grid[lefti][leftj] == 'B')
                        {
                            lefti = lefti - 1;
                            leftj = leftj - 1;
                            if (lefti>=0&&leftj>=0&&lefti<=N&&leftj<=N)
                            {
                                dp[lefti][leftj]+=dp[i][j];
                                dp[lefti][leftj]%= MOD;
                            }
                        }
                        else
                        {
                            dp[lefti][leftj]+=dp[i][j];
                            dp[lefti][leftj]%= MOD;
                        }
                    }
                    righti = i-1;
                    rightj = j + 1;
                    if (rightj>=0&&righti>=0&&rightj<=N&&righti<=N)
                    {
                        if (grid[righti][rightj] == 'B')
                        {
                            righti = righti - 1;
                            rightj = rightj + 1;
                            if (rightj>=0&&righti>=0&&rightj<=N&&righti<=N)
                            {
                                dp[righti][rightj]+=dp[i][j];
                                dp[righti][rightj] %= MOD;
                            }
                        }
                        else
                        {
                            dp[righti][rightj]+=dp[i][j];
                            dp[righti][rightj] %= MOD;
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 0 ; i < N; i++)
        {
            if (grid[0][i]!='B')
            {
                 ans+=dp[0][i];
                 ans %= 1000007;
            }
        }
        ans %= 1000007;
        cout<<"Case "<<t<<": "<<ans<<endl;
        /*for (int i = 0 ; i < N; i++)
        {
            for (int j = 0 ; j  < N; j++)
                cout<<dp[i][j];
            cout<<endl;
        }*/
    }
}
