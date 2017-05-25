#include <bits/stdc++.h>
#define EPS 1e-9
#define INF 0x3f3f3f3f
using namespace std;

struct Point {
    double x, y;
    Point (double xx = 0, double yy = 0) {
        x = xx, y = yy;
    }
    bool operator==(const Point &a) const {
        return fabs(x-a.x) < EPS && fabs(y-a.y) < EPS;
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

double MAXD, MIND;

int main() {
    int T, cases = 0;
    scanf("%d", &T);
    while (T--) {
        MAXD = -INF, MIND = INF;
        double totA = 0, totB = 0;
        int NA, NB;
        scanf("%d%d", &NA, &NB);
        vector <Point> PA, PB;
        for (int i = 0; i < NA; i++){
            double a, b;
            scanf("%lf%lf", &a, &b);
            PA.push_back((Point){a, b});
            if (i > 0) totA += Magnitude(PA[i] - PA[i-1]);
        }
        for (int i = 0; i < NB; i++){
            double a, b;
            scanf("%lf%lf", &a, &b);
            PB.push_back((Point){a, b});
            if (i > 0) totB += Magnitude(PB[i] - PB[i-1]);
        }
        int pa = 0, pb = 0;
        double dista, distb, t;
        Point SA = PA[0], SB = PB[0];
        Vector VA, VB;
        while (pa < NA-1 && pb < NB-1) {
            dista = Magnitude(PA[pa + 1] - SA);
            distb = Magnitude(PB[pb + 1] - SB);
            t = min (dista / totA, distb / totB);
            VA = (PA[pa + 1] - SA) * (t * totA / dista);
            VB = (PB[pb + 1] - SB) * (t * totB / distb);
            MIND = min(MIND, DistanceToLineSegment(SA, SB, SB + VB - VA));
            MAXD = max(MAXD, max(Magnitude(SB - SA), Magnitude(SB + VB - VA - SA)));
            SA = SA + VA;
            SB = SB + VB;
            if (SA == PA[pa + 1]) pa++;
            if (SB == PB[pb + 1]) pb++;
        }
//        printf("\n%lf %lf\n", MAXD, MIND);
        printf("Case %d: %.lf\n", ++cases, MAXD - MIND);
    }
}
