#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;
int N, M, K;
int a[MAXN];
int ms[MAXN];
int main() {
    int T; scanf("%d", &T);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    for (int cs = 1; cs <= T; cs++) {
        scanf("%d %d %d", &N, &M, &K);
        int ans = N;
        memset(ms, 0, sizeof ms);
        for (int i = 3; i < N; i++) {
            a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % M + 1;
        }
        set <int> req;
        for (int i = 1; i <= K; i++)
            req.insert(i);
        int st = 0, ed = 0;
        while(ed < N && !req.empty()) {
            if (req.count(a[ed])) req.erase(a[ed]);
            ms[a[ed]]++;
            ed++;
        }
        if (!req.empty()) {
            printf("Case %d: sequence nai\n", cs);
            continue;
        }
        ans = ed;
        while (st < N) {
            ms[a[st]]--;
            if (a[st] <= K && !ms[a[st]]) {
                while (!ms[a[st]] && ed < N) {
                    ms[a[ed]]++;
                    ed++;
                }
                if (!ms[a[st]]) break;
            }
            st++;
            ans = min(ans, ed - st);
        }
        printf("Case %d: %d\n", cs, ans);
    }
}
