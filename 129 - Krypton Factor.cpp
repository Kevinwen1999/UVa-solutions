#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
int n, L;
int S[100],cnt;
int dfs(int cur)
{
    if (cnt++ == n)
    {
        for (int i = 0 ; i < cur; i++)
        {
            if (i % 64 ==0 && i > 0) printf("\n");
            else if (i % 4 == 0 && i > 0) printf(" ");
            printf("%c",'A'+S[i]);
        }
        printf("\n%d\n", cur);
        return 0;
    }
    for (int i = 0 ; i < L; i++)
    {
        S[cur] = i;
        bool OK = true;
        for (int j = 1; j*2 <= cur+1; j++)
        {
            bool same = true;
            for (int k = 0 ; k < j; k++)
            {
                if (S[cur - k] != S[cur - k - j])
                {
                    same = false;
                    break;
                }
            }
            if (same)
            {
                OK = false;
                break;
            }
        }
        if (OK)
        {
            if (!dfs(cur+1)) return 0;
        }
    }
    return 1;
}
int main()
{
    while(1)
    {
        cin>>n>>L;
        if (n==0 && L==0) break;
        cnt = 0;
        dfs(0);
    }
    return 0;
}
