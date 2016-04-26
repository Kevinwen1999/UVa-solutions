#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000 + 5;
const int INF = 99999999;
const int MAXA = 26;
char in1[MAXN], in2[MAXN];
int s1[MAXA], s2[MAXA], e1[MAXA], e2[MAXA]; // starting and ending index for each letter
int dp[2][MAXN], inc[2][MAXN]; //inc : the number of colours that haven't finished
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s%s", in1+1, in2 + 1);

        int N = strlen(in1+1), M = strlen(in2+1);
        for (int i = 1; i <= N; i++) in1[i] -= 'A';
        for (int i = 1; i <= M; i++) in2[i] -= 'A';
        // calculate starting point and ending point
        for (int i = 0 ; i < MAXA; i++)
        {
            s1[i] = s2[i] = INF;
            e1[i] = e2[i] = 0;
        }
        for (int i = 1; i <= N; i++)
        {
            s1[in1[i]] = min(s1[in1[i]], i);
            e1[in1[i]] = i;
        }
        for (int i = 1; i <= M; i++)
        {
            s2[in2[i]] = min(s2[in2[i]], i);
            e2[in2[i]] = i;
        }
        //DP
        int flag = 0;
        memset(dp,0,sizeof dp);
        memset(inc,0,sizeof inc);
        int v1, v2;
        for (int i = 0 ; i <= N; i++)
        {
            for (int j = 0 ; j <= M; j++)
            {
                if (!i&&!j) continue;
                v1 = v2 = INF;
                if (i) v1 = dp[flag^1][j] + inc[flag^1][j]; //delete from in1
                if (j) v2 = dp[flag][j-1] + inc[flag][j-1]; //delete from in2
                dp[flag][j] = min(v1, v2);

                if (i)
                {
                    inc[flag][j] = inc[flag^1][j];
                    if (s1[in1[i]] == i && s2[in1[i]] > j ) inc[flag][j]++; //start a letter
                    if (e1[in1[i]] == i && e2[in1[i]] <= j) inc[flag][j]--; //end a letter
                }
                else if (j)
                {
                    inc[flag][j] = inc[flag][j-1];
                    if (s2[in2[j]] == j && s1[in2[j]] > i ) inc[flag][j]++; //start a letter
                    if (e2[in2[j]] == j && e1[in2[j]] <= i) inc[flag][j]--; //end a letter
                }
            }
            flag ^= 1;
        }
        printf("%d\n", dp[flag^1][M]);
    }
}
