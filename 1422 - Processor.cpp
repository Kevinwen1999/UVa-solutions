#include <bits/stdc++.h>
#define EPS 1e-6
#define pii pair <int, pair <int, int> >
using namespace std;

int N;
vector <pii> v;
vector <int> p;
struct Compare {
    bool operator() (pair <int, double> const& a, pair <int, double> const& b) const {
        if (a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};

bool check(double speed) {
    int idx = 0;
    priority_queue <pair <int, double>, vector <pair <int, double> >, Compare> pq;
    for (int i = 0; i < p.size() - 1; i++) {
        while (idx < v.size() && v[idx].first == p[i]) {
            pq.push(make_pair(v[idx].second.first, v[idx].second.second));
            idx++;
        }
        double ct = p[i], et = p[i + 1];
        while (!pq.empty()) {
            pair <int, double> ctask = pq.top();
            if (ctask.first - ct <= EPS) return false;
            pq.pop();
            double tn = min(et - ct, ctask.second / speed);
            ctask.second -= tn * speed;
            if (ctask.second > EPS) pq.push(ctask);
            ct += tn;
            if (et - ct < EPS) break;
        }
    }
    return pq.empty();
}

void exec() {
    cin >> N;
    v.clear(), p.clear();
    for (int i = 0, a, b, c; i < N; i++) {
        cin >> a >> b >> c;
        v.push_back(make_pair(a, make_pair(b, c)));
        p.push_back(a), p.push_back(b);
    }
    sort(v.begin(), v.end());
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    int L = 1, R = 10000000;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    cout << min(L, 10000000) << "\n"; // Slight issue due to floating point percision
}

int main() {
    int T; cin >> T;
    while(T--) {
        exec();   
    }
}
