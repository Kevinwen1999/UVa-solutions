#include <bits/stdc++.h>
using namespace std;

int N;
struct node {
    int id;
    int l;
    double f;
};

bool cmp (node &a, node &b) {
    return a.f * b.l > b.f * a.l;
}

int main() {
    while (cin >> N && !cin.eof()) {
        vector <node> v;
        double c;
        for (int i = 0, a, b; i < N; i++) {
            cin >> a >> b >> c;
            v.push_back((node){a, b, c});
        }
        sort(v.begin(), v.end(), cmp);
        int Q; cin >> Q;
        cout << v[Q - 1].id << "\n";
    }
}
