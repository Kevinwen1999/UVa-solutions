#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 100
#define UPWARD 0
#define DOWNWARD 1
#define FLAT 2
using namespace std;
int N;
int deck[100];
int getscore (int card1, int card2, int card3) {
    int pc = 0, nc = 0;
    int sum = 0;
    sum += abs(card1) + abs(card2) + abs(card3);
    if (card1 > 0) pc++; else nc++;
    if (card2 > 0) pc++; else nc++;
    if (card3 > 0) pc++; else nc++;
    if (pc > nc) return sum;
    else return -sum;
}
struct state {
    int value[MAXN], direction[MAXN];
    int hold[2];
    int nexpos;
    int score;
    bool isfinal() {
        if (nexpos == 2*N) {
            score += hold[0] + hold[1];
            hold[0] = hold[1] = 0;
            return true;
        }
        else
            return false;
    }
    state() {
        for (int i = 0; i < 8; i++) {
            value[i] = deck[i];
            direction[i] = (i%2==0 ? UPWARD : DOWNWARD);
        }
        hold[0] = hold[1] = 0;
        nexpos = 8;
        score = 0;
    }
    state child() const {
        state s;
        memcpy(&s, this, sizeof(s));
        s.nexpos++;
        return s;
    }
    void expand(int player, vector <state> &V) const {
        int &cur = deck[nexpos];
        state temp;
        // hold a card
        if (hold[player] == 0) {
            temp = child();
            temp.hold[player] = cur;
            V.push_back(temp);
        }
        // make flat card
        for (int i = 0; i < 7; i++) {
            if (direction[i] == DOWNWARD && direction[i+1] == UPWARD) {

                // use curcard and keep nexcard
                temp = child();
                temp.score += getscore(value[i], value[i+1], cur);
                temp.direction[i] = temp.direction[i+1] = FLAT;
                temp.value[i] = temp.value[i+1] = cur;
                V.push_back(temp);

                //use card on hold
                if (hold[player]!=0) {
                    temp = child();
                    temp.score += getscore(value[i], value[i+1], hold[player]);
                    temp.direction[i] = temp.direction[i+1] = FLAT;
                    temp.value[i] = temp.value[i+1] = hold[player];
                    temp.hold[player] = cur;
                    V.push_back(temp);
                }
            }
        }
        // make tower
        if (hold[player] != 0) {
            for (int i = 0; i < 7; i++) {
                if (direction[i] == FLAT && direction[i+1] == FLAT && value[i] == value[i+1]) {
                    temp = child();
                    temp.score += getscore(cur, hold[player], value[i]);
                    temp.direction[i] = UPWARD, temp.direction[i+1] = DOWNWARD;
                    temp.value[i] = cur, temp.value[i+1] = hold[player];
                    temp.hold[player] = 0;
                    V.push_back(temp);
                    swap(temp.value[i], temp.value[i+1]);
                    V.push_back(temp);
                }
            }
        }
    }
};
int alphabeta (int player, state& s, int alpha, int beta) {
    if (s.isfinal()) return s.score;
    vector <state> V;
    s.expand(player, V);
    for (state child : V) {
        int val = alphabeta(1-player, child, alpha, beta);
        if (!player)
            alpha = max(alpha, val);
        else
            beta = min(beta, val);
        if (beta <= alpha) break;
    }
    if (!player) return alpha;
    else return beta;
}
int kase = 0;
int main() {
    char name[100];
    while (scanf("%s", name) != EOF && name[0] != 'E') {
        scanf("%d", &N);
        for (int i = 0; i < 2*N; i++) {
            char tmp;
            scanf("%d%c", &deck[i], &tmp);
            if (tmp == 'B') deck[i] = -deck[i];
        }
        state ori;
        int start = !(deck[0] > 0);
        int ans = alphabeta(start, ori, -INF, INF);
        if (name[0] == 'B') ans = -ans;
        printf("Case %d: ", ++kase);
        if (ans == 0) printf("Axel and Birgit tie\n");
        else if (ans > 0) printf("%s wins %d\n", name, ans);
        else printf("%s loses %d\n", name, abs(ans));
    }
}
