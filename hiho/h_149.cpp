// Trie树
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
struct Trie_node {
    char ch;
    int flag;
    Trie_node *child, *bro, *fa, *next;
    Trie_node(char ch): ch(ch), child(NULL), bro(NULL), fa(NULL), next(NULL), flag(0) {}
} *root = new Trie_node(0);
void insert(char s[], int ad) {
    Trie_node *p = root;
    for (int i = 0; s[i]; i++) {
        Trie_node *pc = p->child;
        while (pc != NULL && pc->ch != s[i]) pc = pc->bro;
        if (pc == NULL) {
            Trie_node *tmp = new Trie_node(s[i]);
            tmp->bro = p->child;
            p->child = tmp;
            tmp->fa = p;
            p = tmp;
        } else {
            p = pc;
        }
    }
    if (p->flag == 0) p->flag = ad;
}
Trie_node *get_child(Trie_node *p, char ch) {
    for (Trie_node *tmp = p->child; tmp; tmp = tmp->bro) {
        if (tmp->ch == ch) return tmp;
    }
    return NULL;
}
bool query(char s[])
{
    Trie_node *p = root;
    int min_idx = 1000000000;
    bool ad;
    if (p->flag > 0) {
        min_idx = p->flag;
        ad = 1;
    } else if (p->flag < 0) {
        min_idx = -p->flag;
        ad = 0;
    }
    for (int i = 0; s[i] && p; i++) {
        p = get_child(p, s[i]);
        if (p) {
            if (p->flag > 0 && p->flag < min_idx) {
                min_idx = p->flag;
                ad = 1;
            } else if (p->flag < 0 && -p->flag < min_idx) {
                min_idx = -p->flag;
                ad = 0;
            }
        }
    }
    if (min_idx == 1000000000) return 1;
    else return ad;
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    char comm[10], addr[33];
    int ip[4], mask;
    addr[32] = '\0';
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 32; j++) addr[j] = '0';
        scanf("%s%d.%d.%d.%d", comm, &ip[0], &ip[1], &ip[2], &ip[3]);
        for (int k = 3; k >= 0; k--) {
            int j = k*8+7;
            while (ip[k]) {
                addr[j--] = (ip[k] & 1) + '0';
                ip[k] >>= 1;
            }
        }
        if (getc(stdin) != '/') mask = -1;
        else scanf("%d", &mask), addr[mask] = '\0';
        if (comm[0] == 'a') insert(addr, i);
        else insert(addr, -i);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 32; j++) addr[j] = '0';
        scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
        for (int k = 3; k >= 0; k--) {
            int j = k*8+7;
            while (ip[k]) {
                addr[j--] = (ip[k] & 1) + '0';
                ip[k] >>= 1;
            }
        }
        printf("%s\n", query(addr)?"YES":"NO");
    }
    return 0;
}
