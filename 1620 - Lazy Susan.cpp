#include <bits/stdc++.h>
using namespace std;
int a[1010], N;
int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        int cnt = 0;
        bool OK = false;
        for (int i = 0; i < N; i++) {
            scanf("%d", &a[i]);
            a[i + N] = a[i];
        }
        for (int s = 0; s < N; s++) {
            cnt = 0;
            for (int i = s; i < s + N; i++) {
                for (int j = i - 1; j >= s; j--) {
                    if (a[j] > a[i])
                    cnt++;
                }
            }
            if (cnt - 1 & 1) {
                printf("possible\n");
                OK = true;
                break;
            }
        }
        if (!OK)
            printf("impossible\n");
    }
}
