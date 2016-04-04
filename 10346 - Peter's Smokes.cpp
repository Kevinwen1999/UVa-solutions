#include <iostream>
using namespace std;
long long N, K;
int main()
{
    while (cin>>N>>K && !cin.eof())
    {
        long long left = N, tot = 0;
        while(left >= K)
        {
            left-=K;
            tot+=K;
            left++;
        }
        tot+=left;
        cout<<tot<<endl;
    }
}
