#include <bits/stdc++.h>
#define MAXN 800010
using namespace std;
int N;
struct node {
    int amount;
    int date;
} v[MAXN];
bool cmp(node &a, node &b) {
    if (a.date == b.date) {
        return a.amount < b.amount;
    }
    return a.date < b.date;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0, a, b; i < N; i++) {
            scanf("%d %d", &v[i].amount, &v[i].date);
        }
        sort(v, v + N, cmp);
        int ctime = 0;
        priority_queue <int> pq;
        for (int i = 0; i < N; i++) {
            ctime += v[i].amount;
            pq.push(v[i].amount);
            if (ctime > v[i].date) {
                ctime -= pq.top();
                pq.pop();
            }
        }
        printf("%d\n", pq.size());
        if (T) printf("\n");
    }
}
