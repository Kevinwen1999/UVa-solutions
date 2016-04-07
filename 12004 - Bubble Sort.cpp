#include <iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for (int i = 1; i <= T; i++)
    {
        cout<<"Case "<<i<<": ";
        long long N;
        cin>>N;
        long long ans = (N-1) * N / 2;
        if (ans % 2 ==0)
            cout<<ans/2<<endl;
        else
            cout<<ans<<"/2"<<endl;
    }
}
