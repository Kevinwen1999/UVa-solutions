#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define EPS 1e-9
using namespace std;
int N, M;
vector <int> house;
int main()
{
    ios::sync_with_stdio(0);
    int cse; cin>>cse;
    while (cse--)
    {
        cin>>N>>M;
        house.clear();
        for (int i = 0, x; i < M; i++)
        {
            cin>>x;
            house.push_back(x);
        }
        sort(house.begin(), house.end());
        double l = 0, h = 1.0*house[house.size()-1], diameter, cover, minn = 999999999.0, maxx = 0.0;
        int used;
        while (fabs(l-h)>EPS)
        {
            diameter = (l+h) /2;
            cover = -1.0; used = 0; maxx = diameter / 2;
            for (int i = 0; i < M; i++)
            {
                if (house[i] > cover)
                {
                    used++;
                    cover = house[i] + diameter;
                }
            }
            if (used <= N)
            {
                h = diameter;
                minn = min(minn, maxx);
            }
            else
                l = diameter;
        }
        printf("%.1lf\n", minn);
    }
}
