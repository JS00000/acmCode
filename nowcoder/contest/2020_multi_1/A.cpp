#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define maxn (111111)
#define rank rrank
bool cmp(int *r, int a, int b, int l)
{ return r[a] == r[b] && r[a + l] == r[b + l]; }
int ta[maxn], tb[maxn], bk[maxn];
int rank[maxn], sa[maxn], height[maxn];
void da(int *r, int *sa, int n, int m)
{
    int i, j, p, *x = ta, *y = tb, *t;
    for(i = 0; i < m; i++) bk[i] = 0;
    for(i = 0; i < n; i++) bk[x[i] = r[i]]++;
    for(i = 1; i < m; i++) bk[i] += bk[i-1];
    for(i = 0; i < n; i++) sa[--bk[x[i]]] = i;
    for(j = 1, p = 1; p < n; j *= 2, m = p)
    {
        for(p = 0, i = n - j; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0; i < m; i++) bk[i] = 0;
        for(i = 0; i < n; i++) bk[x[i]]++;
        for(i = 1; i < m; i++) bk[i] += bk[i-1];
        for(i = n-1; i >= 0; i--) sa[--bk[x[y[i]]]] = y[i];
        for(t = x, x = y, y = t, x[sa[0]] = 0, p = 1, i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j)? p-1: p++;
    }
}
void calheight(int *r, int n)
{
    for(int i = 0; i < n; i++) rank[sa[i]] = i;
    for(int k = 0, i = 0; i < n; i++)
    {
        k ? k-- : 0;
        if(rank[i] > 0)
            while(r[i + k] == r[sa[rank[i] - 1] + k])
                k++;
        height[rank[i]] = k;
    }
}
char s[maxn];
int r[maxn], n;
struct node {
    int id, fir_a, fir_b;
    bool operator< (const node& o) const {
        int p = max(fir_a, fir_b), q = max(o.fir_a, o.fir_b);
        int u = p - min(fir_a, fir_b) - 1;
        int v = q - min(o.fir_a, o.fir_b) - 1;
        if(u != v) return u < v;
        int rankp = (p < n)? rank[p + 1]: (-1);
        int rankq = (q < n)? rank[q + 1]: (-1);
        return rankp < rankq;
    }
};
vector<node> v;
int main()
{
    while(cin >> n) {
        scanf("%s", s);
        int idx_a = -1, idx_b = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') {
                if(idx_a == -1) r[i] = 1;
                else r[i] = i - idx_a + 1;
                idx_a = i;
            } else {
                if(idx_b == -1) r[i] = 1;
                else r[i] = i - idx_b + 1;
                idx_b = i;
            }
        }
        int m = n;
        r[m++] = 0;
        // printf("r:  "); for(int i = 0; i < m; i++) {
        //  printf("%d ", r[i]);
        // } printf("\n");
 
        da(r, sa, m, m + 100);
        calheight(r, m);
 
        // printf("rk: "); for(int i = 0; i < m; i++) {
        //  printf("%d ", rank[i]);
        // } printf("\n");
 
        v.clear();
        int fir_a = n, fir_b = n;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == 'a') fir_a = i;
            else fir_b = i;
            v.push_back((node){i, fir_a, fir_b});
        }
        sort(v.begin(), v.end());
        for(int i = 0, sz = v.size(); i < sz; i++) {
            if(i > 0) putchar(' ');
            printf("%d", v[i].id + 1);
        }
        printf("\n");
    }
    return 0;
}