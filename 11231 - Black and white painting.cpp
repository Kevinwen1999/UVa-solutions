#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long x, y , color, main, few, sum ;
    while(1)
    {
        cin>>y>>x>>color;
        if (x==0&&y==0&&color==0) break;
        x = x-8+1; y = y-8+1;
        if (color == 1)
        {
            main =  ceil(y * 0.5);
            few = floor(y * 0.5);
        }
        else
        {
            main = floor(y * 0.5);
            few =  ceil(y * 0.5);
        }
        sum = ceil(x * 0.5) * main + floor(x * 0.5) * few;
        cout<<sum<<endl;
    }
}
