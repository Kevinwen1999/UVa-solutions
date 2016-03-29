#include <iostream>
#include <cstring>
using namespace std;
int T,K,A,B;
long long c[31];
long long tot;
long long f(int k, int i)
{
    if (i==0) return 0;
    if (k==0) return 1;
    if (i < (1 << (k-1)))
        return 2*f(k-1,i);
    else
        return f(k-1,i-(1<<(k-1))) + 2*c[k-1];
}
int main()
{
    c[0] = 1;
    for (int i = 1; i <= 30; i++)
        c[i] = 3*c[i-1];
    cin>>T;
    for (int cnt = 1; cnt <= T; cnt++)
    {
        cin>>K>>A>>B;
        tot = f(K,B) - f(K,A-1);
        cout<<"Case "<<cnt<<": "<<tot<<endl;
    }
    return 0;
}
