#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;
int L, T, N;
struct ant
{
    int id; // id of ant
    int p; // position of ant
    int d; // direction of ant, -1 for L, 0 for turning, 1 for R
    bool operator < (const ant& n) const
    {
        return p < n.p;
    }
}ori[MAXN], after[MAXN],cur;
int o[MAXN]; // map that store index of element after sorted
string dir[3] = {"L", "Turning", "R"};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int C; cin>>C;
    for (int cse = 1; cse <= C; cse++)
    {
        cin>>L>>T>>N;
        for (int i = 0; i < N; i++)
        {
            char op; int p;
            cin>>p>>op;
            int d = (op=='R' ? 1 : -1);
            ori[i] = (ant){i,p,d};
            after[i] = (ant){0,p+T*d,d};
        }
        sort(ori,ori+N);
        for (int i = 0; i < N; i++)
        {
            o[ori[i].id] = i;
        }
        sort(after,after+N);
        for (int i = 0; i < N-1; i++)
        {
            if (after[i].p == after[i+1].p)
                after[i].d = after[i+1].d = 0;
        }
        cout<<"Case #"<<cse<<":\n";
        for (int i = 0; i < N; i++)
        {
            int c = o[i];
            if (after[c].p < 0 || after[c].p > L)
                cout<<"Fell off\n";
            else
                cout<<after[c].p<<" "<<dir[after[c].d+1]<<"\n";
        }
        cout<<"\n";
    }
}
