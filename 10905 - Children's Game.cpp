#include <bits/stdc++.h>
using namespace std;

struct node {
    string s;
    node(string in) : s(in) {}
    bool operator < (node& a) const {
        string sa = s + a.s, as = a.s + s;
        for (int i = 0; i < sa.size(); i++) {
            if (sa[i] > as[i]) return true;
            else if (sa[i] < as[i]) return false;
        }
        return sa.size() < as.size();
    }
};

int N;

void exec() {
    vector <node> v;
    for (int i = 0; i < N; i++) {
        string in; cin >> in;
        v.push_back((node){in});
    }
    sort(v.begin(), v.end());
    for (auto i : v) 
        cout << i.s;
    cout << "\n";
}

int main() {
    while (cin >> N && N) {
        exec();
    }
}
