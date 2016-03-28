#include <iostream>
#include <queue>
using namespace std;
int N;
int main()
{
    while(1)
    {
        cin>>N;
        if (N==0) break;
        priority_queue <int, vector<int>, greater<int> > q;
        for (int i = 0,temp ; i < N; i++)
        {
            cin>>temp;
            q.push(temp);
        }
        int ans = 0;
        for (int i = 0,a,b,sum ; i < N-1; i++)
        {
            a = q.top();
            q.pop();
            b = q.top();
            q.pop();
            sum = a + b;
            ans+=sum;
            q.push(sum);
        }
        cout<<ans<<endl;
    }
}
