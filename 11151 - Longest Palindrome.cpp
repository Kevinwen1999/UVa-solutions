#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int T,length;
string in;
int dp[1010][1010];
int recur(int l, int r)
{
    if (dp[l][r]!= -1 ) return dp[l][r];
    if (l==r) return dp[l][r]= 1;
    if (l+1==r)
    {
        if (in[l]==in[r])
            return dp[l][r]= 2;
        else
            return dp[l][r]= 1;
    }
    if (in[l]==in[r])
        return dp[l][r] = recur (l+1,r-1)+2;
    return dp[l][r] = max(recur(l,r-1),recur(l+1,r));
}
int main()
{
    cin>>T;
    string dummy;
    getline(cin, dummy);
    while (T--)
    {
        getline(cin,in);
        memset(dp,-1,sizeof dp);
        length = in.length();
        if (length==0) cout<<0<<endl;
        else cout<<recur(0,length-1)<<endl;
    }
}
