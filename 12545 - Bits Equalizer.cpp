#include <bits/stdc++.h>
using namespace std;
char a[110], b[110];
int exec() {
    int N = strlen(a);
    int qt= 0, qf = 0, tf = 0, ft = 0;
    int a1 = 0, b1 = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] == '1') a1++;
        if (b[i] == '1') b1++;
        if (a[i] == '?') {
            if (b[i] == '0') qf++;
            if (b[i] == '1') qt++;
        } else if (a[i] == '1') {
            if (b[i] == '0') tf++;
        } else if (a[i] == '0') {
            if (b[i] == '1') ft++;
        }
    }
    if (a1 > b1) return -1;
    int ans = 0;
    ans += qf + qt + max(tf, ft);
    return ans;
}
int main() {
    int T, c = 0; scanf("%d", &T);
    while (T--) {
        scanf("%s", a);
        scanf("%s", b);
        printf("Case %d: %d\n", ++c, exec());
    }
}
