#include <bits/stdc++.h>
#define MOD 20071027
#define MAXM 301000
#define MAXN 110
#define SIGMA 30
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-9
using namespace std;

int m;
string match;
int b[1000010];
void kmpPreprocess()
{
    memset(b, 0, sizeof b);
    int i = 0, j = -1; b[0] = -1;
    while (i < m)
    {
        while (j >= 0 && match[i] != match[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

int main() {
    int N, ks = 0;
    while (cin >> N && N) {
        m = N;
        cin >> match;
        kmpPreprocess();
        printf("Test case #%d\n", ++ks);
        for (int i = 2; i <= m; i++) {
            if (b[i] > 0 && i % (i - b[i]) == 0)
                printf("%d %d\n", i, i / (i - b[i]));
        }
        printf("\n");
    }
}
