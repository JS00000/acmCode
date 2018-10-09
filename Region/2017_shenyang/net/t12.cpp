#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000007
using namespace std;

int a[maxn];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a+i);
        }
        int mini = 1000000007, sum = 0, temp;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            a[i] -= temp;
            sum += a[i];
            if (sum < mini) mini = sum;
        }
        int i = 0;
        while (mini < 0)
            mini -= a[i++];
        printf("%d\n", i);
    }
    return 0;
}
