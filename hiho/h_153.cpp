#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 500007
using namespace std;

int n;
int q[maxn*2], mi[maxn], ma[maxn];

int main()
{
    char c[4];
    scanf("%d", &n);
    int fq = 0, fmi = 0, fma = 0, tq = 0, tmi = 0, tma = 0;
    int t, p;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", c);
        if (c[0] == 'P')
        {
            scanf("%d%d", &t, &p);
            q[tq++] = t;
            q[tq++] = p;
            while(tmi > fmi && mi[tmi-1] > p) tmi--;
            mi[tmi++] = p;
            while(tma > fma && ma[tma-1] < p) tma--;
            ma[tma++] = p;
        }
        else if (c[0] == 'R')
        {
            scanf("%d", &t);
            while(q[fq] <= t && fq < tq) 
            {
                if (q[fq+1] == mi[fmi]) fmi++;
                if (q[fq+1] == ma[fma]) fma++;
                fq+=2;
            }
        }
        else if (c[0] == 'Q')
        {
            printf("%d %d %d\n", ma[fma], mi[fmi], q[tq-1]);
        }
    }
    return 0;
}
