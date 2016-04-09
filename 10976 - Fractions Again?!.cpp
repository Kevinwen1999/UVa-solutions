#include <iostream>
#include <utility>
#include <vector>
#include <cstdio>
using namespace std;
int k;
vector <pair <int,int> > all;
int main()
{
    while(scanf("%d", &k)==1)
    {
        int tot = 0;
        all.clear();
        for (int i = k+1; i <= 2*k; i++)
        {
            if (i*k % (i-k) == 0)
            {
                tot++;
                all.push_back(make_pair((i*k)/(i-k),i));
            }
        }
        printf("%d\n",tot);
        for (int i = 0 ; i < all.size(); i++)
            printf("1/%d = 1/%d + 1/%d\n", k,all[i].first, all[i].second);
    }
}
