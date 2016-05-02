#include <bits/stdc++.h>

using namespace std;
const int MAXN = 30 + 10;
const int MAXV = 6000 + 10;
int sig[MAXN];
int number[MAXN];
int N;
bool visited[MAXN][MAXN][MAXV];
bool used[MAXV];
void dfs(int idx, int open, int val) // current index, number of open bracket, value till now
{
    if (visited[idx][open][val])
        return;
    visited[idx][open][val] = true;
    if (idx==N)
    {
        used[val + 3000] = true; //offset technique
        return;
    }
    int nval = val + number[idx] * sig[idx] * ((open % 2 ==0) ? 1 : -1); //value to pass down
    if (sig[idx] == -1) // current sign is negative, can put a open bracket
        dfs(idx+1, open + 1, nval);
    if (open > 0) //can close a bracket
        dfs(idx+1, open -1, nval);
    dfs(idx+1, open, nval); //do nothing
}
int main()
{
    string in;
    while (getline(cin,in))
    {
        stringstream ss(in);
        number[0] = in[0];
        sig[0] = 1;
        int idx = 0, num;
        char sign;
        N = 1;
        ss>>num;
        while(ss>>sign>>num)
        {
            idx++; N++;
            sig[idx] = (sign == '+' ? 1 : -1);
            number[idx] = num;
        }
        memset(visited,0,sizeof visited);
        memset(used,0,sizeof used);
        dfs(0,0,0);
        int cnt = 0;
        for (int i = 0; i < MAXV; i++)
            if (used[i]) cnt++;
        cout<<cnt<<"\n";
    }
}
