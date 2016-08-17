#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#define EPS 1e-9
using namespace std;
struct point
{
    double x, y;
    point() {x = y = 0.0;}
    point(double a, double b) {x = a; y = b;}
}p1, p2, p3, p4;
double dist(point a, point b)
{
    return hypot(a.x-b.x, a.y-b.y);
}
struct line { double a, b, c;};
void point_to_line(point a, point b, line &l)
{
    if (fabs(a.x-b.x) < EPS)
    {
        l.a = 1.0; l.b = 0.0; l.c = -a.x;
    }
    else
    {
        l.a = -(double) (a.y-b.y) / (a.x-b.x);
        l.b = 1.0;
        l.c = -(double) (l.a * a.x) - a.y;
    }
}
struct vec {double x, y; vec(double a, double b) {x = a; y = b;}};
vec tovec(point a, point b){return vec(b.x - a.x, b.y-a.y);}
vec scale (vec v, double s) {return vec(v.x*s, v.y*s);}
point translate (point p, vec v) { return point(p.x + v.x, p.y + v.y);}
double magnitude (vec v) {return sqrt(v.x*v.x + v.y*v.y);}
double dot(vec a, vec b) {return (a.x*b.x + a.y*b.y);}
double norm_sq(vec v) {return v.x*v.x + v.y*v.y;}
double dist_to_line(point p, point a, point b, point &c)
{
    // c = a + u * ab
    // projection : dot(ap,ab) / sq(ab)
    vec ap = tovec(a,p), ab = tovec(a,b);
    double u = dot(ap,ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p,c);
}
double dist_to_lineseg(point p, point a, point b, point &c)
{
    vec ap = tovec(a,p), ab = tovec(a,b);
    double u = dot(ap,ab) / norm_sq(ab);
    if (u < 0.0)
    {
        c = point(a.x, a.y); return dist(p,a);
    }
    if (u > 1.0)
    {
        c = point(b.x, b.y); return dist(p,b);
    }
    return dist_to_line(p,a,b,c);
}
double angle(point a, point o, point b) //return angle AOB in rad, times 180.0/pi to get degree
{
    vec oa = tovec(o,a); vec ob = tovec(o,b);
    return acos(dot(oa, ob)/ sqrt(norm_sq(oa)*norm_sq(ob)));
}
double cross(vec a, vec b) {return a.x*b.y - a.y*b.x;}
double CCW (point p, point q, point r) {return cross(tovec(p,q), tovec(p,r)) > 0;} //return true if point R is on left side of line PQ
bool collinear (point p, point q, point r) {return fabs(cross(tovec(p,q), tovec(p,r)) ) < EPS;}
int N;
vector <point> v;
double mindist = 99999999.0, curdist;
point& pp3 = p3;
int main()
{
    while(scanf("%lf%lf", &p1.x, &p1.y)==2)
    {
        scanf("%d", &N);
        N++;
        v.clear();
        for (int i = 0; i < N; i++)
        {
            scanf("%lf%lf", &p2.x, &p2.y);
            v.push_back(p2);
        }
        mindist = 99999999.0;
        for (int i = 0; i < N-1; i++)
        {
            curdist = dist_to_lineseg(p1, v[i], v[i+1], p3);
            if (curdist < mindist)
            {
                mindist = curdist;
                //cout<<mindist<<"\n"<<p3.x<<"\t"<<p3.y<<"\n";
                p4.x = p3.x; p4.y = p3.y;
            }
        }
        printf("%.4lf\n%.4lf\n", p4.x, p4.y);
    }
}

