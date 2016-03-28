#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int N,M;
int main()
{
    while(1)
    {
        cin>>N>>M;
        if (cin.eof()) break;
        vector <int> buff;
        for (int i = 0,a ; i < N; i++)
        {
            cin>>a;
            buff.push_back(a);
        }
        int ans;
        int left = 1; int right = 1000000000;
        for (int i = 0 ; i < 50; i++)
        {
            bool possible = true;
            int cursum = 0;
            int jarused = 1;
            int mid = (right+left)/2;
            for (int j = 0 ; j < buff.size(); j++)
            {
                cursum+=buff[j];
                if (cursum>mid)
                {
                    jarused++;
                    cursum = buff[j];
                    if (jarused>M||cursum>mid)
                    {
                        possible = false;
                        break;
                    }
                }
            }
            if (!possible)
            {
                left = mid;
            }
            else
            {
                ans = mid;
                right = mid;
            }
        }
        cout<<ans<<endl;
    }
}
