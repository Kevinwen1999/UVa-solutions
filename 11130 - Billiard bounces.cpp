#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double a, b, v, A, s;
double pi = acos(-1);
int main()
{
    while (scanf("%lf %lf %lf %lf %lf", &a, &b, &v, &A, &s))
    {
        if (a+b+v+A+s <1e-6) break;
        double hypot = s*v / 2;
        double adj = hypot * cos(A/180*pi);
        double opp = hypot * sin(A/180*pi);
        printf("%.0lf %.0lf\n", adj/a, opp/b);
    }
}
