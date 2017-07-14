#include <cstdio>

int main()
{
    int n, a = 0, d = 0;
    char c;
    scanf("%d", &n);
    scanf("%c", &c);
    for (int i = 0; i < n; ++i)
    {
        scanf("%c", &c);
        if (c == 'A') a++;
        else if (c == 'D') d++;
    }
    if (a > d) printf("Anton\n");
    else if (a < d) printf("Danik\n");
    else printf("Friendship\n");
    return 0;
}
