#include <iostream>
#include <cstring>
using namespace std;
int N;
int curmax=-100000, ans=0;
int ary[10025];
inline int maxx(int a, int b){return (a>b)?a:b;}
int main()
{
    cin>>N;
    while(N!=0)
    {
        curmax=-100000; ans=0;
        memset(ary,0,sizeof ary);
        for (int i = 0 ; i  <N; i++)
            cin>>ary[i];
        for (int i = 0 ; i < N; i++)
        {
            ans+=ary[i];
            curmax = maxx(curmax,ans);
            if (ans<0) ans = 0;
        }
        if (curmax<=0)cout<<"Losing streak."<<endl;
        else cout<<"The maximum winning streak is "<<curmax<<"."<<endl;
        cin>>N;
    }
}
