#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 5;
int N, s[MAXN], dp[MAXN];
struct node
{
    int v, c, k ,l;
} node1, node2;
bool operator < (const node &a, const node &b)
{
    return a.v < b.v;
}
int main()
{
    while (cin>>N && N)
    {
        vector <node> bulb;
        for (int i = 0 ; i < N; i++)
        {
            cin>>node1.v>>node1.c>>node1.k>>node1.l;
            bulb.push_back(node1);
        }
        sort(bulb.begin(), bulb.end());
        s[0] = bulb[0].l;
        for (int i = 1; i < N; i++)
            s[i] = s[i-1] + bulb[i].l;
        dp[0] = 0;
        int p1;
        for (int i = 0 ; i < N; i++)
        {
            dp[i] = s[i] * bulb[i].k + bulb[i].c;
            for (int j = 0; j<= i; j++)
            {
                //p1 = (j-1 < 0) ? 0 : s[j-1];
                dp[i] = min(dp[i],dp[j] + (s[i] - s[j]) * bulb[i].k + bulb[i].c);
            }
        }
        cout<<dp[N-1]<<endl;
    }
}
