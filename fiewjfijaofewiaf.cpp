#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
long long ori, nbase;
long long  bases[10000];
string curbase ;
long long  curnum;
long long dic(long long number, long long  base)
{
    queue <long long > buff;
    while (number!=0)
    {
        buff.push(number%base);
        number/=base;
    }
    long long result = 0;
    int place = 1;
    while (!buff.empty())
    {
        result += buff.front()*place;
        buff.pop();
        place*=10;
    }
    return result;
}

int main()
{
    cin>>ori>>nbase;
    for (int i = 0 ; i < nbase; i++)
        cin>>bases[i];
    curnum = bases[nbase-1];
    for (int i = nbase-2; i>=0; i--)
    {
        curnum = dic(bases[i],curnum);
    }
    curnum = dic(ori,curnum);
    cout<<curnum;
}
