#include <iostream>
#include <cstring>

using namespace std;
int Prime[5200], Pt;
int ans[1121][15];
int n,m;
void sieve() {
    char mark[10000] = {};
    Pt = 0;
    int i, j;
    for(i = 2; i < 10000; i++) {
        if(mark[i] == 0) {
            Prime[Pt++] = i;
            for(j = 2; i*j < 10000; j++)
                mark[i*j] = 1;
        }
    }
}
void dp()
{
    ans[0][0] = 1;
    for (int i = 0 ; i < Pt; i++)
        for (int j = 1120; j >= Prime[i] ;j--)
            for (int k = 14; k >= 1; k--)
                ans[j][k]+= ans[j-Prime[i]][k-1];
}
int main()
{
    sieve();
    dp();
    while (1)
    {
        cin>>n>>m;
        if (n==0&&m==0)break;
        cout<<ans[n][m]<<endl;
    }
}
