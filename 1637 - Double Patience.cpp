#include <iostream>
#include <vector>
#include <map>
using namespace std;

char card[9][4][3];
map<vector<int>, double> state;
double dp (vector <int> & cur, int cnt)
{
    if (cnt == 0) return 1; // no cards remain, 100% victory
    if (state.count(cur) != 0) return state[cur]; // dp
    double sum = 0; // total posibility
    int tot = 0; // total number of state
    for (int i = 0; i < 9; i++)
    {
        if (cur[i] > 0) // cards remain on this pile
            for (int j = i + 1; j < 9; j++)
            {
                if (cur[j] > 0)
                {
                    if (card[i][cur[i]-1][0] == card[j][cur[j]-1][0])
                    {
                        tot++;
                        cur[i]--; cur[j]--;
                        sum += dp(cur, cnt-2);
                        cur[i]++; cur[j]++;
                    }
                }
            }
    }
    if (tot==0) return state[cur] = 0;
    return state[cur] = sum / tot;
}
bool read()
{
    for(int i = 0; i < 9; ++i)
        for(int j = 0; j < 4; ++j)
            if(scanf("%s", card[i][j]) != 1)
                return false;
    return true;
}
int main()
{
    while(read())
    {
        state.clear();
        vector <int> cnt(9,4);
        printf("%.6f\n", dp(cnt, 36));
    }
}
