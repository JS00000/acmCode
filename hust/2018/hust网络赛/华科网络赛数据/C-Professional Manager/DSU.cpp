#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e5+10;
int par[maxn], hs[maxn];
int sz[maxn];
int cnt;

void init(int n)
{
    for(int i = 0; i <= n; i++)par[i] = i, hs[i] = i, sz[i] = 1;
}

int find(int x)
{
    return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x); y = find(y);
    if(x != y)par[x] = y, sz[y] += sz[x];
}

void del(int x)
{
    sz[find(hs[x])]--;
    hs[x] = ++cnt;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        printf("Case #%d:\n", kase++);
        int n, q;
        sc(n); sc(q);
        init(n+q);
        cnt = n;
        for(int i = 0; i < q; i++){
            int op;
            sc(op);
            if(op == 1){
                int u, v;
                sc(u); sc(v);
                unite(hs[u], hs[v]);
            }
            else if(op == 2){
                int u; sc(u);
                del(u);
            }
            else if(op == 3){
                int u; sc(u);
                int ans = sz[find(hs[u])];
                printf("%d\n", ans);
            }
            else{
                int u, v;
                sc(u); sc(v);
                if(find(hs[u]) == find(hs[v]))printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}

