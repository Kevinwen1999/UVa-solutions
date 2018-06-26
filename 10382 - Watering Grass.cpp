#include <bits/stdc++.h>
using namespace std;
int N;
double L, W;
struct node {
    double c, r;
    node(double a, double b) : c(a), r(b) {
        r = sqrt(r * r - W * W / 4.0);
    }
    bool operator < (node &a) const {
        return c - r < a.c - a.r;
    }
};

void exec() {
    vector <node> v;
    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        if (b * 2 >= W) {
            v.push_back((node){a, b});
            continue;
        }
    }
    N = v.size();
    sort(v.begin(), v.end());
    double clim = 0;
    int cid = 0;
    int tot = 0;
    while (cid < N) {
        double nlim = clim;
        while (cid < N && v[cid].c - v[cid].r <= clim) {
            nlim = max(nlim, v[cid].r + v[cid].c);
            cid++;
        }
        if (nlim == clim) {
            cout << -1 << "\n"; return;
        }
        clim = nlim;
        tot++;
        if (clim >= L) {
            cout << tot << "\n"; return;
        }
    }
    cout << -1 << "\n"; return;
}

int main() {
    while (cin >> N >> L >> W) {
        exec();
    }
}
