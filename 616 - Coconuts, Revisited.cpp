#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    while (cin>>N && N!=-1)
    {
        printf("%d coconuts, ", N);
        int i, j ,ans = 0;
        int limit = (int)sqrt(N) + 1;
        for (i = limit; i >= 2; i--)
        {
            int tot = N;
            for (j = 1; j <= i; j++)
            {
                if (tot % i != 1)
                    break;
                tot = tot - tot/i - 1;
            }
            if (j== i+1 && tot%i ==0)
            {
                ans = 1;
                printf("%d people and 1 monkey\n", i);
                break;
            }
        }
        if (!ans)
            puts("no solution");
    }
}
