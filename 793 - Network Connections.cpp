#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<int> p, r;
inline void init(int n) {
    p.resize(n);
    r.resize(n);
    for(int i=0; i<n; i++) p[i] = i;
    for(int i=0; i<n; i++) r[i] = 0;
}

inline int getSet(int i) {
    if(p[i] == i) return i;
    else return p[i] = getSet(p[i]);
}

inline bool sameSet(int i, int j) {
    int ii = getSet(i), jj = getSet(j);
    return ii == jj;
}

inline void joinSet(int i, int j) {
    if(sameSet(i, j)) return;
    int a = getSet(i), b = getSet(j);
    if(r[a] > r[b]) {
	p[b] = a;
    } else {
	p[a] = b;
	if(r[a] == r[b]) r[a]++;
    }
}

int yes, no, t, comps;
int main() {
    cin >> t;
    for(int tt=0; tt<t; tt++) {
	if(tt > 0) cout << '\n';

	string s;
	cin >> comps; getline(cin, s);
	init(comps);
	yes = 0, no = 0;
	while(getline(cin, s), s!="") {
	    stringstream ss(s);
	    char c;
	    long long a, b;
	    ss >> c >> a >> b; a--; b--;
	    if(c == 'c') joinSet(a, b);
	    else sameSet(a, b) ? yes++ : no++;
	}
	cout << yes << "," << no << '\n';
    }

    return 0;
}
