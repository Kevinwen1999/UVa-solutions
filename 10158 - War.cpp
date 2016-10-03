#include <iostream>
using namespace std;
int N;
const int MAXN = 200010;
int p[MAXN], rnk[MAXN];
void init(int N)
{
    for (int i = 0; i <= N; i++)
        p[i] = i, rnk[i] = 1;
}
int findp(int x)
{
    return p[x] == x ? x : (p[x] = findp(p[x]));
}
bool sameset(int x, int y)
{
    return findp(x) == findp(y);
}
void mergeset(int x, int y)
{
    if (!sameset(x, y))
    {
        x = findp(x), y = findp(y); // EXTREMELY IMPORTANT !!!!!!!!!
        if (rnk[x] > rnk[y])
            rnk[x] += rnk[y], p[y] = x;
        else
            rnk[y] += rnk[x], p[x] = y;
    }
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    while (cin>>N)
    {
        init(2*N); // first N is for friend set and second N is for enemy set
        int opcode, x, y;
        while (1)
        {
            cin>>opcode>>x>>y;
            if (!(opcode+x+y)) break;
            int fx = findp(x), ex = findp(x+N);
            int fy = findp(y), ey = findp(y+N);
            switch (opcode)
            {
            case 1:
                if (fx == ey) cout<<"-1\n";
                else
                {
                    mergeset(fx,fy);
                    mergeset(ex,ey);
                }
                break;
            case 2:
                if (fx == fy) cout<<"-1\n";
                else
                {
                    mergeset(fx,ey);
                    mergeset(fy,ex);
                }
                break;
            case 3:
                if (fx == fy) cout<<"1\n";
                else cout<<"0\n";
                break;
            case 4:
                if (fx == ey) cout<<"1\n";
                else cout<<"0\n";
                break;
            }
        }

    }
}
