#include<cstdio>
#include<vector>

using namespace std;

int T, N, a, b;
vector<int> graph, sum;
vector<bool> vis;

int dfs(int u) {
    vis[u] = true;
    int tot = 0;
    if(graph[u] != -1 && !vis[graph[u]])
        tot += 1 + dfs(graph[u]);
    vis[u] = false;
    return sum[u] = tot;
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d", &N);
        graph.assign(N, -1);
        sum.assign(N, -1);
        vis.assign(N, false);
        for(int i = 0; i < N; i++) {
            scanf("%d %d", &a, &b);
            graph[a - 1] = b - 1;
        }
        int ans = 0, best_len = 0;
        for(int i = 0; i < N; i++) {
            if(sum[i] == -1) dfs(i);
            if(sum[i] > best_len) {
                best_len = sum[i];
                ans = i;
            }
        }
        printf("Case %d: %d\n", t, ans + 1);
    }
}
