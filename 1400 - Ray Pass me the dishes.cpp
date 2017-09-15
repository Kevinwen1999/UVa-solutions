#include <iostream>
#include <algorithm>
#include <utility>
#define ll long long
#define MAXN 500010
#define INF 0x3f3f3f3f
#define pii pair <int, int>
using namespace std;

int N, M;
ll A[MAXN];
ll PA[MAXN];

inline int l(int a) {return a << 1;}
inline int r(int a) {return a << 1 | 1;}
inline int mid(int a) {return a >> 1;}
inline ll qsum(int a, int b) {return PA[b] - PA[a - 1];}
struct node {
    int lx, rx;
    ll val;
    node(int a = 0, int b = 0, ll c = 0) {
        init(a, b, c);
    }
    void init(int a, int b, ll c) {
        lx = a;
        rx = b;
        val = c;
    }
    node operator + (const node& a) const {
        return node(min(lx, a.lx), max(rx, a.rx), val + a.val);
    }
    bool operator < (const node& a) const {
        if (val == a.val) {
            if (lx == a.lx) {
                return rx > a.rx;
            }
            return lx > a.lx;
        }
        return val < a.val;
    }
};
struct segmnt {
    int lidx, ridx;
    node premax;
    node sufmax;
    node submax;
} seg[MAXN * 6];
void evalans(segmnt& s, segmnt& s1, segmnt& s2) {
    s.premax = max(s1.premax, node(s1.lidx, s1.ridx, qsum(s1.lidx, s1.ridx)) + s2.premax);
    s.sufmax = max(s2.sufmax, node(s2.lidx, s2.ridx, qsum(s2.lidx, s2.ridx)) + s1.sufmax);
    s.submax = max(s1.sufmax + s2.premax, max(s1.submax, s2.submax));
    s.lidx = s1.lidx, s.ridx = s2.ridx;
}
void build_tree(int stidx, int L, int R) {
    segmnt& s = seg[stidx];
    if (L == R) {
        s.lidx = s.ridx = L;
        s.submax = node(L, R, A[L]);
        s.sufmax = node(L, R, A[L]);
        s.premax = node(L, R, A[L]);
        return;
    }
    build_tree(l(stidx), L, mid(L + R));
    build_tree(r(stidx), mid(L + R) + 1, R);
    segmnt& s1 = seg[l(stidx)], s2 = seg[r(stidx)];
    evalans(s, s1, s2);
}
segmnt query(int stidx, int L, int R, int QL, int QR) {
    if (L >= QL && R <= QR) return seg[stidx];
    int m = mid(L + R);
    segmnt ans;
    if (QL <= m && QR > m) {
        segmnt s1 = query(l(stidx), L, m, QL, QR);
        segmnt s2 = query(r(stidx), m + 1, R, QL, QR);
        evalans(ans, s1, s2);
        return ans;
    } else if (QL >= m + 1) {
        return query(r(stidx), m + 1, R, QL, QR);
    } else {
        return query(l(stidx), L, m, QL, QR);
    }
}
int main() {
    int ks = 0;
    while (cin >> N >> M) {
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
            PA[i] = A[i] + PA[i - 1];
        }
        build_tree(1, 1, N);
        cout << "Case " << ++ks <<":\n";
        for (int i = 0, a, b; i < M; i++) {
            cin >> a >> b;
            segmnt ans = query(1, 1, N, a, b);
            cout << ans.submax.lx << " " << ans.submax.rx << "\n";
        }
    }
}
