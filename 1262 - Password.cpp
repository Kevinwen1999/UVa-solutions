#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector <char> g[5];
string ans;
bool dfs(int d)
{
    if (d == 5) return true;
    int tot = 1; // posibility of all letters behind current one (product rule)
    for (int i = d+1; i < 5; i++)
    {
        tot *= (int) g[i].size();
    }
    for (int k = 0; k < (int)g[d].size(); k++)
    {
        if (k*tot < N && (k+1)*tot >= N)
        {
            ans +=g[d][k];
            N-= k*tot;
            return dfs(d+1);
        }
    }
    return false;
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        cin>>N;
        ans = "";
        string grid1[6], grid2[6];
        for (int i = 0; i < 6; i++)
            cin>>grid1[i];
        for (int j = 0; j < 6; j++)
            cin>>grid2[j];
        for (int i = 0; i < 5; i++)
        {
            g[i].clear();
            for (int j = 0; j < 6; j++)
            {
                for (int k = 0; k < 6; k++)
                {
                    if (grid1[j][i] == grid2[k][i])
                    {
                        g[i].push_back(grid1[j][i]);
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < 5; i++)
        {
            sort(g[i].begin(), g[i].end());
        }
        if (dfs(0)) cout<<ans<<"\n";
        else cout<<"NO\n";
    }
}
