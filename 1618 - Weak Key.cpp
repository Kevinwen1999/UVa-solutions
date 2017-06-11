#include <bits/stdc++.h>
#define MAXN 5010
using namespace std;
int N;
int a[MAXN];
set <int> s1, s2;
bool isf;
void exec() {
    int i = 0;
    int j;
    while (i + 3 < N && !isf) {
        s1.clear(); s2.clear();
        s1.insert(a[i+1]);
        j = i + 2;
        for (int k = j; k < N; k++)
            s2.insert(a[k]);
        while (j + 1 < N && !isf) {
            bool OK = true;
            if (a[j] <= a[i]) OK = false;
            int sm = *s1.begin();
            if (sm >= a[i]) OK = false;
            auto it = s2.upper_bound(sm);
            if (it == s2.end() || (*it) >= a[i]) OK = false;
            if (OK) {
                printf("YES\n");
                isf = true;
            }
            s1.insert(a[j]); s2.erase(a[j]);
            j++;
        }
        i++;
    }
}
int main() {
    int T; scanf("%d", &T);
    while(T--) {
        isf = false;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }
        exec();
        if (isf) continue;
        reverse(a, a + N);
        exec();
        if (!isf) {
            printf("NO\n");
        }
    }
}
