#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define INF 9999999
using namespace std;
string in;
int dp[90][90];
int N;
int recur (int l, int r)
{
    if (dp[l][r]!=-1) return dp[l][r];
    if (l==r) return dp[l][r] = 1;
    int len1, len2,tlen,j,k;
    tlen = r-l+1;
    int ans = INF;
    string sub1, sub2;
    for (int i = 1 ; i <=tlen ; i++)
    {
        if (tlen%i==0)
        {
            for ( k = l, j = 0; k <= r; k++)
            {
                if (in[k]!=in[j+l])
                    break;
                j++;
                if (j>=i) j = 0;
            }
            if (k==r+1&&r!=l+i-1)
                ans = min(ans,recur(l,l+i-1));
        }
    }
    for (int i = l ; i < r; i++)
    {
        len1= recur (l,i); len2 = recur(i+1,r);
        ans = min(ans, len1+len2);
    }
    return dp[l][r] = ans;
}
int main()
{
    while(1)
    {
        cin>>in;
        if (in=="*") break;
        memset(dp,-1,sizeof dp);
        N = in.size()-1;
        cout<<recur(0,N)<<endl;
    }
    return 0;
}
