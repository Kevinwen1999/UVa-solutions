#include <bits/stdc++.h>
#define MAXN 301
using namespace std;
int N, K;
int adj[MAXN][MAXN];
bool judge() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool same = false;
            for (int k = 0; k < N && !same; k++) {
                if (adj[i][k] && adj[j][k])
                    same = true;
            }
            if (!same) continue;
            for (int k = 0; k < N; k++) {
                if (adj[i][k] || adj[j][k]) {
                    if (adj[i][k] != adj[j][k]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++) {
        memset(adj, 0, sizeof adj);
        scanf("%d %d", &N, &K);
        for (int i = 0, a, b; i < K; i++) {
            scanf("%d %d", &a, &b);
            adj[a][b] = 1;
        }
        printf("Case #%d: ", cs);
        if (judge())
            printf("Yes\n");
        else
            printf("No\n");
    }
}
