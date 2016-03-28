#include <iostream>
using namespace std;
int main()
{
    int N , B , H, W, minx ;
    while (scanf("%d%d%d%d", &N,&B,&H,&W)!=EOF)
    {
        minx = 9999999;
        for (int i = 0 ; i < H; i++)
        {
            int price;
            cin>>price;
            for (int j = 0 ; j < W; j++)
            {
                int bed;
                cin>>bed;
                if ((bed>=N)&&(price*N<minx)&&(price*N<=B))
                {minx = price*N;}
            }
        }
        if (minx == 9999999)
            {cout<<"stay home"<<endl;}
        else
            {cout<<minx<<endl;}
    }
}
