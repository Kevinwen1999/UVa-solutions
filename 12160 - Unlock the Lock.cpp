#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#define MP make_pair
using namespace std;
int L, U ,R;
int button[11];
int main()
{
    int cnt = 0;
    while (1)
    {
        cnt++;
        scanf("%d %d %d", &L, &U , &R);
        if (L==0&&U==0&&R==0) break;
        for (int i = 0 ; i < R; i++)
            scanf("%d", &button[i]);
        queue <pair <int,int> > buff;
        multiset<int> visited;
        buff.push(MP(L,0));
        visited.insert(L);
        int ans;
        bool isans = false;
        while(!buff.empty())
        {
            pair <int, int> top = buff.front();
            buff.pop();
            if (top.first == U)
            {
                isans = true;
                ans = top.second;
                break;
            }
            int temp;
            for (int i = 0 ; i < R ; i++)
            {
                temp = (top.first + button[i]) % 10000;
                if (visited.count(temp) == 0)
                {
                    visited.insert(temp);
                    buff.push(MP(temp,top.second+1));
                }
            }
        }
        printf("Case %d: ", cnt);
        if (isans)
        {
            printf("%d\n", ans);
        }
        else
        {
            puts("Permanently Locked");
        }
    }
}
