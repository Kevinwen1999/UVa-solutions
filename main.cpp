#include <iostream>
using namespace std;
int n,m;
char grid[1001][1001];
int visited[1001][1001];
int cnt = 1;
void dfs(int i,int j)
{
    if (visited[i][j]==0)
    {
        if (grid[i][j]=='S'&&i+1>=0&&j>=0&&i+1<n&&j<m)
        {
            if (visited[i+1][j]==0)
            {
                cnt+=1;
                visited[i][j] = cnt;visited[i+1][j] = cnt;
                dfs(i+1,j);
            }
            else
                visited[i][j] = visited[i+1][j];
        }
        else if (grid[i][j]=='N'&&i-1>=0&&j>=0&&i-1<n&&j<m)
        {
            if (visited[i-1][j]==0)
            {
                cnt+=1;
                visited[i][j] = cnt;visited[i-1][j] = cnt;
                dfs(i-1,j);
            }
            else
                visited[i][j] = visited[i-1][j];
        }
        else if (grid[i][j]=='W'&&i>=0&&j-1>=0&&i<n&&j-1<m)
        {
             if (visited[i][j-1]==0)
            {
                cnt+=1;
                visited[i][j] = cnt;visited[i][j-1] = cnt;
                dfs(i,j-1);
            }
            else
                visited[i][j] = visited[i][j-1];
        }
        else if (grid[i][j]=='E'&&i>=0&&j+1>=0&&i<n&&j+1<m)
        {
            if (visited[i][j+1]==0)
            {
                cnt+=1;
                visited[i][j] = cnt;visited[i][j+1] = cnt;
                dfs(i,j+1);
            }
            else
                visited[i][j] = visited[i][j+1];
        }
    }
    else
    {
        if (grid[i][j]=='S'&&i+1>=0&&j>=0&&i+1<n&&j<m)
        {
            if (visited[i+1][j]==0)
            {
                visited[i+1][j] = visited[i][j];
                dfs(i+1,j);
            }
        }
        else if (grid[i][j]=='N'&&i-1>=0&&j>=0&&i-1<n&&j<m)
        {
            if (visited[i-1][j]==0)
            {
                visited[i-1][j] = visited[i][j];
                dfs(i-1,j);
            }
        }
        else if (grid[i][j]=='W'&&i>=0&&j-1>=0&&i<n&&j-1<m)
        {
           if (visited[i][j-1]==0)
            {
                visited[i][j-1] = visited[i][j];
                dfs(i,j-1);
            }
        }
        else if (grid[i][j]=='E'&&i>=0&&j+1>=0&&i<n&&j+1<m)
        {
            if (visited[i][j+1]==0)
            {
                visited[i][j+1] = visited[i][j];
                dfs(i,j+1);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for (int i = 0 ;  i < n; i++)
        {
            string line; cin>>line;
            for (int j = 0 ; j < m; j++)
            grid[i][j] = line[j];
        }
    visited[0][0] = 1;
    dfs(0,0);
    for (int i = 0 ; i < n; i++)
    {
        for (int j = 0 ; j < m; j++)
        {
            if (visited[i][j]==0)
            {
                dfs(i,j);
            }
        }
    }
    /*for (int i = 0 ; i < n; i++)
    {
        for (int j = 0 ; j < m; j++)
            cout<<visited[i][j];
        cout<<endl;
    }*/
    cout<<cnt<<endl;
    return 0;
}
