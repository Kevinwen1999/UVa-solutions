#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;
int N,temp,M,lef,beg,ans,cnt = 0;
vector <int> ary;
int dif = 999999999;
int main()
{
    //ofstream myfile;
    //myfile.open ("example.txt");
    cin>>N;
    while (!cin.eof())
    {
        dif = 999999999;
        //if (cnt)cout<<endl;
        ary.clear();
        for (int i = 0 ; i < N;i++)
        {
            cin>>temp;
            ary.push_back(temp);
        }
        cin>>M;
        sort(ary.begin(),ary.end());
        for (int i = 0; i < N; i++)
        {
            lef = M-ary[i];
            if (binary_search(ary.begin(),ary.end(),lef)&&abs(ary[i]-lef)<dif)
                {
                    dif = abs(ary[i]-lef);
                    ans = lef;
                    beg = ary[i];
                }
        }
        cout<<"Peter should buy books whose prices are "<<((beg<ans)?beg:ans)<<" and "<<((beg>ans)?beg:ans)<<"."<<endl;
        cout<<endl;
        cin>>N;
    }
    //myfile.close();
    return 0;
}
