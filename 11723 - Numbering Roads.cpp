#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long R, N;
int main()
{
    for (int c = 1; c <= 10002; c++)
    {
        cin>>R>>N;
        if (R==0&&N==0) break;
        int k = (R-1) / N;
        cout<<"Case "<<c<<": ";
        if (k>26)
            cout<<"impossible"<<endl;
        else
            cout<<k<<endl;
    }
}
