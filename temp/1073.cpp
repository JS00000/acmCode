#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

bool flag = 0;
void dfs(int a, int b, int c)
{
    if (a == 5 && b == 5) flag = 1;
    if (!flag)
    {
        bool p = 1;
        while (p)
        {
            int choice = rand() % 6;
            switch(choice)
            {
                // a->b
                case 0:
                    if (b < 7 && a > 0)
                    {
                        if (a + b < 7) dfs(0, a+b, c);
                        else dfs(a + b - 7, 7, c);
                        p = 0;
                    }
                    break;
                // a->c
                case 1:
                    if (c < 3 && a > 0)
                    {
                        if (a + c < 3) dfs(0, b, a + c);
                        else dfs(a + c - 3, b, 3);
                        p = 0;
                    }
                    break;
                // b->c
                case 2:
                    if (c < 3 && b > 0)
                    {
                        if (b + c < 3) dfs(a, 0, b + c);
                        else dfs(a, b + c - 3, 3);
                        p = 0;
                    }
                    break;
                // b->a
                case 3:
                    if (a < 10 && b > 0)
                    {
                        dfs(a + b, 0, c);
                        p = 0;
                    }
                    break;
                // c->a
                case 4:
                    if (a < 10 && c > 0)
                    {
                        dfs(a + c, b, 0);
                        p = 0;
                    }
                    break;
                // c->b
                case 5:
                    if (b < 7 && c > 0)
                    {
                        if (b + c < 7) dfs(a, b + c, 0);
                        else dfs(a, 7, b + c - 7);
                        p = 0;
                    }
                    break;
                default:return;
            }
        }
    }
    printf("%d %d %d\n", a, b, c);
}

int main()
{
    freopen("1073.txt", "w", stdout);
    srand(unsigned(time(NULL)) + clock());
    dfs(10, 0, 0);
    return 0;
}
