#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;
string in;
int N,temp;
long long dist[20][20];
long long recur(int i, int j)
{
    if (i >= N || j>= N) return 0;
    if (dist[i][j]==-2) return 0;
    if (dist[i][j]!=-1) return dist[i][j];
    if (j==N-1) return dist[i][j] = 1;
    long long &ans = dist[i][j] = 0;
    for (int a = 0 ; a < in.size(); a++)
    {
        if (a==i+1||a==i-1||a==i)
            continue;
        else
            ans+=recur(a,j+1);
    }
    return ans;
}
int main()
{
    while(cin>>in)
    {
        N = in.size();
        memset(dist,-1,sizeof dist);
        for (int i = 0 ; i < in.size(); i++)
        {
            if (isdigit(in[i]))
            {
                temp = in[i] - '0';
                for (int j = 0; j < in.size(); j++)
                    dist[j][i] = -2;
                dist[temp-1][i] = -1;
            }
            else if (in[i]!='?')
            {
                temp = in[i] - 'A' + 10;
                for (int j = 0; j < in.size(); j++)
                    dist[j][i] = -2;
                dist[temp-1][i] = -1;
            }
        }
        long long total = 0;
        for (int i = 0 ; i < in.size(); i++)
            total+=recur(i,0);
        cout<<total<<"\n";
    }
}
