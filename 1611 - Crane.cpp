#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;

int T, N;
int A[MAXN];
vector <pair <int, int> > ans;
void change(int L, int R) {
    for (int i = L, j = L + (R - L + 1) / 2;
        j <= R; j++, i++) {
        swap(A[i], A[j]);
    }
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        ans.clear();
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            A[i]--;
        }
        for (int i = 0; i < N; i++) {
            if (A[i] == i) continue;
            int pos = i + 1;
            for (int j = i + 1; j < N; j++) {
                if (A[j] == i) {
                    pos = j;
                    break;
                }
            }
            if (i + (pos - i) * 2 - 1 < N) {
                ans.push_back({i, i + 2 * (pos - i) - 1});
                change(i, i + 2 * (pos - i) - 1);
            } else {
                if ((pos - i) % 2) {
                    ans.push_back(make_pair(i, pos));
                    change(i, pos);
                } else {
                    ans.push_back(make_pair(i + 1, pos));
                    change(i + 1, pos);
                }
                i--;
            }
        }
        printf("%d\n", (int)ans.size());
        for (int i = 0; i < ans.size(); i++) {
            printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
        }
    }
}
