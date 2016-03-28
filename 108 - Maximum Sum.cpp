#include <iostream>
#include <cstring>
#define NINF -0x3f3f3f3f
using namespace std;
int N, curmax = NINF,sum;
int prefix[125][125];
inline int maxx(int a, int b){return (a>b)?a:b;}
int main()
{
    cin>>N;
    for (int i = 0 ; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>prefix[i][j];
            if (i>0) prefix[i][j]+=prefix[i-1][j];
            if (j>0) prefix[i][j]+=prefix[i][j-1];
            if (i>0&&j>0) prefix[i][j]-=prefix[i-1][j-1];
        }
    }
    for (int i = 0 ; i  < N; i++)
        for (int j = 0 ; j  < N; j++)
            for (int k = i ; k  < N; k++)
                for (int l = j ; l < N; l++)
                {
                    sum = prefix[k][l];
                    if (i>0) sum-= prefix[i-1][l];
                    if (j>0) sum-= prefix[k][j-1];
                    if (i>0&&j>0) sum+= prefix[i-1][j-1];
                    curmax = maxx(curmax,sum);
                }
    cout<<curmax<<endl;
    return 0;

}
