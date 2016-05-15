#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
using namespace std;

const int MAX = 55;
int x, y, k;
int ans[MAX];
long long modpow2[MAX];
long long pow2[MAX];

void initial()
{
    pow2[0] = 1;
    for(int i = 1; i < MAX; i++)
        pow2[i] = pow2[i - 1] << 1;
}

long long Pow10ModPow2(int i, int j)
{
    int ans = 1;
    while(i--)
        ans = ans*10%pow2[j];
    return ans;
}

void input()
{
    scanf("%d%d%d", &x, &y, &k);
}

void solve()
{
    int mul = 1, freedigit = 0;
    while(!(x&1) && !(y&1))
    {
        x >>= 1;
        y >>= 1;
        mul <<= 1;
        freedigit++;
    }
    if(k > freedigit && (x&1) && (y&1))
    {
        printf("Diao Ze MDZZ\n");
        return;
    }
    for(int i = 0; i < min(k, freedigit); i++)
        printf("%d", min(x, y)*mul);
    k -= freedigit;
    if(k > 0)
    {
        memset(modpow2, 0, sizeof(modpow2));
        int odd = x&1 ? x : y;
        int even = x + y - odd;
        for(int i = 0; i < k; i++)
        {
            ans[i] = modpow2[i + 1] ? odd : even;
            for(int j = i + 1; j <= k; j++)
                modpow2[j] = (modpow2[j] + ans[i]*Pow10ModPow2(i, j))%pow2[j];
        }
        for(int i = k - 1; i >= 0; i--)
            printf("%d", ans[i]*mul);
    }
    printf("\n");
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    initial();
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        input();
        solve();
    }
}
