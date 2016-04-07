#include <iostream>
#include <deque>
#include <cmath>
using namespace std;
int N;
int main()
{
    while(true)
    {
        cin >> N;
        if (N == 0) break;
        /*deque<int> d;
        for (int i = 1; i <= N; i++) {
            d.push_front(i);
        }
        deque<int>::iterator it;
        while(d.size() > 1){
            d.pop_back();
            d.push_front(d.back());
            d.pop_back();
            //for (it = d.begin(); it != d.end(); it++)
                //cout<<*it<<" ";
            //cout<<endl;
        }
        it = d.begin();
                cout << *it << endl;
        */
        if (N==1)
        {
            cout<<1<<endl;
            continue;
        }
        int x = 1,up;
        while(1)
        {
            up = pow(2,x);
            if (up>=N)
            {
                cout<<up - 2*(up-N)<<endl;
                break;
            }
            x++;
        }
    }
}
