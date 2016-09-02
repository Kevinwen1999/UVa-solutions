#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;

const double INF = 1e30;
const int MAXN = 8, MAXM = 100+5, MAXS = 15000;

int M, N, S[MAXN], K[MAXN], TK;
double tot, price[MAXN][MAXM];
string name[MAXN];
vector <vector <int> > states;
map <vector <int>, int> id;
int buy[MAXS][MAXN], sell[MAXS][MAXN];
double dp[MAXM][MAXS];
int opt[MAXM][MAXS], parent[MAXM][MAXS];
void dfs(int stock, vector <int>& lots, int totlots)
{
    if (stock == N) // finish state calculating, store state with id
    {
        id[lots] = (int)states.size();
        states.push_back(lots);
    }
    else
    {
        for (int i = 0; i <= K[stock] && totlots + i <= TK; i++) // for wach possible lot number of current stock
        {
            lots[stock] = i;
            dfs(stock+1, lots, totlots+i);
        }
    }
}
void init()
{
    vector <int> lots(N);
    states.clear(); id.clear();
    dfs(0,lots,0);
    for (int s = 0; s < states.size(); s++)
    {
        int tlots = 0;
        for (int i = 0 ; i < N; i++) tlots += states[s][i];
        for (int i = 0 ; i < N; i++)
        {
            buy[s][i] = sell[s][i] = -1;
            if (states[s][i] < K[i] && tlots < TK) // buy this stock if possible
            {
                vector <int> news = states[s];
                news[i]++;
                buy[s][i] = id[news];
            }
            if (states[s][i] > 0)
            {
                vector <int> news = states[s];
                news[i]--;
                sell[s][i] = id[news];
            }
        }
    }
}
void update(int m, int st, int st2, double newv, int op)
{
    if (newv > dp[m+1][st2])
    {
        dp[m+1][st2] = newv;
        opt[m+1][st2] = op;
        parent[m+1][st2] = st;
    }
}
double DP()
{
    for(int i = 0; i <= M; i++)
        for(int s = 0; s < states.size(); s++) dp[i][s] = -INF;
    dp[0][0] = tot;
    for (int i = 0; i < M; i++)
    {
        for (int s = 0; s < states.size(); s++)
        {
            double v = dp[i][s];
            if (v < -1) continue;
            update(i, s, s, v, 0); // HOLD
            for (int j = 0; j < N; j++)
            {
                if(buy[s][j] >= 0 && v >= price[j][i] - 1e-3)
                    update(i, s, buy[s][j], v - price[j][i], j+1);
                if(sell[s][j] >= 0)
                    update(i, s, sell[s][j], v + price[j][i], -j-1);
            }
        }
    }
    return dp[M][0];
}
void printans(int m, int st)
{
    if (m==0) return;
    printans(m-1, parent[m][st]);
    if (opt[m][st] == 0) cout<<"HOLD\n";
    else if (opt[m][st] > 0) cout<<"BUY "<<name[opt[m][st]-1]<<"\n";
    else cout<<"SELL "<<name[-opt[m][st]-1]<<"\n";
}
int main()
{
    int cnt = 0;
    while (cin>>tot>>M>>N>>TK)
    {
        if (cnt > 0) printf("\n");
        for (int i = 0; i < N; i++)
        {
            cin>>name[i]>>S[i]>>K[i];
            for (int j = 0; j < M; j++)
            {
                cin>>price[i][j];
                price[i][j] *= S[i];
            }
        }
        init();
        double ans = DP();
        printf("%.2lf\n", ans);
        printans(M,0);
    }
    return 0;
}
