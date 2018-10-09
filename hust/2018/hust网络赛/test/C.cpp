#include <cstdio>

#define maxn 100007

int N, Q, son_idx;
int son[maxn];
struct edge
{
    int next, to;
}nextson[maxn*20];

inline void add_son(int fa, int s)
{
    nextson[son_idx].to = s;
    nextson[son_idx].next = son[fa];
    son[fa] = son_idx++;
}

int father[maxn], size[maxn];
void init()
{
    for (int i = 0; i <= N; ++i)
        father[i] = i, size[i] = 1, son[i] = -1;
    son_idx = 0;
}

int find(int x)
{
    return father[x]==x ? x : find(father[x]);
}

void merge(int x, int y)
{
    int a = find(x), b = find(y);
    if (a != b) {
        father[a] = b;
        size[b] += size[a];
        add_son(b, a);
    }
}


void separate(int x)
{
    int a = find(x);
    if (a != x) {
        // has father
        for (int k = son[x]; k != -1; k = nextson[k].next) {
            father[nextson[k].to] = a;
            add_son(a, nextson[k].to);
        }
        if (nextson[son[father[x]]].to == x) {
            son[father[x]] = nextson[son[father[x]]].next;
        } else {
            for (int k = son[father[x]]; k != -1; k = nextson[k].next) {
                if (nextson[nextson[k].next].to == x) {
                    nextson[k].next = nextson[nextson[k].next].next;
                    break;
                }
            }
        }
        size[a]--;
    } else if (size[a] != 1) {
        // the root
        int sa = size[a];
        a = nextson[son[x]].to;
        father[a] = a;
        for (int k = nextson[son[x]].next; k != -1; k = nextson[k].next) {
            father[nextson[k].to] = a;
            add_son(a, nextson[k].to);
        }
        size[a] = sa - 1;
    } // single
    father[x] = x;
    size[x] = 1;
    son[x] = -1;
}


int main(int argc, char const *argv[])
{
    freopen("1.in", "r", stdin);
    freopen("1.ou", "w", stdout);

    int T, kase;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        printf("Case #%d:\n", kase);
        scanf("%d%d", &N, &Q);
        init();
        int com, u, v, t = 0;
        for (int i = 0; i < Q; i++) {
            scanf("%d", &com);
            if (com == 1) {
                scanf("%d%d", &u, &v);
                merge(u, v);
            } else if (com == 2) {
                scanf("%d", &u);
                separate(u);
            } else if (com == 3) {
                scanf("%d", &u);
                printf("%d\n", size[find(u)]);
            } else if (com == 4) {
                scanf("%d%d", &u, &v);
                printf("%s\n", find(u) == find(v) ? "YES": "NO");
            }
        }
    }
    return 0;
}
