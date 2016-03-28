#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
string line;
stringstream ss;
vector <int> pancake, need;
int N,cnt,cur,pos;
int main()
{
    while(getline(cin,line))
    {
        if (cnt!=0) cout<<endl;
        cnt++;
        ss.clear();
        pancake.clear();
        need.clear();
        ss.str(line);
        while(ss>>N)
        {
            pancake.push_back(N);
            need.push_back(N);
        }
        for (int i = 0 ; i < pancake.size(); i++)
            cout<<pancake[i]<<" ";
        cout<<endl;
        sort(need.begin(),need.end());
        reverse(need.begin(),need.end());
        reverse(pancake.begin(),pancake.end());
        for (int i = 0 ; i < need.size(); i++)
        {
            cur = need[i];
            if (pancake[i]==cur) continue;
            vector <int>:: iterator it;
            it = find(pancake.begin(),pancake.end(),cur);
            pos = it - pancake.begin();
            if (pos!=pancake.size()-1)
            {
                reverse(pancake.begin()+pos, pancake.end());
                cout<<pos+1<<" ";
            }
            reverse(pancake.begin()+i, pancake.end());
            cout<<i+1<<" ";
        }
        cout<<0;
    }
}
