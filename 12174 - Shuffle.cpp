#include <iostream>
#include <cstring>
#include <set>
using namespace std;
int T,S,N,ary[300030];
bool record[300030];
int occur[300030];
/*bool check(int index)
{
    if (record[index]==false) return false;
    if (record[index]==true && (index + N) >= S) return true;
    return check(index+ N);
}*/
int main()
{
    cin>>T;
    while (T--)
    {
        cin >> N >> S;
        for (int i = 0; i < S; i++)
        {
            cin>>ary[i];
        }
        for (int i = 0 ; i < S+N+1; i++)
        {
            if (i < S)
                record[i] = false;
            else
                record[i] = true;
        }
        int start = 0, fin = N-1;
        if (S < N) fin = S-1;
        memset(occur,0,sizeof occur);
        int diff = 0;
        occur[ary[start]] ++;
        diff++;
        for (int i = start+1; i <= fin; i++)
        {
            if (occur[ary[i]] == 0)
                diff++;
            occur[ary[i]]++;
        }
        if (diff == N) record[start] = true;
        while(fin < (S-1))
        {
            occur[ary[start]]--;
            if (occur[ary[start]] == 0)
                diff--;
            start++;
            fin++;
            if (occur[ary[fin]] == 0)
                diff++;
            if (diff == N) record[start] = true;
            occur[ary[fin]]++;
        }
        memset(occur,0,sizeof occur);
        occur[ary[fin]]++;
        record[fin] = true;
        for (int i = fin-1; i >= start; i--)
        {
            if (occur[ary[i]] ==0)
            {
                record[i] = true;
                occur[ary[i]]++;
            }
            else
                break;
        }
        int tot = 0;
        memset(occur,0,sizeof occur);
        for (int i = 0 ; i  < N; i++)
        {
            if (occur[ary[i]]== 0 || i >= S)
            {
                occur[ary[i]]++;
            }
            else
                break;
            bool valid = 1;
            for (int j = i+1;j < N+S+1; j+=N)
            {
                if (!record[j])
                    valid = 0;
            }
            if (valid)
                tot++;
        }
        cout<<tot<<endl;
        /*for (int i = 0 ; i < S; i++)
            cout<<record[i]<<" ";*/
    }
}
