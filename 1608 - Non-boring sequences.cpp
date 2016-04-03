#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int N;
int a[200050],l[200050],r[200050];
bool unique(int lf , int rt , int i)
{
    return (l[i] < lf && r[i] > rt);
}
bool recur(int L, int R )
{
    if (L>=R ) return true;
    // meet in the middle lol
    for (int i = 0 ;L + i <= R  - i; i++)
    {
        if (unique(L,R ,L + i))
            return recur(L +i+1,R ) && recur(L,L +i-1);
        if (L + i == R  - i) break;
        if (unique(L,R ,R -i))
            return recur(R -i+1,R ) && recur(L,R -i-1);
    }
    return false;
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        cin>>N;
        for (int i = 0 ; i < N; i++)
            cin>>a[i];
        map<int,int> M;
        for (int i = 0; i < N; i++)
        {
            if (M.count(a[i]) ==0 )
            {
                l[i] = -1;
                M[a[i]] = i;
            }
            else
            {
                l[i] = M[a[i]];
                M[a[i]] = i;
            }
        }
        M.clear();
        for (int i = N-1; i >= 0; i--)
        {
            if (M.count(a[i]) ==0 )
            {
                r[i] = N;
                M[a[i]] = i;
            }
            else
            {
                r[i] = M[a[i]];
                M[a[i]] = i;
            }
        }
        /*for (int i = 0 ; i < N; i++)
            cout<<i<<" : left: "<<l[i]<<" right: "<<r[i]<<endl;*/
        if (recur(0,N-1))
            cout<<"non-boring"<<endl;
        else
            cout<<"boring"<<endl;
    }
}
