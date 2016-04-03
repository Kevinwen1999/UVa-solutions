#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int main()
{
    int T;
    cin>>T;
    vector <int> buff;
    for (int c = 1; c <= T; c++)
    {
        cin>>N;
        buff.clear();
        for (int i = 0,x ; i < N; i++)
        {
            cin>>x;
            buff.push_back(x);
        }
        sort(buff.begin(),buff.end());
        int index = N / 2 ;
        cout<<"Case "<<c<<": "<<buff[index]<<endl;
    }
}
