#include <bits/stdc++.h>
using namespace std;
 
int N, M;
map <char, int> mp;
char pm[4] = {'A', 'C', 'G', 'T'};
int cnt[4];
void exec() {
	cin >> M >> N;
	vector <string> v;
	string temp;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	int tot = 0;
	for (int i = 0; i < N; i++) {
		memset(cnt, 0, sizeof cnt);
		for (int j = 0; j < M; j++) {
			cnt[mp[v[j][i]]]++;
		}
		int mx = 0, idx;
		for (int j = 0; j < 4; j++) {
			if (cnt[j] > mx) {
				mx = cnt[j];
				idx = j;
			}
		}
		cout << pm[idx];
		tot += M - mx;
	}
	cout << "\n" << tot << "\n";
}
 
int main() {
	int T; cin >> T;
	mp['A'] = 0;
	mp['C'] = 1;
	mp['G'] = 2;
	mp['T'] = 3;
	while (T--) exec();
	return 0;
}
