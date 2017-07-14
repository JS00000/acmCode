#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, p, w, h;
int a[1007];

bool check(int s)
{
    int line = 0;
    for (int i = 0; i < n; ++i)
        line += (a[i]-1)/(w/s)+1;
    return ((line-1)/(h/s)+1) <= p;
}


int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d%d", &n, &p, &w, &h);
        for (int i = 0; i < n; ++i)
            scanf("%d", a+i);
        int l = 1, r = min(w, h), mid;
        while(l <= r)
        {
            mid = (l+r)/2;
            if (check(mid)) l = mid+1;
            else r = mid-1;
        }
        printf("%d\n", l-1);
    }
    return 0;
}
