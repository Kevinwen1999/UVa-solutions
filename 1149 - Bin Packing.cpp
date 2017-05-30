#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int N, L;
int all[MAXN];
int main () {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &N, &L);
        for (int i = 0; i < N; i++) {
            scanf("%d", &all[i]);
        }
        sort(all, all+N);
        int l = 0, r = N-1, ans = 0;
        while(l <= r) {
            if (all[l] + all[r] <= L) {
                l++;
            }
            r--; ans++;
        }
        printf("%d\n", ans);
        if (T) printf("\n");
    }
}
