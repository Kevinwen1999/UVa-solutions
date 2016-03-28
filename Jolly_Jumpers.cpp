#include <iostream>
#include <cmath>
using namespace std;
int buff[3050];
bool flags[999999];
int main()
{
    int N;
    while (scanf("%d", &N)!=EOF)
    {
        bool isj = true;
        for (int i = 0 ; i < 3050; i++)
            flags[i] = false;
        for (int i = 0 ; i < N; i++)
            cin>>buff[i];
        for (int i = 0 ; i < N-1; i++)
        {
            int diff = abs(buff[i] - buff[i+1]);
            flags[diff] = true;
        }
        for (int i = 1 ; i <= N-1; i++)
        {
            if (flags[i]==false)
            {
                isj = false;
                break;
            }
        }
        if (N==1||isj == true)
            cout<<"Jolly"<<endl;
        else
            cout<<"Not jolly"<<endl;

    }
    return 0;
}
