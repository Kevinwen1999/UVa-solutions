// Judge for the problem was broken at the time
#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

int W, N, S;
double V;
vector <int> skis;
vector <pair <int, int> > gates;

bool check(int idx) {
    double spd = skis[idx];
    double cl = gates[0].first;
    double cr = cl + W;
    for (int i = 1; i < N; i++) {
        double t = (gates[i].second - gates[i - 1].second) / spd;
        double rl = gates[i].first, rr = gates[i].first + W;
        double nl = cl - t * V, nr = cr + t * V;
        cl = max(nl, rl), cr = min(nr, rr);
        if (cl > cr + EPS) return false;
    }
    return true;
}

void exec() {
    cin >> W >> V >> N;
    gates.clear(); skis.clear();
    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        gates.push_back({a, b});
    }
    cin >> S;
    for (int i = 0, a; i < S; i++) {
       cin >> a;
       skis.push_back(a);
    }
    sort(skis.begin(), skis.end());
    int L = 0, R = S - 1;
    while(L <= R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    if (R < 0) cout << "IMPOSSIBLE\n";
    else cout << skis[R] << "\n";
}

int main() {
    int T; cin >> T;
    while(T--) {
        exec();
    }
}
