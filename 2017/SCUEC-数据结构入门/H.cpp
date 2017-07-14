#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef unsigned long long llu;
struct node
{
    int data;
    node *l, *r;
    node(){l = NULL, r = NULL;}
    node(int t){l = NULL, r = NULL, data = t;}
};

struct bst
{
    node *root;
    llu w, base;
    bst(){root = NULL;w = 0;base = 1;}
    void _insert(node *&p, int t)
    {
        if (p == NULL) p = new node(t);
        else if (t < p->data) _insert(p->l, t);
        else _insert(p->r, t);
    }
    void insert(int t)
    {
        _insert(root, t);
    }
    void PreOrderTraversal(node *p)
    {
        if (p == NULL) return;
        w += p->data * base;
        base *= 10;
        PreOrderTraversal(p->l);
        PreOrderTraversal(p->r);
    }
    llu calc()
    {
        PreOrderTraversal(root);
        return w;
    }
};

int main()
{
    int n;
    while(scanf("%d", &n), n != 0)
    {
        char s[20];
        scanf("%s", s);
        int len = strlen(s);
        bst b0;
        for (int i = 0; i < len; ++i)
            b0.insert(s[i] - '0');
        llu ans = b0.calc();
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", s);
            len = strlen(s);
            bst b;
            for (int i = 0; i < len; ++i)
                b.insert(s[i] - '0');
            if (ans == b.calc()) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
