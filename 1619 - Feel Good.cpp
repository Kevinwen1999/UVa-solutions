#include <bits/stdc++.h>
#define MAXN 100010
#define INF 1
using namespace std;
int N;
int a[MAXN], l[MAXN], r[MAXN], al, ar;
long long ans, ta, pre[MAXN];
void exec() {
    ans = -INF;
    memset(l, -1, sizeof l);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
        pre[i] = a[i] + pre[i - 1];
    }
    vector <pair <int, int> > v;
    for (int i = 1; i <= N; i++) {
        l[i] = i - 1;
        while(v.size() > 0 && v.back().first >= a[i]) {
            r[v.back().second] = i - 1;
            l[i] = l[v.back().second];
            v.pop_back();
        }
        v.push_back({a[i], i});
    }
//    cout<<v.size()<<"\n";
//    for (int i = 1; i <= N; i++)
//        cout<<l[i]<<" "<<r[i]<<"\n";
    for (int i = 0; i < v.size(); i++) {
//        cout<<v[i].first<<" "<<v[i].second<<"\n";
        r[v[i].second] = N;
    }
    for (int i = 1; i <= N; i++) {
        if (l[i] == -1) continue;
        if (a[i] == 0) {
            l[i] = i - 1, r[i] = i;
        }
        ta = 1LL * a[i] * (pre[r[i]] - pre[l[i]]);
//        cout<<i<<": "<<l[i] + 1<<" "<<r[i]<<" "<<ta<<"\n";
        if (ta > ans || (ta == ans && (r[i] - l[i]) < (ar - al))) {
            ans = ta; al = l[i], ar = r[i];
        }
    }
}
int main() {
//    freopen("output.txt", "w", stdout);
    bool shit = false;
    while(scanf("%d", &N) == 1) {
        exec();
        if (shit) printf("\n");
        else shit = true;
        printf("%lld\n%d %d\n", ans, al + 1, ar);
    }
}
