#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int V;
int adj[101][101];
bool visited[101], visited1[101];
void dfs(int i)
{
    visited[i] = true;
    for (int j = 0 ; j < V; j++)
    {
        if (adj[i][j] == 1&&visited[j] == false)
            dfs(j);
    }
}
void dfs (int i , int target)
{
    if (i!=target)
    {
        visited1[i] = true;
        for (int j = 0 ; j < V; j++)
        {
            if (adj[i][j] == 1&&visited1[j] == false&&j!=target)
            dfs(j,target);
        }
    }
}
int main()
{
    int N;
    cin>>N;
    for (int cnt = 1; cnt <= N; cnt++)
    {
        cin>>V;
        for (int i = 0 ; i < V; i++)
        {
            visited[i] = false;
            visited1[i] = false;
            for (int j = 0 ; j < V; j++)
            {
                cin>>adj[i][j];
            }
        }
        cout<<"Case "<<cnt<<":"<<endl;
        cout<<"+";
        for (int i = 0 ; i < 2*V-1; i++)
            cout<<"-";
        cout<<"+"<<endl<<"|";
        dfs(0);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0 ; j < V; j++)
                visited1[j] = false;
            dfs(0,i);
            for (int j = 0 ; j < V; j++)
            {
                if (visited[j] == true && visited1[j] == false)
                    cout<<"Y"<<"|";
                else
                    cout<<"N"<<"|";
            }
            cout<<endl<<"+";
            for (int i = 0 ; i < 2*V-1; i++)
                cout<<"-";
            cout<<"+"<<endl;
            if (i!=V-1)
                cout<<"|";
        }
    }
    return 0;
}
