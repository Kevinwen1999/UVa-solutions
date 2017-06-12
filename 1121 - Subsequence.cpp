#include <bits/stdc++.h>
#define MAXN 100010
#define INF 0x3f3f3f3f
using namespace std;
int N, S;
int a[MAXN];
int main() {
//    freopen("output.txt", "w", stdout);
    while (scanf("%d %d", &N, &S) == 2) {
        for (int i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }
        int st = 0, sum = 0, ed = 0, minl = INF;
        while(st < N) {
            if (ed < st) ed = st;
            while(sum < S && ed < N) {
                sum += a[ed++];
            }
            if (sum >= S)
                minl = min(minl, ed - st);
            sum -= a[st++];
        }
        printf("%d\n", minl == INF ? 0 : minl);
    }
}
