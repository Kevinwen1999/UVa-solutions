#include <iostream>
#include <cmath>
#define EPS 1e-9
using namespace std;
double a, b;
const double PI = acos(-1.0);
int main()
{
    int cse = 0;
    while (scanf("%lf : %lf", &a, &b) == 2)
    {
        double l = 0.00, h = 400.00, angle, arc, r, L, W;
        while (fabs(l - h) > EPS)
        {
            L = (l+h)/2;
            W = b/a * L;
            r = sqrt(0.5*L*0.5*L + 0.5*W*0.5*W);
            angle = 2.0 * atan(0.5*W/0.5/L)*180/PI;
            arc = angle / 360 * PI * (2.0*r);
            if (arc * 2 + L * 2 > 400)
                h = L;
            else
                l = L;
        }
        printf("Case %d: %.12lf %.12lf\n", ++cse, L, W);

    }
}
