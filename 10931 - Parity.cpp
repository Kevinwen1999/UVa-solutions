#include <iostream>
#include <deque>
using namespace std;
unsigned long long in;
deque <int> d;
int main()
{
    while (cin>>in&&in)
    {
        cout<<"The parity of ";
        int sum = 0;
        int cur;
        while (in)
        {
            cur = in % 2;
            d.push_back(cur);
            if (cur) sum++;
            in /= 2;
        }
        while (!d.empty())
        {
            cout<<d.back();
            d.pop_back();
        }
        cout<<" is "<<sum<<" (mod 2).\n";
    }
}
