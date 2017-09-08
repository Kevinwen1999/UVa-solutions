#include <bits/stdc++.h>
#define MAXM 100010
#define ll long long
using namespace std;
ll N;
ll bit1[MAXM], bit2[MAXM];
ll A[MAXM];
ll lmt[MAXM], rmt[MAXM];
void update(ll x, int v, ll bit[]) {
    for (;x <= MAXM; x += (x & -x))
        bit[x] += v;
}
ll query(ll a, ll bit[]) {
    ll sum = 0;
    for (; a > 0; a-=(a & -a))
        sum += bit[a];
    return sum;
}
void exec() {
    scanf("%lld", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }
    memset(bit1, 0, sizeof bit1);
    memset(bit2, 0, sizeof bit2);
    for (int i = 1; i <= N; i++) {
        lmt[i] = query(A[i] - 1, bit1);
        update(A[i], 1LL, bit1);
    }
    for (int i = N; i >= 1; i--) {
        rmt[i] = query(A[i] - 1, bit2);
        update(A[i], 1LL, bit2);
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += (ll)lmt[i] * (N - i - rmt[i]) + (ll)rmt[i] * (i - lmt[i] - 1);
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        exec();
    }
}
