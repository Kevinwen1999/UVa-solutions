#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int N;
int p[MAXN], dist[MAXN];

void init(int N)
{
    for (int i = 0; i <= N; i++)
        p[i] = i, dist[i] = 0;
}
int findp(int x)
{
    if (p[x] == x)
        return p[x];
    else {
        int pa = findp(p[x]);
        dist[x] += dist[p[x]];
        return p[x] = pa;
    }
}
bool sameset(int x, int y)
{
    return findp(x) == findp(y);
}

vector <pair <int, int> > in;
bool input() {
    cin >> N;
    init(N);
    char op;
    int a, b;
    while(1) {
        cin >> op;
        if (op == 'O') break;
        if (op == 'E') {
            cin >> a;
            findp(a);
            cout << dist[a] << "\n";
        } else {
            cin >> a >> b;
            dist[a] = abs(a - b) % 1000;
            p[a] = b;
        }
    }
}
int main() {
    int T; cin >> T;
    while(T--) {
        input();
    }
}
