#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string x;
    while (1)
    {
        cin>>x;
        if (x=="#")
            break;
        int len = x.length();
        if(next_permutation(x.begin(),x.end())==1)
        {
            cout<<x<<endl;
        }
        else
        {
            cout<<"No Successor"<<endl;
        }

    }
}
