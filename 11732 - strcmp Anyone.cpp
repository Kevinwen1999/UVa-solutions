#include <bits/stdc++.h>
#define MOD 20071027
#define MAXM 301000
#define MAXN 110
#define SIGMA 30
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-9

ll ans = 0;

#define MAXNODE 5000000
using namespace std;
int sz = 0, root;
struct TrieNode {
    char chr;
    int end_cnt;
    int pass_cnt;
    int lchild; // pointing to first child
    int rchild; // pointing to adjacent siblings
};
TrieNode trie[MAXNODE];
int NewNode(char c) {
    trie[sz].lchild = trie[sz].rchild = -1;
    trie[sz].end_cnt = trie[sz].pass_cnt = 0;
    trie[sz++].chr = c;
    return sz - 1;
}
void init_trie() {
    sz = 0;
    root = NewNode(0);
}
void TrieInsert(char *s) {
    int slen = strlen(s);
    int cur = trie[root].lchild; // current node
    int par = root; // parent of cur
    bool same = true;
    for (int i = 0; i <= slen; i++) {
        if (cur == -1) { // current node for s[i] DNE
            trie[par].lchild = cur = NewNode(s[i]);
            trie[cur].pass_cnt = 1;
            same = false;
        } else {
            if (i) ans += trie[cur].pass_cnt;
            ans += trie[cur].pass_cnt++;
            while (trie[cur].rchild != -1 && trie[cur].chr != s[i]) // keep going right to siblings
                cur = trie[cur].rchild;
            if (trie[cur].chr != s[i]) { // if corresponding node is not found
                trie[cur].rchild = NewNode(s[i]);
                cur = trie[cur].rchild;
                same = false;
            }
        }
        par = cur;
        cur = trie[par].lchild; // keep going down
    }
    if (same) trie[par].end_cnt++;
    ans += trie[par].end_cnt;
}
char st[1010];
int main() {
    int N, ks = 0;
    while (scanf("%d", &N) && N) {
        init_trie();
        ans = 0;
        for (int i = 0; i < N; i++) {
            scanf("%s", st), TrieInsert(st);
        }
        printf("Case %d: %lld\n", ++ks, ans);
    }
}
