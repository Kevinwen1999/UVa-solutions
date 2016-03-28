#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int M, N;
string in;
char graph[110][110];
int visited[110][110];
int cnt = 0;
void dfs(int i, int j)
{
    if (i<0||j<0||i>=M||j>=N)
        return;
    if (graph[i][j]!='@'||visited[i][j]!=0)
        return;
    visited[i][j] = cnt;
    for (int a = -1; a <=1; a++)
        for (int b = -1; b <= 1; b++)
            if (a!=0||b!=0)  dfs(i+a,j+b);
}
int main()
{
   while(1)
   {
       cin>>M>>N;
       if (M==0&&N==0) break;
       memset(visited,0,sizeof visited);
       for (int i = 0 ; i < M; i++)
       {
          cin>>in;
          for (int j = 0 ; j < N; j++)  graph[i][j] = in[j];
       }
       cnt = 0;
       for (int i = 0 ; i < M; i++)
           for (int j = 0 ; j < N; j++)
               if (!visited[i][j]&&graph[i][j]=='@')
               {
                   cnt++;
                   dfs(i,j);
               }
        cout<<cnt<<endl;
   }
}
