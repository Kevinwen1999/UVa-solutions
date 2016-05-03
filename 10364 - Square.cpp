#include <bits/stdc++.h>

using namespace std;
int num[30];
int N;
int sum;
int dp[1<<20][5];
int tmp;
bool recur(int b, int dcnt)
{
    if (~dp[b][dcnt]) return dp[b][dcnt];
    if (b == (1<<N)-1) return dp[b][dcnt] = (dcnt == 4); //all sticks are chosen
    dp[b][dcnt] = 0;
    for (int i = 0, bnext; i < N; i++)
    {
        if (b & (1<<i)) continue; //already chosen
        if (tmp + num[i] <= sum * (dcnt + 1))
        {
            tmp += num[i]; //add this edge
            bnext = b | (1<<i);
            if (tmp < sum * (dcnt+1) && recur(bnext, dcnt)) dp[b][dcnt] = 1; //if edge is incomplete
            if (tmp == sum * (dcnt+1) && recur(bnext, dcnt+1)) dp[b][dcnt] = 1; //else if it's complete
            tmp -= num[i]; //restore global value
        }
    }
    return dp[b][dcnt];
}
int main()
{
    int T; cin>>T;
    while(T--)
    {
        sum = tmp = 0;
        cin>>N;
        for (int i = 0 ; i < N; i++)
        {
            cin>>num[i];
            sum+=num[i];
        }
        if (sum %4 != 0) {cout<<"no"<<"\n"; continue;}
        sum/=4;
        memset(dp,-1,sizeof dp);
        if (recur(0,0)) cout<<"yes"<<"\n";
        else cout<<"no\n";
    }
}
