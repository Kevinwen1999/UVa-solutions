#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[1000050], s[1000050], l[1000050];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N;
        for (int i = 0 ; i < N; i++)
            cin>>p[i];
        for (int i = 0; i < N; i++)
            cin>>s[i];
        int level = s[0];  long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (level > s[i])
                level = s[i];
            if (level < p[i])
                level = p[i];
            l[i] = level;
        }
        for (int i = N-1; i >= 0; i--)
        {
            if (level > s[i])
                level = s[i];
            if (level < p[i])
                level = p[i];
            l[i] = min(l[i],level);
            sum += (l[i] - p[i]);
        }
        cout<<sum<<endl;
    }
}
