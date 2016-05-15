#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

const int CHARSET = 26, BASE = 'a';
vector<int> zeros;
struct Trie
{
    int tot, root;
    vector<vector<int> > child;
    vector<int> fa;
    vector<int> son;
    Trie()
    {
        zeros.resize(26);
        child.push_back(zeros);
        child.push_back(zeros);
        fa.push_back(0);
        fa.push_back(0);
        son.push_back(0);
        son.push_back(0);
        root = tot = 1;
    }
    void insert(const char *str)
    {
        int chi = root;
        int now;
        for (const char *p = str; *p; ++p)
        {
            now = chi;
            chi = child[now][*p-BASE];
            if (chi == 0)
            {
                child[now][*p-BASE] = ++tot;
                chi = tot;
                child.push_back(zeros);
                fa.push_back(now);
                son[now]++;
                son.push_back(0);
            }
        }
    }
    bool query(const char *str)
    {
        int cur = root;
        for (const char *p = str; *p && cur; ++p)
            cur = child[cur][*p - BASE];
        return cur;
    }
    int del(const char *str)
    {
        stack<int> s;
        int cur = root;
        for (const char *p = str; *p && cur; ++p)
        {
            cur = child[cur][*p - BASE];
            s.push(*p - BASE);
        }
        if (!cur) return 0;
        if (son[cur])
        {
            for (int i = 0; i < 26; ++i)
                child[cur][i] = 0;
            son[cur] = 0;
        }
        for (; !son[cur] && cur; cur = fa[cur])
        {
            child[fa[cur]][s.top()]= 0;
            s.pop();
            son[fa[cur]]--;
        }
        return 0;
    }
};


int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);
    Trie tree;
    int t;
    char st[100], c[10];
    scanf("%d", &t);
    while(t--)
    {
        getchar();
        scanf("%s", c);
        if (c[0] == 'i')
        {
            scanf("%s", st);
            tree.insert(st);
        }
        else if (c[0] == 'd')
        {
            scanf("%s", st);
            tree.del(st);
        }
        else if (c[0] == 's')
        {
            scanf("%s", st);
            if (tree.query(st))
                printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
