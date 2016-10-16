// Fenwick_tree
#include <cstdio>

#define maxn 1007

using namespace std;

int lowbit(int x)
{
	return x&(-x);
}

int n;
int A[maxn];
int BIT[maxn];

void build()
{ 
    for (int i=1;i<=n;i++)
    {
        BIT[i]=A[i];
        for (int j=i-1; j>i-lowbit(i); j--)
            BIT[i]+=A[j];
    }
}

void edit(int i, int delta)
{
    for (int j = i; j <= n; j += lowbit(j))
        BIT[j] += delta;
}

int sum (int k)
{
    int ans = 0;
    for (int i = k; i > 0; i -= lowbit(i))
        ans += BIT[i];
    return ans;
}


int main(int argc, char const *argv[])
{
	
	return 0;
}
