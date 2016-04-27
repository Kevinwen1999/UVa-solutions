#include <bits/stdc++.h>

using namespace std;
string in;
int N;
const int MAXN = 100 + 5;
int dp[MAXN][MAXN];
bool ismatch(char a, char b)
{
    if (a=='(' && b ==')') return true;
    if (a=='[' && b==']') return true;
    return false;
}
void print(int i, int j) //recursive
{
    if (i > j) return; //for blank ones
    if (i==j)
    {
        if (in[i]=='(' || in[i] == ')') cout<<"()";
        else cout<<"[]";
        return;
    }
    int &ans = dp[i][j];
    if (ismatch(in[i],in[j]) && ans == dp[i+1][j-1])
    {
        cout<<in[i];print(i+1,j-1);cout<<in[j];
        return;
    }
    for (int k = i; k < j; k++)
    {
        if (ans == dp[i][k] + dp[k+1][j])
        {
            print(i,k); print(k+1,j);
            return;
        }
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    getline(cin,in);
    while (T--)
    {
        getline(cin,in);
        getline(cin,in);
        N = in.size();
        //DP
        for (int i = 0 ; i < N; i++)
        {
            dp[i+1][i] = 0; // for blanks
            dp[i][i] = 1;
        }
        for (int i = N-2; i >= 0; i--)
        {
            for (int j = i+1; j < N; j++)
            {
                dp[i][j] = N;
                if (ismatch(in[i],in[j]))
                    dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
                for (int k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k+1][j]);
            }
        }

        print(0,N-1); cout<<"\n";
        if (T) cout<<"\n";
    }
}
