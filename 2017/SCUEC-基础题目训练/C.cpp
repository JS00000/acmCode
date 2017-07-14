#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;



int main()
{
    int n, m;
    bool flag;
    while(scanf("%d%d", &n, &m), n != 0 || m != 0)
    {
        flag = 0;
        if (m == 0) printf("Yes\n"), flag = 1;
        else if (m > 0)
        {
            int hm = sqrt(m) + 1;
            for (int i = 1; i < hm; ++i)
                if (m % i == 0 && i + m / i == abs(n))
                {
                    printf("Yes\n");
                    flag = 1;
                    break;
                }
        }
        else
        {
            m = -m;
            int hm = sqrt(m) + 1;
            for (int i = 1; i < hm; ++i)
                if (m % i == 0 && (i - m / i == n || - i + m / i == n))
                {
                    printf("Yes\n");
                    flag = 1;
                    break;
                }
        }
        if (!flag) printf("No\n");
    }
    return 0;
}
