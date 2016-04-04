#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int N, table[1050][1050];
int main()
{
    while (cin>>N && !cin.eof())
    {
        string temp;
        for (int i = 0 ; i < N; i++)
        {
            cin>>temp;
            for (int j = 0 ; j < N; j++)
                table[i][j] = temp[j] - '0';
        }
        vector <int> win, lose;
        for (int i = 1; i < N; i++)
        {
            if (table[0][i]==1)
                win.push_back(i);
            else
                lose.push_back(i);
        }
        int T = N;
        while(1)
        {
            if (T==1) break;
            //stage-1 kill black
            vector <int> w2,l2,fin;
            bool match;
            for (int i = 0 ; i < lose.size(); i++)
            {
                int black = lose[i];
                match = false;
                for (int j = 0 ; j < win.size(); j++)
                {
                    int &gray = win[j];
                    if (gray > 0 && table[gray][black] > 0)
                    {
                        cout<<black + 1<<" "<<gray + 1<<endl;
                        match = true;
                        w2.push_back(gray);
                        gray = 0;
                        break;
                    }
                }
                if (!match)
                    fin.push_back(black);
            }
            // stage-2 find opponent for 1
            match = false;
            int cur;
            for (int i = 0 ; i < win.size(); i++)
            {
                cur = win[i];
                if (cur > 0)
                {
                    if (!match)
                    {
                        cout<<"1 "<<cur+1<<endl;
                        match = true;
                    }
                    else
                        fin.push_back(cur);
                }
            }
            // stage-3 deal of the rest
            int survive;
            for (int i = 0 ;i < fin.size(); i+=2)
            {
                cout<<fin[i] + 1<<" "<<fin[i+1]+1<<endl;
                if (table[fin[i]][fin[i+1]] > 0)
                    survive = fin[i];
                else
                    survive = fin[i+1];
                if (table[0][survive]>0)
                    w2.push_back(survive);
                else
                    l2.push_back(survive);
            }
            win = w2;
            lose = l2;
            T/=2;
        }
    }
}
