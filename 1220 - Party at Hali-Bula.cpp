//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;
int N;
string in1, in2;
const int MAXN = 200 + 10;
vector <int> rooted[MAXN];
int dp[MAXN][2];
int only[MAXN][2];
int dfs(int cur, int stat)
{
    if (dp[cur][stat] != -1) return dp[cur][stat];
    int &ans = dp[cur][stat];
    if (rooted[cur].empty())
    {
        only[cur][stat] = 1;
        return ans = stat;
    }
    if (stat)
    {
        ans = stat;
        only[cur][stat] = 1;
        for (int i = 0; i < rooted[cur].size(); i++)
        {
            ans += dfs(rooted[cur][i], 0);
            if (!only[rooted[cur][i]][0])
                only [cur][stat] = 0;
        }
        return ans;
    }
    else
    {
        ans = stat;
        only[cur][stat] = 1;
        for (int i = 0 ; i < rooted[cur].size(); i++)
        {
            ans += max(dfs(rooted[cur][i],0), dfs(rooted[cur][i],1));
            if (dfs(rooted[cur][i],0) == dfs(rooted[cur][i],1))
                only[cur][stat] = 0;
            else if (dfs(rooted[cur][i],0) > dfs(rooted[cur][i],1))
            {
                if (!only[rooted[cur][i]][0])
                    only[cur][stat] = 0;
            }
            else
            {
                if (!only[rooted[cur][i]][1])
                    only[cur][stat] = 0;
            }
        }
        return ans;
    }
}
int main()
{
    while (cin>>N && N)
    {
        map <string, int> m;
        int idx = 0;
        cin>>in1;
        m[in1] = idx++;
        for (int i = 0; i < N; i++)
            rooted[i].clear();
        for (int i = 0; i < N-1; i++)
        {
            cin>>in1>>in2;
            if (!m.count(in1))
                m[in1] = idx++;
            if (!m.count(in2))
                m[in2] = idx++;
            rooted[m[in2]].push_back(m[in1]);
        }
        memset(dp,-1,sizeof dp);
        cout<<max(dfs(0,0), dfs(0,1))<<" ";
        if (dfs(0,0) > dfs(0,1))
        {
            if (only[0][0]) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else if (dfs(0,0) < dfs(0,1))
        {
            if (only[0][1]) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
}
