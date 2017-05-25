#include <bits/stdc++.h>
#define EPS 1e-10
using namespace std;

struct Point {
    double x, y;
    Point (double xx = 0, double yy = 0) {
        x = xx, y = yy;
    }
};
typedef Point Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator * (Vector A, double B) { return Vector(A.x * B, A.y * B); }
Vector operator / (Vector A, double B) { return Vector(A.x / B, A.y / B); }
bool operator < (const Point &a, const Point &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int dcmp(double x) {
    if (fabs(x) < EPS) return 0;
    else return x < 0 ? -1 : 1;
}
bool operator == (const Point &a, const Point &b) {
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }
double Magnitude(Vector A) { return sqrt(Dot(A, A)); }
double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Magnitude(A) / Magnitude(B)); }
double Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }
Vector Rotate(Vector A, double rad) { return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad)); }
Vector Normal(Vector A) {
    double L = Magnitude(A);
    return Vector(-A.y/L, A.x/L);
}
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w) {
    Vector u = P - Q;
    // t1 is for vector v, to calculate t2, use Cross(v, u)
    double t1 = Cross(w, u) / Cross(v, w);
    return P + (v * t1);
}
double DistanceToLine(Point P, Point A, Point B) {
    Vector v1 = B - A, v2 = P - A;
    return fabs(Cross(v1, v2)) / Magnitude(v1);
}
double DistanceToLineSegment(Point P, Point A, Point B) {
    if (A == B) return Magnitude(P - A);
    Vector v1 = B - A, v2 = P - A, v3 = P - B;
    if (dcmp(Dot(v1, v2)) < 0) return Magnitude(v2);
    else if (dcmp(Dot(v1, v3)) > 0) return Magnitude(v3);
    else return fabs(Cross(v1, v2)) / Magnitude(v1);
}
Point GetLineProjection(Point P, Point A, Point B) {
    Vector v = B - A;
    return A + v * (Dot(v, P - A) / Dot(v, v));
}
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
    double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
           c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
    return (dcmp(c1) * dcmp(c2)) < 0 && (dcmp(c3) * dcmp(c4)) < 0;
}
bool OnSegment(Point P, Point a1, Point a2) {
    return dcmp(Cross(a1 - P, a2 - P)) == 0 && dcmp(Dot(a1 - P, a2 - P)) < 0;
}
int main() {
    int N, cases = 0;
    while(scanf("%d", &N) == 1 && N) {
        vector <Point> ps, vs;
        for (int i = 0; i < N; i++) {
            double a, b;
            scanf("%lf%lf", &a, &b);
            ps.push_back((Point){a, b});
            vs.push_back((Point){a, b});
        }
        N--;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (SegmentProperIntersection(ps[i], ps[i + 1], ps[j], ps[j + 1])) {
                    vs.push_back(GetLineIntersection(ps[i], ps[i + 1] - ps[i], ps[j], ps[j + 1] - ps[j]));
                }
            }
        }
        sort(vs.begin(), vs.end());
        vs.erase(unique(vs.begin(), vs.end()), vs.end());
        int V = vs.size();
        int E = N;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < N; j++) {
                if (OnSegment(vs[i], ps[j], ps[j+1]))
                    E++;
            }
        }
        printf("Case %d: There are %d pieces.\n", ++cases, E - V + 2);
    }
}
