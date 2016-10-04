#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector <pair <int,int > > v;
int main()
{
    int cnt = 0;
    int N;
    while (cin>>N && N)
    {
        v.clear();
        for (int i = 0, b, j; i < N; i++)
        {
            cin>>b>>j;
            v.push_back(make_pair(-j,b));
        }
        sort(v.begin(), v.end());
        int start = 0, ans = 0;
        for (int i = 0; i < N; i++)
        {
            start += v[i].second;
            ans = max(ans,start - v[i].first);
        }
        cout<<"Case "<<++cnt<<": "<<ans<<"\n";
    }
}
