#include <iostream>
#include <string>
using namespace std;
long long tot = 0;
int main()
{
    int N,tmp;
    cin>>N;
    string in;
    while(N--)
    {
        cin>>in;
        if (in == "donate")
        {
            cin>>tmp;
            tot+=tmp;
        }
        else
            cout<<tot<<"\n";
    }
}
