#include <iostream>
using namespace std;

int main()
{
    int T, D, I;
    cin>>T;
    while(T--)
    {
        cin>>D>>I;
        int K = 1;
        for (int i = 0 ; i < D-1 ; i++)
        {
            if (I%2==0)
            {
                K = 2 * K + 1;
                I/=2;
            }
            else
            {
                K = 2 * K;
                I = I/2 + 1;
            }
        }
        cout<<K<<endl;
    }
    return 0;
}
