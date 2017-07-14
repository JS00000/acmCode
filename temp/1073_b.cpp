#include <set>
#include <cstdio>
#include <algorithm>
#define maxn 1007
using namespace std;


typedef pair<pair<int, int>, int> P;
set<P> s;

P ss(int a, int b, int c)
{
    return P(pair<int, int>(a, b), c);
}

void sinsert(int a, int b, int c, P p[], int ip)
{
    if (!s.count(ss(a, b, c)))
    {
        s.insert(ss(a, b, c));
        p[ip] = ss(a, b, c);
    }
}

void bfs()
{
    s.clear();
    s.insert(ss(10, 0, 0));
    P p[10000];
    int pre[10000];
    p[0] = ss(10, 0, 0);
    int i = 0, ip = 0, a = 0, b, c;
    while(!(a == 5 && b == 5))
    {
        a = p[i].first.first, b = p[i].first.second, c = p[i].second;
        // a->b
        if (b < 7 && a > 0)
        {
            if (a + b < 7) sinsert(0, a+b, c, p, ++ip), pre[ip] = i;
            else sinsert(a + b - 7, 7, c, p, ++ip), pre[ip] = i;
        }
        // a->c
        if (c < 3 && a > 0)
        {
            if (a + c < 3) sinsert(0, b, a + c, p, ++ip), pre[ip] = i;
            else sinsert(a + c - 3, b, 3, p, ++ip), pre[ip] = i;
        }
        // b->c
        if (c < 3 && b > 0)
        {
            if (b + c < 3) sinsert(a, 0, b + c, p, ++ip), pre[ip] = i;
            else sinsert(a, b + c - 3, 3, p, ++ip), pre[ip] = i;
        }
        // b->a
        if (a < 10 && b > 0)
        {
            sinsert(a + b, 0, c, p, ++ip), pre[ip] = i;
        }
        // c->a
        if (a < 10 && c > 0)
        {
            sinsert(a + c, b, 0, p, ++ip), pre[ip] = i;
        }
        // c->b
        if (b < 7 && c > 0)
        {
            if (b + c < 7) sinsert(a, b + c, 0, p, ++ip), pre[ip] = i;
            else sinsert(a, 7, b + c - 7, p, ++ip), pre[ip] = i;
        }
        i++;
    }
    --i;
    while(p[i].first.first != 10)
    {
        printf("%d %d %d\n", p[i].first.first, p[i].first.second, p[i].second);
        i = pre[i];
    }
    printf("10 0 0\n");
}

int main()
{
    freopen("1073.txt", "w", stdout);
    bfs();
    return 0;
}
