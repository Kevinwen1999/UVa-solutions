#include <bits/stdc++.h>
#define EPS 1e-10
using namespace std;
int N;

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
double GetLineIntersection(Point P, Vector v, Point Q, Vector w) {
    Vector u = P - Q;
    // t1 is for vector v, to calculate t2, use Cross(v, u)
    double t1 = Cross(w, u) / Cross(v, w);
    return fabs(t1);
    //return P + (t1 * v);
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

struct line {
    Point st;
    Vector v;
};
void exec() {
    Point cur, nex;
    vector <line> A;
    stack <int> all;
    for (int i = 0; i < N; i++) {
        cin>>cur.x>>cur.y>>nex.x>>nex.y;
        A.push_back((line){cur, nex-cur});
    }
    for (int i = N-1; i >= 0; i--) {
        bool ok = true;
        for (int j = i + 1; j < N && ok; j++) {
            double tt1 = Cross(A[i].v, A[j].st - A[i].st) * Cross(A[i].v, (A[j].st + A[j].v - A[i].st));
            double tt2 = Cross(A[j].v, A[i].st - A[j].st) * Cross(A[j].v, (A[i].st + A[i].v - A[j].st));
            if (dcmp(tt1) >= 0 || dcmp(tt2) >= 0) continue;
            double tmp = GetLineIntersection(A[i].st, A[i].v, A[j].st, A[j].v);
            //cout<<j<<" "<<tt<<endl;
            if (tmp > 0 && tmp < 1.0) ok = false;
        }
        if (ok) all.push(i+1);
    }
    cout<<"Top sticks: ";
    bool k = false;
    while(!all.empty()) {
        if (k) cout<<", ";
        else k = true;
        cout<<all.top();
        all.pop();
    }
    cout<<".\n";
}
int main () {
    while (1) {
        cin>>N;
        if (!N) break;
        exec();
    }
}
