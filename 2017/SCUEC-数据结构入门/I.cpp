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
    bst(){root = NULL;}
    void _insert(node *&p, int t, char s[])
    {
        if (p == NULL) p = new node();
        if (s[0] == 'L') _insert(p->l, t, s+1);
        else if (s[0] == 'R') _insert(p->r, t, s+1);
        else p->data = t;
    }
    void insert(int t, char s[])
    {
        _insert(root, t, s);
    }
    void build(char s[])
    {
        int num = s[1] - '0', i = 1;
        while(s[++i] != ',') num = num*10 + s[i] - '0';
        s[strlen(s)-1] = '\0';
        insert(num, s+i+1);
    }
    void traversal(int nn)
    {
        node *p[300];
        p[0] = root;
        int i = 0, iq = 1;
        while(i < iq)
        {
            if (p[i]->l != NULL) p[iq++] = p[i]->l;
            if (p[i]->r != NULL) p[iq++] = p[i]->r;
            i++;
        }
        if (iq != nn) printf("not complete\n");
        else
        {
            for (int i = 0; i < nn-1; ++i)
                printf("%d ", p[i]->data);
            printf("%d\n", p[nn-1]->data);
        }
        for (int i = 0; i < iq; ++i)
            delete p[i];
        root = NULL;
    }
};

int main()
{
    bst b;
    char s[50];
    int nn = 0;
    while(~scanf("%s", s))
    {
        if (strlen(s) > 2) b.build(s), nn++;
        else b.traversal(nn), nn = 0;
    }
    return 0;
}
