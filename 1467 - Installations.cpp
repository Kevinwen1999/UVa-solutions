#include <bits/stdc++.h>
#define pii pair <int, int>
using namespace std;

int N;
vector <pii> vp;

int calc(vector <pii> &A, int& mid, int& smid) {
    mid = smid = -1;
    int ct = 0;
    int mx = 0, smx = 0;
    for (int i = 0; i < N; i++) {
        ct += A[i].second;
        int diff = max(0, ct - A[i].first);
        if (diff > mx) {
            smx = mx;
            smid = mid;
            mx = diff;
            mid = i;
        } else if (diff > smx) {
            smx = diff;
            smid = i;
        }
    }
    return mx + smx;
}
void print() {
    for (auto i : vp) {
        cout << i.first << " " << i.second << " | ";
    }
    cout << "\n";
}
void exec() {
    vp.clear();
    scanf("%d", &N);
    for (int i = 0, a, b; i < N; i++) {
        scanf("%d %d", &a, &b);
        vp.push_back({b, a});
    }
    sort(vp.begin(), vp.end());
    int mi, smi;
    int best = calc(vp, mi, smi);
    int maxpos = max(mi, smi);
    for (int i = maxpos - 1, a, b; i >= 0; i--) {
        auto j = vp[i];
        vp.erase(vp.begin() + i);
        vp.insert(vp.begin() + maxpos, j);
        best = min(best, calc(vp, a, b));
        vp.erase(vp.begin() + maxpos);
        vp.insert(vp.begin() + i, j);
    }
    printf("%d\n", best);
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        exec();
    }
}
