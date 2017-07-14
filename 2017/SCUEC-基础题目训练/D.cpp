#include <cstdio>
using namespace std;

void show(int n)
{
    if (n == 0) printf("00");
    else if (n < 10) printf("0%d", n);
    else printf("%d", n);
}

int main()
{
    int a, b, c;
    while(scanf("%d%d", &a, &b), a != 0 || b != 0)
    {
        for (c = a * 100 + b - ((a * 100 - 1) % b + 1); c+b < (a+1)*100; c += b) show(c % 100), printf(" ");
        show(c % 100);
        printf("\n");
    }
    return 0;
}
