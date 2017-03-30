#include <bits/stdc++.h>
#define MAXN 70
#define ULL unsigned long long
using namespace std;
int N;
int ori[MAXN], fin[MAXN];

unsigned long long calc(int* A, int i, int target) {
    if (i==0) return 0; // no element
    if (A[i] == target) return calc(A, i-1, target); // in order, continue
    return calc(A, i-1, 6-A[i]-target) + (1LL<<(i-1)); // move everything on the third pole and move the current one.
}

int main() {
    int kase = 0;
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 1; i <= N; i++) {
            scanf("%d", &ori[i]);
        }
        for (int i = 1; i <= N; i++) {
            scanf("%d", &fin[i]);
        }
        bool solved = false;
        for (int i = N; i >= 1 && !solved; i--) {
            if (ori[i] == fin[i]) continue;
            else {
                solved  = true;
                ULL ans = calc(ori, i-1, 6-ori[i]-fin[i]) + calc(fin, i-1, 6-ori[i]-fin[i]) + 1;
                printf("Case %d: %llu\n", ++kase, ans);
            }
        }
        if (!solved)
            printf("Case %d: 0\n", ++kase);
    }
}
