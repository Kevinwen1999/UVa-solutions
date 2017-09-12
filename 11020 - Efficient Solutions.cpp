#include <bits/stdc++.h>
#define MAXN 15010
using namespace std;

struct node{
    int c, l;
    bool operator < (const node& a) const {
        if (c == a.c) {
            return l < a.l;
        }
        return c < a.c;
    }
};
int N;
multiset <node> all;
void exec() {
    cin>>N;
    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        node tn = (node){a, b};
        auto pt = all.lower_bound(tn);
        if (pt == all.begin() || (--pt) -> l > b) {
            all.insert(tn);
            pt = all.upper_bound(tn);
            while(pt != all.end() && pt -> l >= b) {
                all.erase(pt++);
            }
        }
        cout<<all.size()<<"\n";
    }
}

int main() {
    int T;
    cin>>T;
    for (int ks = 1; ks <= T; ks++) {
        all.clear();
        if (ks > 1) cout<<"\n";
        cout<<"Case #"<<ks<<":\n";
        exec();
    }
}
