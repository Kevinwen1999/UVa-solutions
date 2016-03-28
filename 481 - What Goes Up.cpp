#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int ary[100000], dp[100000], id[100000] , P[100000],temp, cnt, lis, lisend;
int main()
{
    cin>>temp;
    while (!cin.eof())
    {
        ary[cnt] = temp;
        cnt++;
        cin>>temp;
    }
    for (int i = 0 ; i < cnt; i++)
    {
        int pos = lower_bound(dp,dp+lis,ary[i])-dp;
        dp[pos] = ary[i];
        id[pos] = i;
        if (pos==0)
            P[i] = -1;
        else
            P[i] = id[pos-1];
        if (pos+1>lis)
        {
            lis = pos+1;
            lisend = i;
        }

    }
    cout<<lis<<endl<<"-"<<endl;
    stack <int> buff;
    while (lisend>=0)
    {
        buff.push(ary[lisend]);
        lisend = P[lisend];
    }
    while (!buff.empty())
    {
        cout<<buff.top()<<endl;
        buff.pop();
    }
    return 0;

}
