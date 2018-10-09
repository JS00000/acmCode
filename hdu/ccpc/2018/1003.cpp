#include <cstdio>

int main()
{
    int T, p;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &p);
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p-1; j++)
                printf("%d ", i);
            printf("%d\n", i);
        }
        for (int i = 0; i < p-1; i++) {
            for (int j = 0; j < p-1; j++)
                printf("%d ", i+1);
            printf("%d\n", i+1);
        }
        for (int j = 0; j < p-1; j++)
            printf("1 ");
        printf("1\n");
    }
    return 0;
}
