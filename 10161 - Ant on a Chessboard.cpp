#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int N;
    while(cin >> N && N)
    {
        int dia = ceil(sqrt(N));
        int x, y, cur = dia * dia;
        if (dia % 2 != 0)
        {
            x = 1; y = dia;
            while(1)
            {
                if (cur == N) break;
                else if (x!=dia) x++;
                else y--;
                cur--;
            }
        }
        else
        {
            x = dia; y = 1;
            while(1)
            {
                if (cur == N) break;
                else if (y != dia) y++;
                else x--;
                cur--;
            }
        }
        cout<<x<<" "<<y<<endl;
    }
}
