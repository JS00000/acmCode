#include <cstdio>
#include <cstring>

#define maxn 1000007

char s[maxn];

int main()
{
    scanf("%s", s);
    int l = strlen(s);
    int k = l-1, x, y;
    // x:( y:)

    // pre
    while (s[k] == ')') k--;
    y = l - k;
    while (s[k] == '(') k--;
    x = l - 1 - k - y;
    for (int i = 0; i < k; i++) printf("%c", s[i]);
    printf("(");
    for (int i = 0; i < y - x; i++) printf(")");
    for (int i = 0; i < x; i++) printf("()");
    printf("\n");

    // suf
    for (k = l-1, x = 0, y = 0; k >= 0; k--) {
        if (s[k] == ')') {
            y++;
        } else {
            x++;
            if (x < y) break;
        }
    }
    y--;
    for (int i = 0; i < k; i++) printf("%c", s[i]);
    printf(")");
    for (int i = 0; i < x; i++) printf("(");
    for (int i = 0; i < y; i++) printf(")");
    printf("\n");
    return 0;
}
