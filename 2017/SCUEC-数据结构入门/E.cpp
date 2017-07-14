#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int stack[maxn];
int b[maxn];

int main()
{
    int N;
    scanf("%d", &N);
    while(N)
    {
        scanf("%d", &b[0]);
        while (b[0])
        {
            for (int i = 1; i < N; ++i)
            {
                scanf("%d", &b[i]);
            }
            int k = 0, a = 0;
            stack[0] = 0;
            bool flag = true;
            for (int i = 0; i < N; ++i)
            {
                if (b[i] >= stack[k]) 
                {
                    while(a < b[i]) stack[++k] = ++a;
                    k--;
                }
                else
                {
                    printf("No\n");
                    flag = false;
                    break;
                }
            }
            if (flag) printf("Yes\n");
            scanf("%d", &b[0]);
        }
        printf("\n");
        scanf("%d", &N);
    }
    return 0;
}
