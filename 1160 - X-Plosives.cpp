#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int N;
int p[MAXN], rnk[MAXN];

void init(int N)
{
    for (int i = 0; i <= N; i++)
        p[i] = i, rnk[i] = 1;
}
int findp(int x)
{
    return p[x] == x ? x : (p[x] = findp(p[x]));
}
bool sameset(int x, int y)
{
    return findp(x) == findp(y);
}
void mergeset(int x, int y)
{
    if (!sameset(x, y))
    {
        x = findp(x), y = findp(y); // EXTREMELY IMPORTANT !!!!!!!!!
        if (rnk[x] > rnk[y])
            rnk[x] += rnk[y], p[y] = x;
        else
            rnk[y] += rnk[x], p[x] = y;
    }
}

vector <pair <int, int> > in;
bool input() {
    in.clear();
    int a, b;
    while (1) {
        cin >> a;
        if (cin.eof()) return false;
        if (a == -1) return true;
        cin >> b;
        in.push_back({a, b});
    }
}
int main() {
    while (1) {
        if (!input()) return 0;
        init(100000);
        int cnt = 0;
        for (auto i : in) {
            if (sameset(i.first, i.second)) cnt++;
            else mergeset(i.first, i.second);
        }
        cout << cnt << "\n";
    }
}
