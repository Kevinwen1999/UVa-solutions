#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N;
vector <int> adj[2000];
int dp[2000];
int dfs(int cur)
{
    if (dp[cur]!=-1 ) return dp[cur];
    int ans = 0;
    for (int i = 0,next ; i < (int) adj[cur].size(); i++)
    {
        next = adj[cur][i];
        ans+=dfs(next);
    }
    if (ans==0) ans = 1;
    return dp[cur] = ans;
}
int cnt = 0;
int main()
{
    while(1)
    {
        cin>>N;
        if (cin.eof())
            break;
        if (cnt>0) cout<<endl;
        cnt++;
        for (int i = 0 ; i  <2000; i++)
            adj[i].clear();
        for (int i = 0 ,choice; i < N; i++)
        {
            cin>> choice;
            for (int j = 0, next ; j < choice; j++)
            {
                cin>>next;
                adj[i].push_back(next);
            }
        }
        memset(dp,-1,sizeof dp);
        cout<<dfs(0)<<endl;
    }
}
