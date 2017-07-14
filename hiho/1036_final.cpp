// Trie图
#include <queue>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
struct Trie_node {
    char ch;
    int cnt;
    Trie_node *child, *bro, *fa, *next;
    Trie_node(char ch): ch(ch), child(NULL), bro(NULL), fa(NULL), next(NULL), cnt(0) {}
} *root = new Trie_node(0);
void insert(string s) {
    Trie_node *p = root;
    for (std::string::iterator it = s.begin(); it != s.end(); it++) {
        Trie_node *pc = p->child;
        while (pc != NULL && pc->ch != *it) pc = pc->bro;
        if (pc == NULL) {
            Trie_node *tmp = new Trie_node(*it);
            tmp->bro = p->child;
            p->child = tmp;
            tmp->fa = p;
            p = tmp;
        } else {
            p = pc;
        }
    }
    p->cnt++;
}
Trie_node *get_child(Trie_node *p, char ch) {
    for (Trie_node *tmp = p->child; tmp; tmp = tmp->bro) {
        if (tmp->ch == ch) return tmp;
    }
    return NULL;
}
// bfs
void build_trie_graph() {
    queue<Trie_node *> q;
    q.push(root);
    while (!q.empty()) {
        Trie_node *tmp = q.front();
        q.pop();
        for (; tmp; tmp = tmp->bro) {
            if (tmp == root) tmp->next = NULL;
            else if (tmp->fa == root) tmp->next = root;
            else {
                Trie_node *next = tmp->fa->next;
                while (next != NULL && get_child(next, tmp->ch) == NULL) next = next->next;
                if (next == NULL) tmp->next = NULL;
                else tmp->next = get_child(next, tmp->ch);
            }
            if (tmp->child) q.push(tmp->child);
        }
    }
}
bool solve(string s) {
    Trie_node *p = root;
    for (std::string::iterator it = s.begin(); it != s.end(); it++) {
        while (p != NULL && get_child(p, *it) == NULL) p = p->next;
        if (p == NULL) p = root;
        else p = get_child(p, *it);
        if (p->cnt) return 1;
    }
    return 0;
}
int main() {
    std::ios::sync_with_stdio(false);
    int N;
    cin >> N;
    while(N--) {
        string str;
        cin >> str;
        insert(str);
    }
    build_trie_graph();
    string str;
    cin >> str;
    cout << (solve(str) ? "YES\n" : "NO\n");
    return 0;
}
