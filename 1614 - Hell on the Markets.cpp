#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct node {
    int id, num, sign;
} A[MAXN];

bool cmp1(const node &p, const node &q) {
    return p.id < q.id;
}

bool cmp2(const node &p, const node &q) {
    return p.num > q.num;
}

int main() {
    int N;
    while(scanf("%d", &N) == 1) {
        int sum = 0;
        for(int i = 0; i < N; ++i) {
            scanf("%d", &A[i].num);
            A[i].id = i;
            sum += A[i].num;
        }
        if(sum & 1) {
            puts("No");
            continue;
        } else
            puts("Yes");

        sum = 0;
        sort(A, A+N, cmp2);
        for(int i = 0; i < N; ++i)
            if(sum > 0) {
                sum -= A[i].num;
                A[i].sign = -1;
            } else {
                sum += A[i].num;
                A[i].sign = 1;
            }

        sort(A, A+N, cmp1);
        printf("%d", A[0].sign);
        for(int i = 1; i < N; ++i)  printf(" %d", A[i].sign);
        printf("\n");
    }
    return 0;
}
