#include <iostream>
using namespace std;
int k, S[20];
bool cnt = 0;
int main()
{
    while (1)
    {
        cin>>k;
        if (k==0)break;
        if (cnt==1)cout<<endl;
        cnt = 1;
        for (int i = 0 ; i < k; i++)cin>>S[i];
        for (int i = 0 ; i < k-5; i++)
            for (int j = i+1 ; j < k-4; j++)
                for (int l = j+1 ; l < k-3; l++)
                    for (int m = l+1; m < k-2; m++)
                        for (int n = m+1; n < k-1; n++)
                            for (int o = n+1; o < k; o++)
                                cout<<S[i]<<" "<<S[j]<<" "<<S[l]<<" "<<S[m]<<" "<<S[n]<<" "<<S[o]<<endl;
    }
}
