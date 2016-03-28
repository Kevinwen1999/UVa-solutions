#include <iostream>
#include <cstring>
using namespace std;
int N, S;
int curstart = 1, curfin = 1, maxstart = 1, maxfin = 1, curmax = 0, ans = 0;
int ary[20025];
inline int maxx(int a, int b){return (a>b)?a:b;}
int main()
{
    cin>>N;
    for (int cnt = 1; cnt<=N; cnt++)
    {
        curstart = 1; curfin = 1; maxstart = 1; maxfin = 1; curmax = 0; ans = 0;
        cin>>S;
        for (int i = 2 ; i <= S; i++)
            cin>>ary[i];
        for (int i = 2; i <= S; i++)
        {
            ans+=ary[i];
            curfin = i;
            if (ans>curmax||(ans==curmax)&&(curfin-curstart>maxfin-maxstart))
            {
                curmax = ans;
                maxstart = curstart;
                maxfin = curfin;
            }
            if (ans<0)
            {
                ans = 0;
                curstart = i;
            }
        }
        if (curmax<=0||maxstart == maxfin)
            cout<<"Route "<<cnt<<" has no nice parts"<<endl;
        else
            cout<<"The nicest part of route "<<cnt<<" is between stops "<<maxstart<<" and "<<maxfin<<endl;
    }
        return 0;
}
