#include <vector>
#include <cstdio>
#include <algorithm>
#define maxn 1007
using namespace std;

struct disjoint_set
{
    vector<int> fa, rank;
    disjoint_set(int n): fa(n), rank(n)
    {
        for (int i = 0; i < n; i++) 
            fa[i] = i;
    }
    int find(int x) 
    {
        return fa[x] = fa[x] == x ? x : find(fa[x]);
    }
    void merge(int x, int y)
    {
        int a = find(x), b = find(y);
        if (rank[a] < rank[b]) {
            fa[a] = b;
        } else {
            fa[b] = a;
            if (rank[a] == rank[b]) 
                rank[a]++;
        }
    }
};

int gcd(int x, int y)
{
    return y == 0 ? x: gcd(y, x % y);
}


int main()
{
    int n, p[maxn], count[maxn];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf("%d", p+i);
    disjoint_set s(n);
    for (int i = 0; i < n; i++) 
        s.merge(i, p[i]-1), count[i] = 0;
    for (int i = 0; i < n; i++) 
        count[s.find(i)]++;
    int ans = 1;
    for (int i = 0; i < n; i++) 
        if (count[i] != 0)
            ans = ans / gcd(count[i], ans) * count[i];
    printf("%d\n", ans);
    return 0;
}
