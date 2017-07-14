#include <set>
#include <cstdio>
#include <algorithm>
#define maxn 100007
using namespace std;

int n;
int c[maxn];
set<int> s;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", c+i);
        int ans = 1;
        s.clear();
        for (int i = 0; i < n; ++i)
        {
            if (!s.count(c[i])) s.insert(c[i]);
            else ans++, s.clear(), s.insert(c[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
