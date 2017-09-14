#include <bits/stdc++.h>
#define MAXN 100010
#define MAX_N 100010
#define LOG_TWO_N 20	// 2^10 > 1000, adjust this value as needed

using namespace std;
int N, Q, cnt;
int A[MAXN];
int Ap[MAXN];
map <int, int> all, st, ed, hsh;

int SpT[MAX_N][LOG_TWO_N];
void RMQ(int n)
{
    // constructor as well as pre-processing routine
    for (int i = 0; i < n; i++)
    {
        SpT[i][0] = i; // RMQ of sub array starting at index i + length 2^0=1
    }

    // the two nested loops below have overall time complexity = O(n log n)
    for (int j = 1; (1<<j) <= n; j++)	// for each j s.t. 2^j <= n, O(log n)
        for (int i = 0; i + (1<<j) - 1 < n; i++)
        // for each valid i, O(n)
        if (Ap[SpT[i][j-1]] > Ap[SpT[i+(1<<(j-1))][j-1]])
        SpT[i][j] = SpT[i][j-1];	// start at index i of length 2^(j-1)
        else
        SpT[i][j] = SpT[i+(1<<(j-1))][j-1]; // start at index i+2^(j-1) of length 2^(j-1)
}
int query(int i, int j) {
    // this query is O(1)
    int k = (int)floor(log((double)j-i+1) / log(2.0));	// 2^k <= (j-i+1)
    if (Ap[SpT[i][k]] > Ap[SpT[j-(1<<k)+1][k]])
        return SpT[i][k];
    else
        return SpT[j-(1<<k)+1][k];
}

int main() {
    while(cin >> N && N) {
        cin >> Q;
        all.clear();
        st.clear();
        ed.clear();
        hsh.clear();
        memset(SpT, 0, sizeof SpT);
        cnt = 0;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            all[A[i]]++;
            if (!st.count(A[i])) st[A[i]] = i;
            ed[A[i]] = i;
        }
        for (auto i : all) {
            hsh[i.first] = cnt;
            Ap[cnt++] = i.second;
        }
        RMQ(cnt);
        for (int i = 0, a, b; i < Q; i++) {
            cin >> a >> b; a--, b--;
            int lg = hsh[A[a]], rg = hsh[A[b]];
            if (lg == rg) {
                cout << b - a + 1 << "\n";
                continue;
            }
            int tot = ed[A[a]] - a + 1;
            tot = max(tot, b - st[A[b]] + 1);
            if (lg + 1 <= rg - 1)
                tot = max(tot, Ap[query(lg + 1, rg - 1)]);
            cout << tot << "\n";
        }

    }
}
