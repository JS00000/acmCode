#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

unsigned long long get(int w, int x, int y)
{
    if (w == 2) return x == 1? y : 5 - y;
    else {
        int m = w >> 1;
        if (x <= m && y <= m) return (unsigned long long)(m) * m - get(m, m - y + 1, x) + 1;
        else if (x <= m && y > m) return (unsigned long long)(m) * m + get(m, x, y - m);
        else if (x >  m && y > m) return (unsigned long long)(m) * m * 2 + get(m, x - m, y - m);
        else return (unsigned long long)(m) * m * 4 - get(m, y, w - x + 1) + 1;
    }
}

int main()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    printf("%llu\n", get(pow(2, n), x, y));
    return 0;
}
