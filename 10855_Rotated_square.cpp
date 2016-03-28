#include <iostream>
#include <string>
using namespace std;
int bd, sd;
char bs[500][500], ss[500][500];
int main()
{
    while (1)
    {
        cin>>bd>>sd;
        if (bd==0&&sd==0)
            break;
        for (int i = 0 ; i < bd; i++)
        {
            string line;
            cin >> line;
            for (int j = 0 ; j < bd; j++)
            {
                bs[i][j]=line[j];
            }
        }
        for (int i = 0 ; i < sd; i++)
        {
            string line;
            cin >> line;
            for (int j = 0 ; j < sd; j++)
            {
                ss[i][j]=line[j];
            }
        }
        for (int rot = 0 ; rot < 4 ; rot++)
        {
            int times = 0;
            for (int i = 0 ; i <bd; i++)
            {
                for (int j = 0 ; j<bd; j++)
                {
                    bool istrue = true;
                    for (int k = 0 ;k < sd; k++)
                    {
                        for (int l = 0 ; l <sd; l++)
                        {
                            if (i + k >= bd || j + l >= bd){
                                istrue = false;
                                break;
                            }

                            if (bs[i+k][j+l] != ss[k][l])
                            {
                                istrue = false;
                                break;
                            }
                        }
                    }
                    if (istrue)
                        {times++;}
                }
            }
            if (rot > 0) cout << " ";
            cout<<times;

            char temp[500][500];
            for (int i = 0  ; i  < sd; i++)
            {
                for (int j = 0 ; j < sd; j++)
                {
                    temp[i][j] = ss[sd-1-j][i];
                }
            }
            for (int i = 0; i < sd; i++)
            {
                for (int j = 0 ; j  < sd; j++)
                {
                    ss[i][j]= temp[i][j];
                }
            }
        }
        cout<<endl;
    }
}
