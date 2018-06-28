#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;

int N, k;
map <int, int> mp;
vector <int> v[MAXN], all;

bool check(int lim) {
    for (int i = 0; i < k; i++)
        v[i].clear();
    for (int i : all) {
        int mnsz = N + 1, idx = -1;
        for (int j = 0; j < k; j++) {
            if (v[j].size() < mnsz && v[j].size() < lim && (v[j].empty() || v[j][v[j].size() - 1] != i)) {
                mnsz = min(mnsz, (int)v[j].size());
                idx = j;
            }
        }
        if (idx == -1) return false;
        v[idx].push_back(i);
    }
    return true;
}

void exec() {
    mp.clear();
    all.clear();
    k = 0;
    for (int i = 0, a; i < N; i++) {
        cin >> a;
        mp[a] ++;
        k = max(k, mp[a]);
        all.push_back(a);
    }
    sort(all.begin(), all.end());
    int L = 1, R = N;
    while(L <= R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    cout << k << "\n";
    check(L);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (j) cout << " ";
            cout << v[i][j];
        }
        cout << "\n";
    }
}

int main() {
    while (cin >> N) {
        if (N) exec();
        if (N) cout << "\n";
        if (!N) break;
    }
}
