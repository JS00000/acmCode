#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 50007
using namespace std;

bool d[maxn] = {};
set<int> s;

int main()
{
    int n;
    scanf("%d", &n);
    int ma = sqrt(n), ans = 0, r;
    for (int i = 1; i <= ma; ++i)
        if (n % i == 0) d[i] = 1, s.insert(n/i);
    for (int i = 2; i <= ma; ++i)
    {
        int mul = 1, j = i;
        while(j > 1 && mul < n && d[j]) mul *= j--;
        if ( (n % mul == 0) && ((n / mul <= ma && d[n / mul]) || (n / mul > ma && s.count(n/mul))) && i-j > ans )
        {
            ans = i-j;
            r = i;
        }
    }
    
    if (ans == 0) ans = 1, r = n;

    printf("%d\n", ans);
    if (ans == 1) printf("%d\n", r);
    else
    {
        for (int i = 1; i < ans; ++i)
            printf("%d*", r - ans + i);
        printf("%d\n", r);
    }
    return 0;
}
