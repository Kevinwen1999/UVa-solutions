#include <bits/stdc++.h>
#define MOD 20071027
#define MAXM 301000
#define MAXN 110
#define SIGMA 30
using namespace std;
string in, tmp;
int N;
int dp[MAXM];
int ch[4000 * 100 + 10][SIGMA];
int val[4000 * 100 + 10];
vector <int> prefix[MAXM];
int sz;
void init_trie() {
    sz = 1;
    memset(ch, 0, sizeof ch);
    memset(val, 0, sizeof val);
    for (int i = 0; i < in.size(); i++)
        prefix[i].clear();
}
int getidx(char c) {
    return c - 'a';
}
void add_word(string &s, int v) {
    int u = 0;
    for (int i = 0; i < s.size(); i++) {
        int cc = getidx(s[i]);
        if (!ch[u][cc]) {
            ch[u][cc] = sz++;
        }
        u = ch[u][cc];
    }
    val[u] = v;
//    cout<<"Word ends at "<<u<<"\n";
}
void calc(int idx) {
    int u = 0;
    for (int i = idx; i < in.size(); i++) {
        int cc = getidx(in[i]);
        if (!ch[u][cc]) break;
        u = ch[u][cc];
        if (val[u])
            prefix[idx].push_back(val[u]);
    }
}
int DP(int idx) {
    if (idx > in.size()) return 0;
    if (idx == in.size()) return 1;
    if (~dp[idx]) return dp[idx];
    dp[idx] = 0;
    for (int i : prefix[idx]) {
        dp[idx] = (dp[idx] + DP(idx + i)) % MOD;
    }
    return dp[idx];
}
int main() {
    int kc = 0;
    while(cin>>in) {
        kc++;
        init_trie();
        cin>>N;
        for (int i = 0; i < N; i++) {
            cin>>tmp;
            add_word(tmp, tmp.size());
        }
        memset(dp, -1, sizeof dp);
//        dp[in.size()] = 1;
        for (int i = in.size() - 1; i >= 0; i--) {
            calc(i);
//            for (int j : prefix[i]) {
////                cout<<":: "<<j<<"\n";
//                dp[i] = (dp[i] + dp[i + j]) % MOD;
//            }
////            cout<<dp[i]<<"\n";
        }
//        for (int i = 0; i < sz; cout<<val[i++]<<"\n");
        printf("Case %d: %d\n", kc, DP(0));
    }
}
