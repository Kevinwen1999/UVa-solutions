#include <bits/stdc++.h>
using namespace std;

map <int, int> M;

int main() {
    int N, D;
    while (cin >> N >> D) {
        if (!(N || D)) break;
        M.clear();
        int tot = 0;
        for (int i = 0; i < N; i++) {
            int a; cin >> a;
            tot += a;
            M[a]++;
        }
        for (int i = 0; i < D; i++) {
            int a; cin >> a;
            M[a]--;
            if (M[a] >= 0) continue;
            else tot += a;
        }
        cout << tot << "\n";
    }
}
