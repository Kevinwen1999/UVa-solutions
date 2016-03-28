#include <iostream>
#include <cstring>
#include <cstring>
#include <algorithm>
using namespace std;
string str1, str2;
int cnt = 0, len1, len2;
int dp[110][110];
int recur (int m, int n)
{
    if (m==-1||n==-1) return 0;
    if (dp[m][n]!=-1) return dp[m][n];
    if (str1[m]==str2[n]) return dp[m][n] = 1+ recur(m-1,n-1);
    return dp[m][n] = max(recur(m-1,n),recur(m,n-1));
}
int main()
{
    while(1)
    {
        getline(cin,str1);
        if (str1=="#") break;
        getline(cin,str2);
        cnt++;
        len1 = str1.size(); len2 = str2.size();
        memset(dp,-1,sizeof dp);
        if (len1==0||len2==0)
            cout<<"Case #"<<cnt<<": you can visit at most "<<0<<" cities."<<endl;
        else
            cout<<"Case #"<<cnt<<": you can visit at most "<<recur(len1-1,len2-1)<<" cities."<<endl;
    }
    return 0;
}
