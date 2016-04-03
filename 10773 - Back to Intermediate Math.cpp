#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
const double eps = 1e-6;
int main()
{
    int T;
    cin>>T;
    for (int c = 1 ; c <= T; c++)
    {
        double d,v,u;
        cin>>d>>v>>u;
        cout<<"Case "<<c<<": ";
        if (u - v < eps || u < eps || v < eps)
        {
            cout<<"can't determine"<<endl;
            continue;
        }
        double ver = sqrt(u*u-v*v);
        double ans = fabs( d/u - d/ver);
        cout<<fixed;
        cout<<setprecision(3);
        cout<<ans<<endl;
    }
}
