#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <algorithm>    // std::set_intersection, std::sort
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
    return b==0?a:gcd(b, a%b);
}


int main () {

    int n = 8, m = 8;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            printf("%4d", (i & j));
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            printf("%4d", (i | j));
        }
        printf("\n");
    }

    printf("\n");
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int temp = gcd(i & j, i | j);
            printf("%4d", temp);
            sum += temp;
        }
        printf("\n");
    }
    printf("%d\n", sum);
    return 0;
}