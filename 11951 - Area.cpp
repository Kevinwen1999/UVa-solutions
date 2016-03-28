#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
int T, N, M, K;
int prefix[125][125];
long long curmin = INF,sum,area;
int main()
{
    cin>>T;
    for (int cnt = 1; cnt <= T; cnt++)
    {
        cin>>N>>M>>K;
        curmin = INF;area=0;
        for (int i = 0 ; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin>>prefix[i][j];
                if (i>0) prefix[i][j]+=prefix[i-1][j];
                if (j>0) prefix[i][j]+=prefix[i][j-1];
                if (i>0&&j>0) prefix[i][j]-=prefix[i-1][j-1];
            }
        }
    for (int i = 0 ; i  < N; i++)
        for (int j = 0 ; j  < M; j++)
            for (int k = i ; k  < N; k++)
                for (int l = j ; l < M; l++)
                {
                    sum = prefix[k][l];
                    if (i>0) sum-= prefix[i-1][l];
                    if (j>0) sum-= prefix[k][j-1];
                    if (i>0&&j>0) sum+= prefix[i-1][j-1];
                    if (sum>K) continue;
                    if ((k -i+1)*(l-j+1)>area||curmin>sum&&(k -i+1)*(l-j+1)==area)
                    {
                        curmin = sum;
                        area = (k-i+1)*(l-j+1);
                    }
                }
        cout<<"Case #"<<cnt<<": "<<area<<" ";
        if (area!=0)cout<<curmin<<endl;
        else cout<<"0"<<endl;
    }
}
