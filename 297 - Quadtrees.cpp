#include <bits/stdc++.h>
using namespace std;
string t1, t2;
int buf[33][33], tot;
int ptr, len = 32;
void gen(string & t, int r, int c, int w)
{
    char ch = t[ptr++];
    if (ch=='p')
    {
        gen(t,r,c+w/2,w/2);
        gen(t,r,c,w/2);
        gen(t,r+w/2,c,w/2);
        gen(t,r+w/2,c+w/2,w/2);
    }
    else if (ch=='f')
    {
        for (int i = r; i < r+w; i++)
        {
            for (int j = c; j < c+w; j++)
            {
                if (!buf[i][j])
                    buf[i][j] = 1, tot++;
            }
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        cin>>t1>>t2;
        tot = 0;
        memset(buf,0,sizeof buf);
        ptr = 0;
        gen(t1,0,0,len);
        ptr = 0;
        gen(t2,0,0,len);
        printf("There are %d black pixels.\n", tot);
    }
}
