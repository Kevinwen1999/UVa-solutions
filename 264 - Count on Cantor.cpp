#include <iostream>
using namespace std;
int N;
int main()
{
    while(cin >> N)
    {
        int i;
        for ( i = 1; ;i++)
        {
            if (i*(i+1)/2 + 1 > N)
            {
                i--; break;
            }
        }
        int a , b, start = i*(i+1) / 2 + 1;
        a = 1 + (N - start); b = i - (N - start) + 1;
        if (i%2!=0)
            printf("TERM %d IS %d/%d\n", N, a, b);
        else
            printf("TERM %d IS %d/%d\n", N, b, a);
    }
}
