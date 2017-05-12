#include <bits/stdc++.h>
using namespace std;
#define MAXN 30
#define INF 0x3f3f3f3f
#define EPS 1e-9
const double PI = acos(-1.0);
bool dequals(double a, double b) {
    return fabs(a - b) < EPS;
}
struct point
{
    double x, y;
    point() {x = y = 0.0;}
    point(double a, double b) {x = a; y = b;}
    bool operator == (point other) const
    {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
}p1, p2, p3;
struct vec {double x, y; vec(double a, double b) {x = a; y = b;}};
vec tovec(point a, point b){return vec(b.x - a.x, b.y-a.y);}
vec scale (vec v, double s) {return vec(v.x*s, v.y*s);}
point translate (point p, vec v) { return point(p.x + v.x, p.y + v.y);}
double magnitude (vec v) {return sqrt(v.x*v.x + v.y*v.y);}
double dot(vec a, vec b) {return (a.x*b.x + a.y*b.y);}
double norm_sq(vec v) {return v.x*v.x + v.y*v.y;}
double angle(point a, point o, point b) //return angle AOB in rad, times 180.0/pi to get degree
{
    vec oa = tovec(o,a); vec ob = tovec(o,b);
    return acos(dot(oa, ob)/ sqrt(norm_sq(oa)*norm_sq(ob)));
}
double cross(vec a, vec b) {return a.x*b.y - a.y*b.x;}
double CCW (point p, point q, point r) {return cross(tovec(p,q), tovec(p,r));}
int N;
point PA[MAXN];
bool isClockwize;
double calcang(int i, point p[]) {
    int A = i, B = (i+1)%N, C = (i+2)%N;
    double ang = 0;
    double ta = angle(p[A], p[B], p[C]);
    double flag = cross(tovec(p[B], p[A]), tovec(p[B], p[C]));
    if (!isClockwize) flag = -flag;
    if (flag < 0) ang += PI + (PI-ta);
    else ang = ta;
    return ang;
}
void clockwize(int idx) {
    int A = (idx - 1 + N) % N, B = (idx + 1) % N;
    if (PA[A].x == PA[B].x) {
        isClockwize = (PA[A].y > PA[B].y);
    }
    else
        isClockwize = (PA[A].x < PA[B].x);
}
int main() {
    while(!cin.eof() && cin>>N && N >= 3) {
        int idx = 0;
        int ix = -INF, iy = -INF;
        for (int i = 0, x, y; i < N; i++) {
            cin>>x>>y;
            PA[i] = point(x,y);
            if (y > iy || (y == iy && x >= ix)) {
                ix = x, iy = y, idx = i;
            }
        }
        clockwize(idx);
        double maxa = -INF, mina = INF;
        for (int i = 0; i < N; i++) {
            double a = calcang(i, PA);
            maxa = max(maxa, a);
            mina = min(mina, a);
        }
        maxa *= 180.0/PI;
        mina *= 180.0/PI;
        printf("%.6lf %.6lf\n", mina, maxa);
    }
}
