// Trie图
#include <queue>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
struct T {
    char ch;
    T *child, *bro, *fa, *next;
    bool b;
    T(char ch) : ch(ch), child(NULL), bro(NULL), fa(NULL), next(NULL), b(0) {}
} *root = new T(0);
void put(string str) {
    int sz = str.size();
    T *p = root;
    for(int i = 0; i < sz; ++i) {
        T *pc = p -> child;
        while(pc != NULL && pc -> ch != str[i])
            pc = pc -> bro;
        if(pc == NULL) {
            T *t = new T(str[i]);
            t -> bro = p -> child;
            p -> child = t;
            t -> fa = p;
            p = t;
        } else
            p = pc;
    }
    p -> b = 1;
}
T *in(T *r, char ch) {
    for(T *t = r -> child; t; t = t -> bro) {
        if(t -> ch == ch)
            return t;
    }
    return NULL;
}
void bfs() {
    queue<T *> myqueue;
    myqueue.push(root);
    while(!myqueue.empty()) {
        T *t = myqueue.front();
        myqueue.pop();
        for(T *tmp = t; tmp; tmp = tmp -> bro) {
            if(tmp == root)
                tmp -> next = NULL;
            else if(tmp -> fa == root)
                tmp -> next = root;
            else {
                T *tmpfa = tmp -> fa -> next;
                while(tmpfa != NULL && in(tmpfa, tmp -> ch) == NULL)
                    tmpfa = tmpfa -> next;
                if(tmpfa == NULL)
                    tmp -> next = NULL;
                else
                    tmp -> next = in(tmpfa, tmp -> ch);
            }
            // 原程序这里有问题，没有遍历完，改正后速度大幅下降
            if(tmp -> child)
                myqueue.push(tmp -> child);
        }
    }
}
bool find(string str) {
    T *t = root;
    for(int i = 0, sz = str.size(); i < sz; ++i) {
        while(t != NULL && in(t, str[i]) == NULL)
            t = t -> next;
        if(t == NULL)
            t = root;
        else
            t = in(t, str[i]);
        if(t -> b)
            return 1;
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
        put(str);
    }
    bfs();
    string str;
    cin >> str;
    cout << (find(str) ? "YES\n" : "NO\n");
    return 0;
}