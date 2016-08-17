#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#define EPS 1e-9
using namespace std;
struct point
{
    double x, y;
    point() {x = y = 0.0;}
    point(double a, double b) {x = a; y = b;}
}p1, p2, p3;
double dist(point a, point b)
{
    return hypot(a.x-b.x, a.y-b.y);
}
bool cmp (point a, point b)
{
    return a.x > b.x;
}
int cnt, N;
vector <point> v;
point peak;
int main()
{
    scanf("%d", &cnt);
    cout<<fixed<<setprecision(2);
    while(cnt--)
    {
        scanf("%d", &N);
        v.clear();
        for (int i = 0; i < N; i++)
        {
            cin>>p1.x>>p1.y;
            v.push_back(p1);
        }
        sort(v.begin(), v.end(), cmp);
        peak.x = peak.y = 0;
        double sum = 0;
        for (int i = 1; i < N; i++)
        {
            if (v[i].y > peak.y)
            {
                sum += dist(v[i], v[i-1]) * (v[i].y - peak.y) / (v[i].y - v[i-1].y);
                peak.x = v[i].x; peak.y = v[i].y;
            }
        }
        cout<<sum<<"\n";
    }
}
