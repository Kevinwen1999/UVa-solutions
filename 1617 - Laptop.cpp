#include <bits/stdc++.h>
using namespace std;
vector <pair <int, int> > all;
bool cmp (pair <int, int> &a, pair<int, int> &b) {
    return (a.second == b.second) ? (a.first < b.first) : (a.second < b.second);
}
int N;
int main() {
    int T; scanf("%d", &T);
    while(T--) {
        all.clear();
        scanf("%d", &N);
        for (int i = 0, a, b; i < N; i++) {
            scanf("%d %d", &a, &b);
            all.push_back({a, b});
        }
        sort(all.begin(), all.end(), cmp);
        int cnt = -1, last = -1;
        for (auto i : all) {
            if (i.first > last) {
                cnt++;
                last = i.second;
            }
            else if (i.second != last){
                last++;
            }
        }
        printf("%d\n", cnt);
    }
}
