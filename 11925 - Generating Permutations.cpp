#include <bits/stdc++.h>
#define MAXN 310
using namespace std;
int N;
vector <int> A, ans;
bool sorted() {
    for (int i = 0; i < N; i++) {
        if (A[i] != i + 1) return false;
    }
    return true;
}
int main() {
    while (scanf("%d", &N) == 1 && N) {
        A.clear();
        ans.clear();
        for (int i = 0, a; i < N; i++) {
            scanf("%d", &a);
            A.push_back(a);
        }
        while (!sorted()) {
            if (A[0] < A[1] || (A[0] == N && A[1] == 1)) {
                A.insert(A.begin(), A[N - 1]);
                A.pop_back();
                ans.push_back(2);
            }
            else {
                swap(A[0], A[1]);
                ans.push_back(1);
            }
        }
        for (int i = ans.size() - 1; i >= 0; i--) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
}
