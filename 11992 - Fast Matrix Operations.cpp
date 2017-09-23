#include <iostream>
#include <climits>
#include <cstdio>
#include <algorithm>

#define INF 0x3f3f3f3f
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll int
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-9

#define MAXN 100010
#define SEGN 300030
using namespace std;

int R, C, M;

struct node {;
    ll addv;
    ll setv;
    ll sum;
    ll minn;
    ll maxx;
};
node seg[22][SEGN];
void push_down(int nm, int o, int L, int R) {
    int lc = o * 2, rc = o * 2 + 1;
    if (seg[nm][o].setv != -1) {
        seg[nm][lc].setv = seg[nm][rc].setv = seg[nm][o].setv;
        seg[nm][lc].addv = seg[nm][rc].addv = 0;
        seg[nm][lc].maxx = seg[nm][lc].minn = seg[nm][o].setv;
        seg[nm][rc].maxx = seg[nm][rc].minn = seg[nm][o].setv;
        int mid = (L + R) / 2;
        seg[nm][lc].sum = (mid - L + 1) * seg[nm][o].setv;
        seg[nm][rc].sum = (R - mid) * seg[nm][o].setv;
        seg[nm][o].setv = -1;
    }
    if (seg[nm][o].addv > 0) {
        seg[nm][lc].addv += seg[nm][o].addv;
        seg[nm][rc].addv += seg[nm][o].addv;
        seg[nm][lc].maxx += seg[nm][o].addv;
        seg[nm][lc].minn += seg[nm][o].addv;
        seg[nm][rc].maxx += seg[nm][o].addv;
        seg[nm][rc].minn += seg[nm][o].addv;
        int mid = (L + R) / 2;
        seg[nm][lc].sum += (mid - L + 1) * seg[nm][o].addv;
        seg[nm][rc].sum += (R - mid) * seg[nm][o].addv;
        seg[nm][o].addv = 0;
    }
}

void push_up(int nm, int o) {
    int lc = o * 2, rc = o * 2 + 1;
    seg[nm][o].sum = seg[nm][lc].sum + seg[nm][rc].sum;
    seg[nm][o].maxx = max(seg[nm][lc].maxx, seg[nm][rc].maxx);
    seg[nm][o].minn = min(seg[nm][lc].minn, seg[nm][rc].minn);
}
ll Val;
void set_update(int nm, int o, int L, int R, int QL, int QR) {
    if (L >= QL && R <= QR) {
        seg[nm][o].setv = Val;
        seg[nm][o].addv = 0;
        seg[nm][o].maxx = seg[nm][o].minn = Val;
        seg[nm][o].sum = (R - L + 1) * Val;
        return;
    }
    push_down(nm, o, L, R);
    int m = (L + R) / 2;
    int lc = o * 2, rc = o * 2 + 1;
    if (QL <= m)
        set_update(nm, lc, L, m, QL, QR);
    if (QR > m)
        set_update(nm, rc, m + 1, R, QL, QR);
    push_up(nm, o);
}
void add_update(int nm, int o, int L, int R, int QL, int QR) {
    if (L >= QL && R <= QR) {
        seg[nm][o].addv += Val;
        seg[nm][o].maxx += Val;
        seg[nm][o].minn += Val;
        seg[nm][o].sum += (R - L + 1) * Val;
        return;
    }
    push_down(nm, o, L, R);
    int m = (L + R) / 2;
    int lc = o * 2, rc = o * 2 + 1;
    if (QL <= m)
        add_update(nm, lc, L, m, QL, QR);
    if (QR > m)
        add_update(nm, rc, m + 1, R, QL, QR);
    push_up(nm, o);
}
ll amin, amax, asum;
void query(int nm, int o, int L, int R, int QL, int QR) {
    if (L >= QL && R <= QR) {
        asum += seg[nm][o].sum;
        amin = min(amin, seg[nm][o].minn);
        amax = max(amax, seg[nm][o].maxx);
        return;
    }
    push_down(nm, o, L, R);
    int m = (L + R) / 2;
    int lc = o * 2, rc = o * 2 + 1;
    if (QL <= m)
        query(nm, lc, L, m, QL, QR);
    if (QR > m)
        query(nm, rc, m + 1, R, QL, QR);
}
void exec() {
    for (int j = 0; j < R; j++)
        for (int i = 0; i < SEGN; i++) {
            seg[j][i].addv = 0;
            seg[j][i].setv = -1;
            seg[j][i].sum = 0;
            seg[j][i].minn = 0;
            seg[j][i].maxx = 0;
        }
    for (int i = 0, op, x1, y1, x2, y2; i < M; i++) {
        cin >> op >> x1 >> y1 >> x2 >> y2;
        x1--, x2--, y1--, y2--;
        if (op != 3) cin >> Val;
        if (op == 1) {
            for (int j = x1; j <= x2; j++) {
                add_update(j, 1, 0, C - 1, y1, y2);
            }
        } else if (op == 2) {
            for (int j = x1; j <= x2; j++) {
                set_update(j, 1, 0, C - 1, y1, y2);
            }
        } else {
            asum = 0, amin = INF, amax = -1;
            for (int j = x1; j <= x2; j++) {
                query(j, 1, 0, C - 1, y1, y2);
            }
            printf("%d %d %d\n", asum, amin, amax);
        }
    }
}

int main() {
    while (cin >> R >> C >> M) {
        exec();
    }
}
