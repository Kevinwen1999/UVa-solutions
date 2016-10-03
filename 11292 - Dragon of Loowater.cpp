#include <iostream>
#include <algorithm>
#include <vector>
const int MAXN = 20010;
using namespace std;
vector <int> head, knight;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    while (cin>>N>>M)
    {
        if (!(N+M)) break;
        head.clear(); knight.clear();
        for (int i = 0, tmp; i < N; i++)
        {
            cin>>tmp; head.push_back(tmp);
        }
        for (int i = 0, tmp; i < M; i++)
        {
            cin>>tmp; knight.push_back(tmp);
        }
        sort(head.begin(), head.end());
        sort(knight.begin(), knight.end());
        int cnt = 0, tot = 0;
        bool OK = false;
        for (int i = 0; i < M && !OK; i++)
        {
            if (knight[i] >= head[cnt])
            {
                tot += knight[i];
                if (++cnt == N) OK = true;
            }
        }
        if (OK)
            cout<<tot<<"\n";
        else
            cout<<"Loowater is doomed!\n";
    }
}
