#include <bitset>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MAXN = 30000030;
int d[MAXN];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
void gen()
{
    for (int c = 1; c <= MAXN/2; c++)
    {
        for (int a = c+c; a < MAXN; a+= c)
        {
            int b = a ^ c;
            if (b == a - c) d[a]++; // pattern: if gcd(a,b) = a ^ b = c then b = a - c

        }
    }
    for (int i = 2; i< MAXN; i++)
        d[i]+=d[i-1];
}
int N;
int main()
{
    gen();
    int T;
    cin>>T;
    for (int cse = 1; cse <= T; cse++)
    {
        cin>>N;
        printf("Case %d: %d\n", cse, d[N]);
    }
}
