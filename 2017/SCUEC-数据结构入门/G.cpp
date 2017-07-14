#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

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
    bst(){root = NULL;}
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
        else if (p == root) printf("%d", p->data);
        else printf(" %d", p->data);
        PreOrderTraversal(p->l);
        PreOrderTraversal(p->r);
    }
    void solve()
    {
        PreOrderTraversal(root);
        printf("\n");
    }
};

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        bst b;
        int temp;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &temp);
            b.insert(temp);
        }
        b.solve();
    }
    return 0;
}
