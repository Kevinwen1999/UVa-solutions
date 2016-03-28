#include <iostream>
#include <vector>

using namespace std;
int track[30];
int N, nt, bestsum;
vector <int> bestpath;
void dfs(vector <int> path, int sum, int index)
{
    sum+=track[index];
    path.push_back(track[index]);
    if (sum>bestsum||sum==bestsum&&path.size()>bestpath.size())
    {
        bestsum = sum;
        bestpath = path;
    }
    for (int i = index + 1; i < nt; i++)
        if (sum+track[i]<=N)
            dfs(path, sum , i);

}
int main()
{
    while (cin>>N>>nt)
    {
        for (int i = 0 ; i < nt; i++)
            cin>>track[i];
        bestsum = 0; bestpath.clear();
        for (int i = 0 ; i < nt; i++)
        {
            vector <int> path;
            dfs(path,0,i);
        }
        for(int j = 0; j < (int) bestpath.size(); j++)
            cout<<bestpath[j]<<" ";
        cout<<"sum:"<<bestsum<<endl;
    }
}
