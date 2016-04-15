
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct point
{
    double x;
    double y;
};

double calDistance(long long n, long long m)
{
    point nn, mm;
    long long start = (long long)sqrt(n);
    nn.x = (n - start * start - start) / 2.0;
    nn.y = 0.0;
    if (start)
    {
        nn.y = (start - 1) * (sqrt(3) / 2.0);
        nn.y += ((start + n) & 1 ? (sqrt(3) / 3.0) : (sqrt(3) / 2.0));
    }
    start = (long long)sqrt(m);
    mm.x = (m - start * start - start) / 2.0;
    mm.y = 0.0;
    if (start)
    {
        mm.y = (start - 1) * (sqrt(3) / 2.0);
        mm.y += ((start + m) & 1 ? (sqrt(3) / 3.0) : (sqrt(3) / 2.0));
    }

    return hypot((nn.x - mm.x) , (nn.y - mm.y));
}

int main()
{
    long long n, m;

    cout.precision(3);
    cout.setf(ios::fixed | ios::showpoint);

    while (cin >> n >> m)
        cout << calDistance(n, m) << endl;

    return 0;
}
