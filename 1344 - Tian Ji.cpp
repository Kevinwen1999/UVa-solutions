#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    while (cin >> N && N) {
        vector <int> A, B;
        for (int i = 0, a; i < N * 2; i++) {
            cin >> a;
            if (i < N)
                A.push_back(a);
            else
                B.push_back(a);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int sa, sb, ea, eb;
        sa = sb = 0, ea = eb = N - 1;
        int tot = 0;
        while (sa <= ea) {
            if (A[ea] > B[eb]) 
                tot++, ea--, eb--;
            else if (A[sa] > B[sb])
                tot++, sa++, sb++;
            else {
                if (A[sa] < B[eb])
                    tot--;
                sa++, eb--;
            }
        }
        cout << tot * 200 << "\n";
    }
}
