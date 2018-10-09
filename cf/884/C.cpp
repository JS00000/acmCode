#include <vector>
#include <cstdio>
#include <algorithm>
#define maxn 100007
using namespace std;

typedef long long ll;

struct disjoint_set
{
    vector<int> fa, rank;
    disjoint_set(int n): fa(n), rank(n)
    {
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    int find(int x) 
    {
        return fa[x] = (fa[x] == x ? x : find(fa[x]));
    }
    void merge(int x, int y)
    {
        int a = find(x), b = find(y);
        if (rank[a] < rank[b]) {
            fa[a] = b;
        } else {
            fa[b] = a;
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
        }
    }
};

int n, p[maxn];

int main()
{
    scanf("%d", &n);
    disjoint_set s(n);
    int temp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        s.merge(i, temp-1);
        p[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        p[s.find(i)]++;
    }
    sort(p, p + n);
    if (n == 1) {
        printf("1\n");
    } else if (n == 2) {
        printf("4\n");
    } else {
        ll ans = 0;
        for (int i = 0; i < n - 2; i++) {
            ans += (long long)p[i] * p[i];
        }
        ans += (long long)(p[n-2] + p[n-1]) * (p[n-2] + p[n-1]);
        printf("%I64d\n", ans);
    }
    return 0;
}
