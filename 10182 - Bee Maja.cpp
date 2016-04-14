#include <iostream>
using namespace std;

int main()
{
    int N,fin,inc,x,y,cycle;
    while(cin>>N)
    {
        if (N==1) {cout<<"0 0"<<endl;continue;}
        fin = 1;inc = 6,cycle = 0;
        while(1)
        {
            if (fin>=N) break;
            fin+=inc;
            inc+=6;
            cycle++;
        }
        x = cycle; y = 0;
        if (fin==N) {cout<<x<<" "<<y<<endl;continue;}
        bool done = false;
        for (int i = 0; i < cycle; i++)
        {
            y--;
            fin--;
            if (fin==N) {cout<<x<<" "<<y<<endl; done = true; break;}
        }
        if (done) continue;
        for (int i = 0; i < cycle; i++)
        {
            x--;
            fin--;
            if (fin==N) {cout<<x<<" "<<y<<endl; done = true; break;}
        }
        if (done) continue;
        for (int i = 0; i < cycle; i++)
        {
            x--; y++;
            fin--;
            if (fin==N) {cout<<x<<" "<<y<<endl; done = true; break;}
        }
        if (done) continue;
        for (int i = 0; i < cycle; i++)
        {
            y++;
            fin--;
            if (fin==N) {cout<<x<<" "<<y<<endl; done = true; break;}
        }
        if (done) continue;
        for (int i = 0; i < cycle; i++)
        {
            x++;
            fin--;
            if (fin==N) {cout<<x<<" "<<y<<endl; done = true; break;}
        }
        if (done) continue;
        for (int i = 0; i < cycle-1; i++)
        {
            x++; y--;
            fin--;
            if (fin==N) {cout<<x<<" "<<y<<endl; done = true; break;}
        }
        if (done) continue;
    }
}
