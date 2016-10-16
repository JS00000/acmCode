#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxn 1000007

typedef long long LL;

using namespace std;

struct node
{
    LL data;
    int pos;
};

int n;
node A[maxn];
LL BIT[maxn];
LL cc[maxn];

bool cmp(node a, node b)
{
    return a.data < b.data;
}

LL lowbit(LL x)
{
    return x&(-x);
}

void edit(int i, LL delta)
{
    for (int j = i; j <= n; j += lowbit(j))
        BIT[j] += delta;
}

LL sum (int k)
{
    LL ans = 0;
    for (int i = k; i > 0; i -= lowbit(i))
        ans += BIT[i];
    return ans;
}


int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &A[i].data);
        A[i].pos = i;
    }
    memset(BIT, 0, (n+3)*sizeof(LL));
    memset(cc, 0, (n+3)*sizeof(LL));
    sort(A+1, A+n+1, cmp);
    int id = 1;
    cc[A[1].pos] = 1;
    for (int i = 2; i <= n; i++)
        if (A[i].data == A[i-1].data) cc[A[i].pos] = id;
        else cc[A[i].pos] = ++id;
    LL num = 0;
    for (int i = 1; i <= n; i++)
    {
        edit(cc[i], 1);
        num += i - sum(cc[i]);
    }
    printf("%lld\n", num);
	return 0;
}
