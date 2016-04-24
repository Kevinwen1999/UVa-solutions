#include <bits/stdc++.h>

using namespace std;
string in;
const int MAXN = 1000 + 5, INF = 9999999;
int ispa[MAXN][MAXN];
int dp[MAXN][MAXN];
int check(int i, int j)
{
    int &ans = ispa[i][j];
    if (~ans) return ans;
    if (i==j) return ans = 1;
    if (i+1==j)
    {
        if (in[i]==in[j]) return ans = 1;
        else return ans = 0;
    }
    if (in[i] == in[j])
        return ans = check(i+1,j-1);
    else
        return ans = 0;
}
int recur (int i, int j)
{
    int &ans = dp[i][j];
    if (~ans) return ans;
    if (check(i,j)) return ans = 1;
    ans = INF;
    for (int k = i; k < j; k++)
    {
        if (check(i,k))
            ans = min(ans, recur(k+1,j)+1);
    }
    return ans;
}
int en;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>in;
        en = in.size()-1;
        memset(ispa, -1, sizeof ispa);
        memset(dp, -1,sizeof dp);
        cout<<recur(0,en)<<endl;
    }
}
