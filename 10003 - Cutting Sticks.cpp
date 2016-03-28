#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int l, n ;
int cuts[60];
int dp[60][60];
int DP(int leftid, int rightid)
{
    if (leftid+1==rightid) return 0;
    if (dp[leftid][rightid]!=-1)return dp[leftid][rightid];
    int ans = 99999999;
    for (int i = leftid+1; i < rightid; i++)
        ans = min(ans, DP(leftid,i)+DP(i,rightid)+(cuts[rightid]-cuts[leftid]));
    return dp[leftid][rightid]=ans;

}
int main()
{
    while(1)
    {
        cin>>l;
        if (l==0)break;
        cin>>n;
        memset(cuts,0,sizeof cuts);
        for (int i = 1 ; i <= n; i++)
            cin>>cuts[i];
        cuts[0] = 0; cuts[n+1] = l;
        memset(dp,-1,sizeof dp);
        cout<<"The minimum cutting is "<<DP(0,n+1)<<"."<<endl;
    }
    return 0;
}
