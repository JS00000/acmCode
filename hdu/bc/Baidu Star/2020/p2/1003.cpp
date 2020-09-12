#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define maxn 20007
using namespace std;

bool mp[101][11];
bool flag[maxn];
int len[maxn];
int tp_idx;
struct node {
    int id;
    int t, p;
    node() {}
    node(int _id, int _t, int _p): id(_id), t(_t), p(_p) {}
    bool operator<(const node& r) const {
        return t == r.t ? id < r.id: t < r.t;
    }
}tp[200007];

int main()
{
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        memset(mp, 0, sizeof(mp));
        memset(flag, 0, sizeof(flag));
        int n;
        scanf("%d", &n);
        tp_idx = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", len + i);
            for (int j = 0; j < len[i]; j++) {
                int tt, pp;
                scanf("%d%d", &tt, &pp);
                tp[tp_idx++] = node(i, tt, pp);
            }
        }
        sort(tp, tp+tp_idx);
        flag[1] = 1;
        int i = 0, j = 0;
        for (int t = 1; t <= 100 && i < tp_idx; t++) {
            j = i;
            while (j < tp_idx && tp[j].t == t) {
                if (flag[tp[j].id]) mp[tp[j].t][tp[j].p] = 1;
                j++;
            }
            j = i;
            while (j < tp_idx && tp[j].t == t) {
                if (mp[tp[j].t][tp[j].p]) flag[tp[j].id] = 1;
                j++;
            }
            i = j;
        }
        printf("1");
        for (int i = 2; i <= n; i++) 
            if (flag[i]) {
                printf(" %d", i);
            }
        printf("\n");
    }
    return 0;
}
