#include <iostream>
#include <set>
using namespace std;
int T,N;
int A[200010],G[200010],S[200010];
struct Candidate
{
    int a, g;
    Candidate(int x, int y) { a = x; g = y;}
    bool operator< (const Candidate &another) const
    {
        return a < another.a;
    }
};
set <Candidate> s;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>N;
        s.clear();
        for (int i = 0 ; i < N; i++)
            cin>>A[i];
        if (N==1)
        {
            cout<<1<<endl;
            continue;
        }
        G[0] = 1;
        S[N-1] = 1;
        for (int i = 1; i < N; i++)
        {
            if (A[i-1]<A[i])
                G[i] = G[i-1]+1;
            else
                G[i] = 1;
        }
        for (int i = N-2; i >=0; i++)
        {
            if(A[i]<A[i+1])
                S[i] = S[i+1]+1;
            else
                S[i] = 1;
        }
        s.insert(Candidate(A[0],G[0]));
        int ans = 1;
        for (int i = 1; i < N; i++)
        {
            Candidate c(A[i],G[i]);
            set <Candidate> :: iterator it = s.lower_bound(c);
            bool keep = true;
            if (it!=s.begin())
            {
                Candidate last = *(--it);
                int len = last.g + S[i];
                ans = max(ans, len);
                if (c.g<=last.g) keep = false;
            }
            if (keep)
            {
                s.erase(c);
                s.insert(c);
                it = s.find(c);
                it++;
                while(it!=s.end()&&it->a > c.a&&it->g <= c.g)
                    s.erase(it++);
            }
        }
        cout<<ans<<endl;
    }
}
