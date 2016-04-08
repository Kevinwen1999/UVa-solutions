#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int MAXN = 1000 + 10;
char s[MAXN][MAXN];
int height[MAXN], ans[MAXN << 1];
struct Rect
{
    int c, h;
    Rect(int cc = 0 , int hh = 0 )
    {
        c = cc;
        h = hh;
    }
}rect[MAXN];
int N, M;
string temp;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        for (int i = 0; i < N; i++)
        {
            cin>>temp;
            for (int j = 0; j < M; j++)
                s[i][j] = temp[j];
        }
        memset(height, 0, sizeof height);
        memset(ans, 0, sizeof ans);
        for (int i = 0 ; i < N; i++)
        {
            int top = -1;
            for (int j = 0 ; j < M; j++)
            {
                if (s[i][j] == '#')
                {
                    top = -1;
                    height[j] = 0;
                }
                else
                {
                    height[j]++;
                    Rect r(j, height[j]);
                    if (top < 0)
                        rect[++top] = r;
                    else
                    {
                        while(top >= 0 && rect[top].h >= r.h)
                            r.c = rect[top--].c;
                        if (top < 0 || r.h - r.c > rect[top].h - rect[top].c)
                            rect[++top] = r;
                    }
                    r = rect[top];
                    ans[r.h + j - r.c + 1]++;
                }
            }
        }
        for (int i = 2 ; i <= M + N ; i++)
            if (ans[i])
                cout<<ans[i]<<" x "<<i*2<<endl;
    }
}
