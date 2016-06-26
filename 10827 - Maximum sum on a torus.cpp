#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int T;
int N;
int grid[77*2][77*2];
int main()
{
    cin>>T;
    while (T--)
    {
        cin>>N;
        for (int i = 0 ; i < N; i++)
            for (int j = 0  ; j < N; j++)
                cin>>grid[i][j], grid[i][j+N] = grid[i+N][j] = grid[i+N][j+N] = grid[i][j];
        for (int i =0; i < N*2; i++)
            for (int j = 0 ; j < N*2; j++)
            {
                if (i > 0) grid[i][j] += grid[i-1][j];
                if (j > 0) grid[i][j] += grid[i][j-1];
                if (i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
            }
        int maxx = -9999999;
        for (int i = 0; i < N; i++)
            for (int j = 0 ; j < N; j++)
                for (int k = i; k < i+N; k++)
                    for (int l = j; l < j + N; l++)
                    {
                        int sum = grid[k][l];
                        if (i > 0) sum -= grid[i-1][l];
                        if (j > 0) sum -= grid[k][j-1];
                        if (i > 0 && j > 0) sum += grid[i-1][j-1];
                        maxx = max(maxx, sum);
                    }
        cout<<maxx<<"\n";
    }
}
