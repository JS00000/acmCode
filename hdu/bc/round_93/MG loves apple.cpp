#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;

int n, k, c0, c1, c2, sum;
short d[maxn];

bool check(int i)
{
    if (i > k) return 0;

    if (d[i] % 3 == 0) 
    {
        c0--;
        int res = n-k-1;
        if (res <= c0) return 1;
        if ()
        // if ((2*min(c1, c2) + c0 >= n-k-1 && c0 > 0) || c0 == 0 && n-k-1 % 2 == 0) return 1;
        // else return 0;
    }
    else if (d[i] % 3 == 1) 
    {
        c1--;
    }
    else 
    {
        c2--;
    }

    // c0+c1+c2 => n-k-1    mod = 3-sum%3
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &k);
        getchar();
        c0 = c1 = c2 = sum = 0;
        for (int i = 0; i < n; i++) 
        {
            d[i] = getchar() - '0';
            sum += d[i];
            if (d[i] % 3 == 0) c0++;
            else if (d[i] % 3 == 1) c1++;
            else c2++;
        }
        bool flag = 0;
        sum -= d[i];
        for (int i = 0; i < n; i++)
        {
            if (d[i] == 0) 
            {
                c0--;
                continue;
            }
            // if (d[i] % 3 == 0) c0--;
            // else if (d[i] % 3 == 1) c1--;
            // else c2--;
            // sum -= d[i];
            if (check(i))
            {
                flag = 1;
                printf("yes\n");
                break;
            }
        }
        if (!flag) printf("no\n");
    }
    return 0;
}
