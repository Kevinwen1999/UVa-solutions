#include <iostream>
using namespace std;

int main()
{
    int ncows, ncars, nshow;
    double p1, p2;
    while(cin>>ncows>>ncars>>nshow)
    {
        // First case: the player choose a door with cows
        p1 = 1.0 * ncows / (ncars+ncows) * ncars / (ncars + ncows - 1 - nshow);
        // Second case: the player choose a door with car
        p2 = 1.0 * ncars / (ncars+ncows) * (ncars-1) / (ncars - 1 + ncows - nshow);
        printf("%.5lf\n", p1+p2);
    }
}
