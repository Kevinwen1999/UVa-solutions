#include <bits/stdc++.h>
#define MAXN 10010
#define PI acos(-1)
using namespace std;
double r[MAXN];
int N, F;
bool check(double sz) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += floor(r[i]/sz);
    }
    return sum >= F;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &N, &F);
        F+=1;
        double LT = 0, RT = 0;
        for (int i = 0; i < N; i++) {
            scanf("%lf", &r[i]);
            r[i] = r[i]*r[i]*PI;
            RT = max(RT, r[i]);
        }
        double ans;
        while((RT-LT) > 1e-5) {
            double mid = (LT+RT)/2;
            if (check(mid)) {
                ans = mid;
                LT = mid;
            }
            else {
                RT = mid;
            }
        }
        printf("%.4lf\n", ans);
    }
}
