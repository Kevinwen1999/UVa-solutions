#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int T,N;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        if (N==1){cout<<"0.000"<<endl;}
        else if (N==2){cout<<"4.000"<<endl;}
        else
        {
            double ans = 2*(N-1) + N + ( (1 + N-3)*(N-3) + N-2)*sqrt(2) + (N-2);
            cout<<fixed;
            cout<<setprecision(3);
            cout<<ans<<endl;
        }
        if (T) cout<<endl;
    }
}
