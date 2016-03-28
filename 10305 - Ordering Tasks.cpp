#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int adj[110][110];
int V , E;

vector<int> topological_sort()
{
	vector<int> result;
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
        visited[i] = false;
	while (true)
    {
		bool allVisited = true;
		for (int i = 0; i < V; i++)
            allVisited = allVisited & visited[i];
		if (allVisited) return result;
		vector<int> inDegree;
		for (int i = 0; i < V; i++)
        {
			if (!visited[i])
			{
				int indeg = 0;
				for (int j = 0; j < V; j++)
					if (!visited[j] && adj[j][i])
                        indeg += 1;
				if (indeg == 0) inDegree.push_back(i);
			}
		}
		sort(inDegree.begin(), inDegree.end());
		if (inDegree.empty())
        {
			vector<int> e;
			return e;
		}
		for (int i = 0; i < inDegree.size(); i++)
        {
			int cur = inDegree[i];
			visited[cur] = true;
			for (int j = 0; j < V; j++)
            {
				adj[cur][j] = 0;
				adj[j][cur] = 0;
			}
			result.push_back(cur);
		}
	}
}

int main()
{
    while (1)
    {
        cin>>V>>E;
        if (V==0 && E ==0) break;
        for (int i = 0 ; i < E; i++)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a][b] = 1;
        }
        vector<int> result = topological_sort();
        for (int n = 0; n < result.size(); n++)
            cout << result[n] + 1 <<" ";
        cout<<endl;
    }
}
