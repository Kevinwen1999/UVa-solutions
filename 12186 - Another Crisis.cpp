#include <bits/stdc++.h>

using namespace std;
int N, T;
const int MAXN = 100000 + 10;
vector <int> rooted[MAXN];
int dfs(int cur)
{
    if (rooted[cur].empty()) return 1; // leaf
    int tot = rooted[cur].size();
    vector <int> temp;
    for (int i = 0 ; i < tot; i++)
        temp.push_back(dfs(rooted[cur][i]));
    sort(temp.begin(), temp.end());
    int needed = (tot*T-1) / 100 + 1; //manual ceiling
    int ans = 0;
    for (int i = 0 ;i < needed; i++)
        ans+= temp[i];
    return ans;
}
int main()
{
    while(cin>>N>>T)
    {
        if (!N && !T) break;
        for (int i = 0; i <= N; i++)
            rooted[i].clear();
        for (int i = 1, x; i <= N; i++)
        {
            cin>>x;
            rooted[x].push_back(i);
        }
        cout<<dfs(0)<<endl;
    }
}
