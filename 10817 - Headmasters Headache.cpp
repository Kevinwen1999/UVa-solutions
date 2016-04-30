#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int S, M, N;
const int MAXN = 100 + 20 + 10;
const int MAXS = 8;
int pay[MAXN], teach[MAXN], dp[MAXN][1<<MAXS][1<<MAXS];
int recur(int i, int b1, int b2) // b1 rep subjects that has only one teacher, b2 rep subjects that has two teacher
{
    if (i== M+N)
        return b2 == ((1<<S)-1) ? 0 : INF;
    int &ans = dp[i][b1][b2];
    if (~ans) return ans;
    ans = INF;
    if (i >= M) ans = recur(i+1, b1, b2); //skip the applicant
    b2 |= (b1 & teach[i]); // b2 must come first to keep the original b1 value when calculating
    b1 |= teach[i];
    ans = min(ans, pay[i] + recur(i+1,b1,b2));
    return ans;
}
int main()
{
    while (cin>>S>>M>>N && S)
    {
        cin.get();
        string in;
        for (int i = 0, tmp; i < M + N; i++)
        {
            getline(cin,in);
            stringstream ss(in);
            ss>> pay[i]; teach[i] = 0;
            while(ss>>tmp)
                teach[i] |= 1 << (tmp-1);
        }
        memset(dp,-1,sizeof dp);
        cout<< recur(0,0,0)<<"\n";
    }
}
