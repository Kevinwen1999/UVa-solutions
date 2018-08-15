#include <bits/stdc++.h>
#define MAXN 110
#define INF 0x3f3f3f3f
using namespace std;

// KM Algorithm, max weighted bipartite matching, answer is the sum of all labels
int N;
int W[MAXN][MAXN]; // adj matrix
int lx[MAXN], ly[MAXN]; // labels of nodes in set X and Y
int matchto[MAXN]; // indicates which node in X is matched to the node in Y
int slack[MAXN]; // keep track of slack(y) = min(l(x) + l(y) - w(x, y)) for all x in S
bool S[MAXN], T[MAXN]; // Nodes that are in Hungarian Tree (S for X and T for Y)

bool match(int root) {
    S[root] = true;
    for (int i = 0; i < N; i++) {
        if (T[i]) continue;
        if (lx[root] + ly[i] != W[root][i]) {
            slack[i] = min(slack[i], lx[root] + ly[i] - W[root][i]);
            continue;
        }
        T[i] = true;
        if (matchto[i] == -1 || match(matchto[i])) {
            matchto[i] = root;
            return true;
        }
    }
    return false;
}

void update() { 
    int a = INF;
    for (int i = 0; i < N; i++) {
        if (!T[i])
            a = min(a, slack[i]);
    }
    for (int i = 0; i < N; i++) {
        if (S[i]) lx[i] -= a;
        if (T[i]) ly[i] += a;
        else slack[i] -= a; // since all x in S is deducted by a
    }
}

void KM() {
    for (int i = 0; i < N; i++) {
        lx[i] = ly[i] = 0;
        matchto[i] = -1;
        for (int j = 0; j < N; j++) {
            lx[i] = max(lx[i], W[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) slack[j] = INF;
        while (true) {
            for (int j = 0; j < N; j++) 
                S[j] = T[j] = 0;
            if (match(i)) break;
            else update();
        }
    }
}

int D, R;
int main() {
    while (cin >> N >> D >> R) {
       if (!(N || D || R)) break;
       vector <int> A, B;
       for (int i = 0; i < N * 2; i++) {
           int a; cin >> a;
           if (i < N) A.push_back(a);
           else B.push_back(a);
       }
       for (int i = 0; i < N; i++) {
           for (int j = 0; j < N; j++) {
               W[i][j] = -(max(0, A[i] + B[j] - D));
           }
       }
       KM();
       int ans = 0;
       for (int i = 0; i < N; i++) {
           ans += lx[i] + ly[i];
       }
       cout << -ans * R << "\n";
    }
}
