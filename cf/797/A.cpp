#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;


int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int ret = n;
    int a[100];
    int ia = 0;
    while(k>1)
    {
        int ma = sqrt(ret);
        bool flag = 0;
        for(int i = 2; i <= ma; i++)
        {
            if (ret % i == 0)
            {
                a[ia++] = i;
                flag = 1;
                ret /= i;
                k--;
                break;
            }
        }
        if (!flag) break;
    }
    if (k>1 || ret == 1) printf("-1\n");
    else 
    {
        for (int i = 0; i < ia; ++i)
            printf("%d ", a[i]);
        printf("%d\n", ret);
    }
    return 0;
}
