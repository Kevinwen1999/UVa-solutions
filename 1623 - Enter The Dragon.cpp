#include <bits/stdc++.h>
using namespace std;
int n, m;
int last[1000010];
int zpos[1000010];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(last, -1, sizeof last);
        memset(zpos, 0, sizeof zpos);
        set<int> s;
        vector <int> input;
        set <pair <int, int> > pq;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            s.insert(i);
        }
        bool ok = true;
        int ztot = 0;
        for (int i = 0, a; i < m; i++) {
            scanf("%d", &a);
            input.push_back(a);
        }
        int zcnt = 0;
        pair <int, int> nz;
        for (int i = 0, a; i < m; i++) {
            a = input[i];
            if (!a) {
                pq.insert({i, ztot++});
                zcnt++;
            } else {
                if (!s.count(a))  {
                    s.insert(a);
                    last[a] = i;
                } else {
                    if (!zcnt) {
                        ok = false; break;
                    }
                    auto it = pq.lower_bound({last[a], 0});
                    if (it == pq.end()) {
                        ok = false; break;
                    }
                    last[a] = i;
                    zcnt--;
                    zpos[it->second] = a;
                    pq.erase(it);
                    s.insert(a);
                }
            }

        }
        if (!ok) printf("NO\n");
        else {
            printf("YES\n");
            for (int i = 0; i < ztot; i++) {
                if (i) printf(" ");
                printf("%d", zpos[i]);
            }
            printf("\n");
        }
    }
}
