#include <iostream>
using namespace std;
int N, R;
double p[25], ans[25];
int bcount(int i)
{
    int cnt  = 0;
    for (int j = 0; j < N; j++)
    {
        if (i & (1<<j))
            cnt ++;
    }
    return cnt;
}
int main()
{
    int Cas = 1;
    while(cin>>N>>R)
    {
        if (!(N||R)) break;
        double anstot = 0;
        for (int j = 0; j < N; j++)
        {
            cin>>p[j];
            ans[j] = 0;
        }
        for (int mask = 0; mask < (1<<N); mask++)
        {
            if (bcount(mask) == R)
            {
                double tmp = 1;
                for (int j = 0; j < N; j++)
                {
                    if (mask & (1<<j)) tmp *= p[j];
                    else tmp *= (1-p[j]);
                }
                anstot +=tmp;
                for (int i = 0; i < N; i++)
                {
                    if (mask & (1<<i)) ans[i] += tmp;
                }
            }
        }
        printf("Case %d:\n",Cas++);
        for(int i=0;i<N;i++) printf("%.6lf\n",ans[i]/anstot);
    }
}
