#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", n/2*2 + (n+1)/2);
    printf("2");
    for (int i = 4; i <= n; i += 2)
        printf(" %d", i);
    for (int i = 1; i <= n; i += 2)
        printf(" %d", i);
    for (int i = 2; i <= n; i += 2)
        printf(" %d", i);
    printf("\n");
    return 0;
}
