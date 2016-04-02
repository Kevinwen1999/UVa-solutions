#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, NE;
int sum[33000],value[33000];
int main()
{
    while(cin>>N && !cin.eof())
    {
        memset(sum,0,sizeof sum);
        memset(value,0,sizeof value);
        NE = 2 << (N-1);
        for (int i = 0 ; i < NE; i++)
            cin>>value[i];
        int cursum = 0, index;
        for (int i = 0 ; i < NE; i++)
        {
            cursum = 0;
            for (int j = 0 ; j < N; j++)
            {
                index = i ^ (1<<j);
                cursum += value[index];
            }
            sum[i] = cursum;
        }
        int maxsum = 0;
        for (int i = 0 ; i < NE; i++)
            for (int j = 0; j < N; j++)
            {
                index = i ^ (1<<j);
                cursum = sum[i] + sum[index];
                maxsum = max(maxsum, cursum);
            }
        cout<<maxsum<<endl;
    }
}
