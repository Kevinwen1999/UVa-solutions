#include <bits/stdc++.h>
#define EPS 1e-10

#define MAXN 510
#define INF 0x3f3f3f3f

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

int R1, R2, N, tot;
vector <Point> pol[MAXN];
double ANS = INF;
double dist[MAXN][MAXN];
double SegmentDist(Point A, Point B, Point C, Point D) {
    double ans = INF;
    ans = min(ans, DistanceToLineSegment(A, C, D));
    ans = min(ans, DistanceToLineSegment(B, C, D));
    ans = min(ans, DistanceToLineSegment(C, A, B));
    ans = min(ans, DistanceToLineSegment(D, A, B));
    return ans;
}
void exec() {
    tot = 0, ANS = INF;
    cin>>R1>>R2>>N;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            dist[i][j] = INF;
        }
        pol[i].clear();
    }
    for (double x, y; tot < R1; tot++) {
        cin>>x>>y;
        pol[0].push_back(Point(x, y));
    }
    for (double x, y; tot < R1+R2; tot++) {
        cin>>x>>y;
        pol[1].push_back(Point(x, y));
    }
    for (int i = 0, n; i < N; i++) {
        cin>>n;
        double x, y;
        for (int j = 0; j < n; j++) {
            cin>>x>>y;
            pol[i + 2].push_back(Point(x, y));
        }
        pol[i + 2].push_back(pol[i + 2][0]);
    }
    N += 2;

    // polygons to each other
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double ta = INF;
            for (int k = 0; k < pol[i].size() - 1; k++) {
                for (int l = 0; l < pol[j].size() - 1; l++) {
                    ta = min(ta, SegmentDist(pol[i][k], pol[i][(k+1) % pol[i].size()], pol[j][l], pol[j][(l+1) % pol[j].size()]));
                }
            }
            dist[i][j] = dist[j][i] = ta;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    printf("%.3lf\n", dist[0][1]);
}

int main() {
    int T; cin>>T;
    while(T--) {
        exec();
    }
}
