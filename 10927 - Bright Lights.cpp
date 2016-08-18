#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#define INF 99999999.0
#define MAXN 100010
using namespace std;
struct point
{
    int x, y, h;
    double t;
}p1, p2, p3, zer;
bool cmp(point a,point b)
{
    if( a.t == b.t )
        return a.x*1ll*a.x + a.y*1ll*a.y < b.x*1ll*b.x + b.y*1ll*b.y;
    return a.t < b.t;
}
bool cmp1(point a,point b)
{
    if( a.x == b.x ) return a.y < b.y;
    return a.x < b.x;
}
int N,cnt=1;
point v[MAXN], ans[MAXN];
int main()
{
    while(~scanf("%d", &N) && N)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].h);
            v[i].t = atan2(v[i].y, v[i].x);
            //else p1.t = INF;
        }
        sort(v, v+N, cmp);
        int tot = 0;
        int maxh = v[0].h;
        for (int i = 1; i < N; i++)
        {
            if (v[i].t==v[i-1].t)
            {
                if (v[i].h <= maxh)
                    ans[tot++] = v[i];
                maxh = max(maxh, v[i].h);
            }
            else
                maxh = v[i].h;
        }
        printf("Data set %d:\n", cnt++);
        if (tot==0)
            printf("All the lights are visible.\n");
        else
        {
            sort(ans, ans+tot, cmp1);
            printf("Some lights are not visible:\n");
            for (int i = 0; i < tot-1; i++)
            {
                printf("x = %d, y = %d;\n", ans[i].x, ans[i].y);
            }
            printf("x = %d, y = %d.\n", ans[tot-1].x, ans[tot-1].y);
        }
    }
    return 0;
}
