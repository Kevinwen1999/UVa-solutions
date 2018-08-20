#include <bits/stdc++.h>
using namespace std;

int N;

struct node {
    int l, r, t;
    bool operator < (const node& a) const {
        if (r == a.r) return l < a.l;
        return r < a.r;
    }
};

int main() {
    while (cin >> N && N) {
        set <node> S;
        bool blyat = false;
        for (int i = 0; i < N; i++) {
            int a, b; cin >> a >> b;
            int c = (b - a)/ 2 + 1;
            S.insert((node){a, b - c, c});
        }
        int last = 0;
        while (!S.empty()) {
            auto c = S.begin();
            last = max(last, c->l);
            if (last > c->r) {
                cout << "NO\n";
                blyat = true;
                break;
            } else {
                last = last + c->t;
            }
            S.erase(c);
        }
        if (!blyat) cout << "YES\n";
    }
}


