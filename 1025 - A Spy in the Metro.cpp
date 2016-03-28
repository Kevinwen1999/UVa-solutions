#include <iostream>
#include <cstring>
#define INF 9999999
using namespace std;
int N,T;
int trans1[51],trans2[51];
int M1, M2;
int start[51],fin[51];
bool hasright[500][51];
bool hasleft[500][51];
int dp[250][51];
int mintime (int timeused, int station)
{
    if (timeused>T) return INF;
    if (station == N-1&&timeused==T) return 0;
    if (dp[timeused][station]!=-1) return dp[timeused][station];
    int ans = INF;
    if(hasright[timeused][station]&&station!=N-1)
        ans = min(ans,mintime(timeused+trans1[station],station+1));
    if(hasleft[timeused][station]&&station!=0)
        ans = min(ans,mintime(timeused+trans2[station],station-1));
    ans = min(ans, mintime(timeused+1,station)+1);
    return dp[timeused][station] = ans;
}
int main()
{
    int cnt = 1;
    while (1)
    {
        cin.sync_with_stdio(0);
        cin.tie(0);
        cin>>N;
        if (N==0) break;
        cin>>T;
        for (int i = 0 ,temp; i < N-1; i++)
        {
            cin>>temp;
            trans1[i] = trans2[i+1] = temp;
        }
        cin>>M1;
        for (int i = 0 ; i < M1; i++)
            cin>>start[i];
        cin>>M2;
        for (int i = 0 ; i < M2; i++)
            cin>>fin[i];
        memset(dp,-1,sizeof dp);
        memset(hasright,0,sizeof hasright);
        memset(hasleft,0,sizeof hasleft);
        int curtime;
        for (int i = 0 ; i < M1; i++)
        {
            curtime = start[i];
            hasright[curtime][0] = true;
            for (int j = 0 ; j < N-1; j++)
            {
                curtime+=trans1[j];
                hasright[curtime][j+1] = true;
            }
        }
        for (int i = 0 ; i < M2; i++)
        {
            curtime = fin[i];
            hasleft[curtime][N-1] = true;
            for (int j = N-1 ; j >0; j--)
            {
                curtime+=trans2[j];
                hasleft[curtime][j-1] = true;
            }
        }
        cout<<"Case Number "<<cnt<<": ";
        if (mintime(0,0)==INF)
            cout<<"impossible"<<"\n";
        else
            cout<<mintime(0,0)<<"\n";
        cnt++;
    }
    return 0;
}
