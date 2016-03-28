#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;
int N,ne;
long long v1[4010],v2[4010],v3[4010],v4[4010];
unordered_map <long long,int> sum;
int main()
{
    cin>>N;
    while(N--)
    {
        cin>>ne;
        sum.clear();
        for (int i = 0;i < ne; i++)
            cin>>v1[i]>>v2[i]>>v3[i]>>v4[i];
        long long s; int tot = 0;
        for (int i = 0; i < ne; i++)
            for (int j = 0 ; j < ne; j++)
            {
                s = v1[i]+v2[j];
                if (sum.count(s)>0)
                    sum[s]++;
                else
                    sum[s] = 1;
            }
        for (int i = 0; i < ne; i++)
            for (int j = 0 ; j < ne; j++)
            {
                s = -(v3[i]+v4[j]);
                if (sum.count(s)>0)
                    tot+=sum[s];
                else
                    continue;
            }
        cout<<tot;
        cout<<endl;
        if(N)
            puts("");
    }
}
