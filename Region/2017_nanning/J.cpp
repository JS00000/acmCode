#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int n, set_n[10];
char source[10], target[10];

struct fmset
{
    vector<int> fa, ra;
    fmset(int n) : fa(n), ra(n)
    {
        for (int i = 0; i < n; ++i) fa[i] = i;
    }
    int find(int v)
    {
        return fa[v] = fa[v]==v ? v : find(fa[v]);
    }
    void merge(int x, int y)
    {
        int a = find(x), b = find(y);
        if (ra[a] < ra[b]) {
            fa[a] = b;
        } else {
            fa[b] = a;
            if (ra[b]==ra[a])
                ++ra[a];
        }
    }
};


int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 5; i++) {
        scanf("%s%s", source, target);
        fmset ds(n);
        for (int i = 0; i < n; i++) {
            ds.merge(source[i] - '1', target[i] - '1');
        }
        for (int i = 0; i < n; i++) {
            set_n[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            set_n[ds.find(i)]++;
        }
        int ans = 0;
        if (set_n[ds.find(source[0] - '1')] > 1) {
            ans += set_n[ds.find(source[0] - '1')] - 1;
        }
        set_n[ds.find(source[0] - '1')] = 0;
        for (int i = 0; i < n; i++) {
            if (set_n[ds.find(i)] > 1) {
                ans += set_n[ds.find(i)] + 1;
                set_n[ds.find(i)] = 0;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
