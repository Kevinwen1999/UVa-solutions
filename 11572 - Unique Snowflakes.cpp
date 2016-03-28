#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int t, n, x, ans, cnt, block;
map<int, int> lastseen;
int main() {
    cin >> t;
    while(t--) {
	cin >> n;
	lastseen.clear();
	ans = 0, cnt = 0, block = 0;
	for(int i=1; i<=n; i++) {
	    cin >> x;
	    int lx = lastseen[x];
	    if(lx != 0) {
		block = max(block, lx);
		cnt = i-block-1;
	    }
	    cnt++;
	    lastseen[x] = i;
	    ans = max(ans, cnt);
	}
	cout << ans << '\n';
    }
}
