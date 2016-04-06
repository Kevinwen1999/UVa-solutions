#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long N;
    while (cin>>N && N!=-1)
    {
        cout<<N<<" = ";
        long long start = 1,ans,ans2,sum;bool OK = false;
        /*
        for (start = 1; start <= N; start++)
        {
            long long sum = 0,n = 1;
            while(1)
            {
                if (n > sqrt(2*N)) break;
                sum = n * (2 * start + (n - 1)) / 2;
                if (sum > N) break;
                if (sum==N)
                {
                    OK = true;
                    ans = start;
                    ans2 = start + n-1;
                    break;
                }
                n++;
            }
            if (OK) break;
        }
        */
        for (int r = sqrt(2*N); r >= 1; r--)
        {
            start = (2*N - r*r + r) / (2*r);
            sum = r* (2 * start + (r - 1)) / 2;
            if (sum == N)
            {
                ans = start;
                ans2 = start + r - 1;
                break;
            }
        }
        cout<<ans<<" + ... + "<<ans2<<endl;
    }
}
