#include <iostream>
#include <cstring>
using namespace std;
int N,temp;
int ary[100000], dp[100000],test = 0;
int main()
{
    cin>>N;
    while (N!=-1)
    {
        memset(ary,0,sizeof ary);
        if (test>0)
            cout<<endl;
        test++;
        ary[0] = N;
        int cnt = 1, curmax = 0;
        cin>>N;
        while (N!=-1)
        {
            ary[cnt] = N;
            cnt++;
            cin>>N;
        }
        for (int i = 0 ; i < cnt; i++)
            dp[i] = 1;
        for (int i = 0; i < cnt; i++)
            for (int j = 0 ; j < i; j++)
            {
                if (ary[j]>=ary[i]&&dp[j]+1>dp[i])
                    dp[i] = dp[j] + 1;
            }
        for (int i = 0; i < cnt ; i++)
        {
            if (dp[i]>curmax)
                curmax = dp[i];
        }
        cout<<"Test #"<<test<<":"<<endl<<"  maximum possible interceptions: "<<curmax<<endl;
        cin>>N;
    }
    return 0;
}
