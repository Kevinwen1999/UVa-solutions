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
double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Magnitude(A) / Magnitude(B)); } // -angle if rotate clockwise
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
    //return fabs(t1);
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

void read(Point &a) {
    double x, y;
    cin>>x>>y;
    a = Point(x, y);
}
Point calc(Point A, Point B, Point C) {
    Vector v1 = Rotate(C - B, Angle(C - B, A - B) / 3.0);
    Vector v2 = Rotate(B - C, -Angle(B - C, A - C) / 3.0); // rotate clockwise
    return GetLineIntersection(B, v1, C, v2);
}
int main() {
    int T; cin>>T;
    Point A, B, C, D, E, F;
    while(T--) {
        read(A);
        read(B);
        read(C);
        D = calc(A, B, C);
        E = calc(B, C, A);
        F = calc(C, A, B);
        printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n", D.x, D.y, E.x, E.y, F.x, F.y);
    }
}
