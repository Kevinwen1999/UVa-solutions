#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int T, m , k;
vector <int> books;
bool flag[510];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>m>>k;
        books.clear();
        int singlemax = 0;
        long long sum = 0;
        for (int i = 0,in; i < m ;i++)
        {
            cin>>in;
            books.push_back(in);
            singlemax = max(singlemax,in);
            sum+=in;
        }
        //sort(books.begin(),books.end());
        long long  L = singlemax, R = sum, mid;
        long long ans;
        while(L < R)
        {
            mid = L + (R-L) / 2;
            long long  turn = 1,sum = 0;
            for (int i = 0 ; i <m; i++)
            {
                if (sum + books[i] > mid)
                {
                    sum = 0;
                    turn++;
                    sum = books[i];
                }
                else
                {
                    sum += books[i];
                }
            }
            if (turn > k)
            {
                L = mid + 1;
            }
            else
            {
                ans = mid;
                R = mid;
            }
        }
        long long  he = 0;
        long long  people = 0;
        memset(flag,0,sizeof flag);
        for (int i = m-1 ; i >=0; i--)
        {
            if (he + books[i] <= ans && i >= k - people -1)
            {
                he+=books[i];
            }
            else
            {
                he = books[i];
                people++;
                if (people < k) flag[i] = 1;
            }
        }
        cout<<books[0];
        if (flag[0]) cout<<" /";
        for (int i = 1 ; i < m; i++)
        {
            cout<<" "<<books[i];
            if (flag[i])
                cout<<" /";
        }
        cout<<endl;
    }
}
