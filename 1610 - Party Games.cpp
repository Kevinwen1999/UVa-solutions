#include <bits/stdc++.h>
using namespace std;
int N;
string in;
vector <string> v;
char ans[100];
void exec(string &a, string &b) {
    int n = a.size(), m = b.size();
    int sz = 0;
    if (n < m) {
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                ans[sz++] = a[i];
                break;
            } else if (a[i] != b[i]) {
                ans[sz++] = a[i] + 1;
                break;

            } else if (a[i] == b[i]) {
                ans[sz++] = a[i];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                ans[sz++] = a[i];
            } else {
                if (i == m - 1) {
                    if (i == n - 1) {
                        ans[sz++] = a[i];
                        break;
                    }
                    if (a[i] + 1 != b[i]) {
                        ans[sz++] = a[i] + 1;
                        break;
                    }
                    ans[sz++] = a[i];
                    for (int j = i + 1; j < n; j++) {
                        if (j == n - 1) {
                            ans[sz++] = a[j];
                        } else if (a[j] != 'Z') {
                            ans[sz++] = a[j] + 1;
                            break;
                        } else
                            ans[sz++] = a[j];
                    }
                    break;
                } else {
                    ans[sz++] = a[i] + 1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < sz; i++) {
        cout << ans[i];
    }
    cout<<"\n";
}
int main() {
    while (scanf("%d", &N) == 1 && N) {
        v.clear();
        for (int i = 0; i < N; i++) {
            cin>>in;
            v.push_back(in);
        }
        sort(v.begin(), v.end());
        int a = (N - 1) / 2, b = a + 1;
        exec(v[a], v[b]);
     }
}
