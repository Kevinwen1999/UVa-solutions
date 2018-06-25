#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 1010
#define ll long long
using namespace std;

int N, B, tot;
map <string, int> mp;
vector <pair <ll, int> > comp[MAXN];
bool check(ll lim) {
    int t = 0;
    for (int i = 0; i < tot; i++) {
        int mn = INF;
        for (auto& j : comp[i]) {
            if (j.first >= lim) {
                mn = min(mn, j.second);
            }
        }
        if (mn == INF) return false;
        t += mn;
    }
    if (t > B) return false;
    else return true;
}
void exec() {
    cin >> N >> B;
    mp.clear();
    tot = 0;
    string t, t1;
    ll maxb = 1, b;
    for (int i = 0, a; i < N; i++) {
        cin >> t >> t1 >> a >> b;
        maxb = max(maxb, b);
        if (!mp.count(t)) mp[t] = tot++;
        comp[mp[t]].push_back({b, a});
    }
    int L = 1, R = maxb;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    cout << R << "\n";
    for (int i = 0; i < tot; i++) {
        comp[i].clear();
    }
}

int main() {
    int T; cin >> T;
    while(T--){
        exec();
    }
}
