#include <stdio.h>
int main(int argc, char const *argv[])
{
	char s[10000];
    char *p; 
    int d;
    while (scanf("%s", s) > 0)
    {
        p = s;
        d = 0;
        while (*p) {
            d += *p - '0';
            ++p;
        }
        if (d == 0) break;

        d %= 9;
        if (d == 0) d = 9;
        printf("%d\n", d);
    }
    return 0;
}
