#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int N, D;
vector <char> all;
char in[MAXN];
bool check[MAXN];
int main() {
    while (scanf("%d %d", &N, &D) == 2 && (N + D)) {
        scanf("%s", in);
        all.clear();
        int al = N - D;
        for (int i = 0; i < N; i++) {
            char cur = in[i];
            if (!all.empty() && D) {
                while(!all.empty() && D && all.back() < cur) all.pop_back(), D--;
            }
            if (all.size() != al) all.push_back(cur);
        }
        for (char i : all) putchar(i);
        printf("\n");
    }
}
