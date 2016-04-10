#include <cstring>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
double R, W[10], ans, val[100],l[100],r[100];
int S;
int t[100], visited[10];
void cal(int cur)
{
    memset(val,0,sizeof val);
    memset(l,0,sizeof l);
    memset(r,0,sizeof r);
    for (int i = cur; i > 0; i--) // from leaves to root
    {
        if (t[i] == -1) // cur node is a balance
        {
            int left = i*2, right = i*2+1; // binary tree child index;
            val[i] = val[left] + val[right]; // sum of weights from left child and right
            double L = val[right] / val[i];
            double R = val[left] / val[i];  // stores the current left and right bridge length , l[i] stores the current max left extend (negative). read the problem to understand the dividing
            l[i] = min(-L + l[left], R + l[right]);
            r[i] = max(-L + r[left], R + r[right]);
        }
        else if (t[i]!=0) // it's a single stone;
        {
            val[i] = W[t[i]];
        }
    }
    double width = r[1] - l[1]; // the total width;
    if (width - R < 1e-5 && width > ans) ans = width;
}
void dfs(int cur, int slot, int remain)
{
    if (remain == 0)
    {
        cal(cur - 1);
        return;
    }
    if (t[cur / 2] != -1) // cannot use this slot (father is a single stone), skip
    {
        dfs(cur + 1, slot, remain);
    }
    else
    {
        if (remain > slot) // can put a balance
        {
            t[cur] = -1;
            dfs(cur + 1, slot + 1, remain);
            t[cur] = 0;
        }
        if (slot == 1 && remain > 1) return; // infeasible, there are no enough slot to put stones
        for (int i = 1; i <= S; i++) // use cur to put one stone
        {
            if (!visited[i]) // not-used stone
            {
                visited[i] = true; t[cur] = i;
                dfs(cur + 1, slot - 1, remain - 1);
                visited[i] = false; t[cur] = 0; //set it back;
            }
        }
    }
}

int main()
{
    int Test;
    cin>>Test;
    while(Test--)
    {
        memset(t,0,sizeof t);
        memset(visited,0,sizeof visited);
        cin>>R>>S;
        for(int i = 1 ; i <= S; i++)
            cin>>W[i];
        if (S == 1) {  printf("%.10lf\n", 0.0); continue;}
        t[1] = -1;
        ans = -1;
        dfs(2,2,S);
        if (ans == -1) printf("-1\n");
        else printf("%.10lf\n", ans);
    }
}
