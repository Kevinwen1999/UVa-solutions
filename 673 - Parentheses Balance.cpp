#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll unsigned long long
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-9
#define EPSS 1e-10

#define MAXN 100010
#define MAXL 5010
#define SEGN 300030
using namespace std;

int N;
char S[200];
int dp[200][200];
inline bool sametype(int i, int j) {
    if (S[i] == '(' && S[j] == ')') return true;
    if (S[i] == '[' && S[j] == ']') return true;
    return false;
}
bool check(int l, int r) {
    if (l > r) return true;
    if (l == r) return false;
    if (~dp[l][r]) return dp[l][r];
    if (sametype(l, r) && check(l + 1, r - 1)) return dp[l][r] = true;
    for (int i = l + 1; i < r - 1; i++){
        if (check(l, i) && check(i + 1, r))
            return dp[l][r] = true;
    }
    return dp[l][r] = false;
}
int main() {
    int T;
    cin >> T;
    cin.getline(S, 200);
    while (T--) {
        memset(dp, -1, sizeof dp);
        cin.getline(S, 200);
        N = strlen(S);
        cout << (check(0, N - 1) ? "Yes\n" : "No\n");
    }
}
