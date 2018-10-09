#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define maxn 10000
using namespace std;

int N, M;
long long A[maxn], P[maxn], S[maxn];
struct node
{
    long long t;
    long long n;
    node(){}
    node(long long _t, long long _n){t = _t, n = _n;}
    bool operator < (const node &r) const
    {
        return r.t > t;
    }
};
priority_queue<node> q;

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++)
        scanf("%lld", A+i);
    for (int i = 0; i < M; i++)
        scanf("%lld", P+i);
    for (int i = 0; i < M; i++)
        scanf("%lld", S+i);
    for (int i = 0; i < M; i++) {
        if (A[i] % S[i] != 0)
            q.push(node(P[i] * (A[i] % S[i]), 1));
        if (A[i] / S[i] != 0)
            q.push(node(P[i] * S[i], A[i] / S[i]));
    }
    int cnt = N;
    long long ans = 0;
    while (!q.empty() && cnt > 0) {
        node top = q.top();
        q.pop();
        if (top.n <= cnt) {
            ans += top.n * top.t;
            cnt -= top.n;
        } else {
            ans += cnt * top.t;
            cnt = 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
