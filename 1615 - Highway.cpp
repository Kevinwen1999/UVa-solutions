#include <bits/stdc++.h>
using namespace std;
double L, D;
int N;
struct node {
    int l, r;
};
bool cmp (node &a, node &b) {
    if (a.l == b.l)
        return a.r > b.r;
    return a.l < b.l;
}
vector <node> v;
int main() {
    while (scanf("%lf %lf", &L, &D) == 2) {
        scanf("%d", &N);
        v.clear();
        double x, y, c;
        for (int i = 0; i < N; i++) {
            scanf("%lf %lf", &x, &y);
            c = sqrt(D * D - y * y);
            v.push_back((node){max(0.0, x - c), min(L, x + c)});
        }
        sort(v.begin(), v.end(), cmp);
        double lastT = -1;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (v[i].l > lastT) {
                cnt++;
                lastT = v[i].r;
            }
        }
        printf("%d\n", cnt);
    }
}
