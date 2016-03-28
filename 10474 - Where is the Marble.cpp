#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, Q;
int main()
{
    for (int cnt = 1;;cnt++)
    {
        cin>>N>>Q;
        if(N==0&&Q==0) break;
        vector <int> buff;
        for (int i = 0 ,temp; i < N; i++)
        {
            cin>>temp;
            buff.push_back(temp);
        }
        sort(buff.begin(),buff.end());
        cout<<"CASE# "<<cnt<<":"<<endl;
        for (int i = 0 , query ; i < Q; i++)
        {
            cin>>query;
            if (binary_search(buff.begin(),buff.end(),query))
            {
                int lb = lower_bound(buff.begin(),buff.end(),query) - buff.begin() + 1;
                cout<<query<<" found at "<<lb<<endl;
            }
            else cout<<query<<" not found"<<endl;
        }
    }
    return 0;
}
