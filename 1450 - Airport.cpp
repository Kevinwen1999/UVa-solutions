#include <bits/stdc++.h>
#define pii pair <int, int>
using namespace std;

int T, N;
vector <pii> vp;

bool check(int mid) {
    int l = 0, r = 0, turn = 0;
    for (int i = 0; i < N; i++) {
        l += vp[i].first, r += vp[i].second;
        int ln = max(0, l - mid);
        int rn = max(0, r - mid);
        if (ln + rn > turn) return false;
        if (!l && r) r--;
        else if (!r && l) l--;
        else if (l + r > turn) turn++;
    }
    return true;
}

void exec() {
    vp.clear();
    cin >> N;
    for (int i = 0, a, b; i < N; i++ ) {
        cin >> a >> b;
        vp.push_back({a, b});
    }
    int l = 1, r = 100000;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l - 1 << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        exec();
    }
}
