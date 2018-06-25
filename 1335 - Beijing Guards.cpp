#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long
using namespace std;
int N;
int req[MAXN];
int l[MAXN], r[MAXN];
bool check(int lim) {
    l[0] = req[0], r[0] = 0;
    for (int i = 1; i < N; i++) {
        if (i & 1) {
            l[i] = min(req[i], req[0] - l[i - 1]);
            r[i] = req[i] - l[i];
        } else {
            r[i] = min(req[i], lim - req[0] - r[i - 1]);
            l[i] = req[i] - r[i];
        }

    }
    return l[N - 1] == 0;
}
void exec() {
    int mxs = 0;
    for (int i = 0; i < N; i++) {
        cin >> req[i];
        if (i) mxs = max(mxs, req[i] + req[i - 1]);
    }
    mxs = max(mxs, req[N - 1] + req[0]);
    if (N & 1) {
        if (N == 1) {
            cout << req[0] << "\n";
            return;
        }
        int L = mxs, R = mxs * 3;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (check(mid)) {
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        cout << L << "\n";
    } else {
        cout << mxs << "\n";
    }
}

int main() {
    while (cin >> N && N) {
        exec();        
    }
}
