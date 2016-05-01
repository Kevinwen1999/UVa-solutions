#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
const int MAXN = 128 + 10;
int M, N, item[MAXN];
int dp[(1<<11)][(1<<11)]; // state : set already chosen, set that indicates the answer
string in;

int recur (int b1, int b2)
{
    int &ans = dp[b1][b2];
    if (~ans) return ans;
    int cnt = 0;
    for (int i = 0 ; i < N; i++)
        if ((item[i] & b1) == b2) // if the item matches with the answer
            cnt ++;
    if (cnt <= 1) return ans = 0;
    ans = INF;
    for (int i = 0, bnext ; i < M; i++)
    {
        if (b1 & (1<<i)) continue; //already asked
        bnext = b1 | (1<<i);
        ans = min(ans, max(recur(bnext, b2), recur(bnext, b2 ^ (1<<i)))+1);
    }
    return ans;
}

int main()
{
    while(cin>>M>>N)
    {
        if (!M && !N) break;
        for (int i = 0, tmp; i < N; i++)
        {
            item[i] = 0;
            cin>>in;
            for (int j = 0; j < M; j++)
            {
                tmp = in[j] - '0';
                if (tmp) item[i] |= (1<<j);
            }
        }
        memset(dp, -1, sizeof dp);
        cout<<recur(0,0)<<"\n";
    }
}
