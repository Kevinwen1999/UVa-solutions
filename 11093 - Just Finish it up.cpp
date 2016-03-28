#include <iostream>
#include <cstring>
using namespace std;
int N, T;
int p[100001];
int v[100001];
bool tried[100001];
int main()
{
    cin>>T;
    for (int cnt = 1; cnt <= T; cnt++)
    {
        cin>>N;
        memset(tried, 0, sizeof tried);
        for (int i = 0 ; i < N; i++)
            cin>>p[i];
        for (int i = 0 ; i < N; i++)
            cin>>v[i];
        int start = 0, fuel = 0,  cur, next;
        bool OK = true;
        while (1)
        {
            cur = start;
            fuel = 0;
            if (tried[start])
            {
                OK = false;
                break;
            }
            OK = true;
            tried[start] = true;
            for (int i = 0 ; i < N; i++)
            {
                fuel += p[cur];
                next = (cur + 1 >= N) ? 0 : (cur + 1);
                if (fuel >= v[cur])
                {
                    fuel -= v[cur];
                    cur = next;
                }
                else
                {
                    OK = false;
                    start = next;
                    break;
                }
            }
            if (OK) break;
        }
        cout<<"Case "<<cnt<<": ";
        if (OK)
            cout<<"Possible from station "<<start+1<<endl;
        else
            cout<<"Not possible"<<endl;
    }
}
