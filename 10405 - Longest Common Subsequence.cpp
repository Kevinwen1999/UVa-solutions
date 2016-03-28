#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string str1, str2;
int  len1, len2;
int dp[1100][1100];
int recur (int m, int n)
{
    if (m==-1||n==-1) return 0;
    if (dp[m][n]!=-1) return dp[m][n];
    if (str1[m]==str2[n]) return dp[m][n] = 1+ recur(m-1,n-1);
    return dp[m][n] = max(recur(m-1,n),recur(m,n-1));
}
int main()
{
    while(getline(cin,str1))
    {
        getline(cin,str2);
        len1 = str1.size(); len2 = str2.size();
        memset(dp,-1,sizeof dp);
        cout<<recur(len1-1,len2-1)<<endl;
    }
    return 0;
}
