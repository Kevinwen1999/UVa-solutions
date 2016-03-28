#include <iostream>
#include <cmath>
using namespace std;
int N;
int ary[100001];
long long ans,last;
int main()
{
  while(cin>>N&&N)
  {
      for (int i = 0 ; i < N; i++)
      {
          cin>>ary[i];
      }
      last = 0;
      ans = 0;
      for (int i = 0 ; i < N; i++)
      {
          ans+=abs(last);
          last+=ary[i];
      }
      cout<<ans<<endl;
  }
}
