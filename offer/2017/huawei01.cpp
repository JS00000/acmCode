#include <cstdio>
#include <cstring>
#define maxn 1000007

char str[maxn];

bool is_char(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_num(char c)
{
    return c >= '0' && c <= '9';
}

bool is_other(char c)
{
    return !is_num(c) && !is_char(c);
}

int main()
{
    gets(str);
    int len = strlen(str);
    int n1 = 0, n2 = 0, n3 = 0, last;
    if (is_char(str[0])) n1 = 1, last = 1;
    else if (is_num(str[0])) n2 = 1, last = 2;
    else n3 = 1, last = 3;
    for (int i = 1; i < len; i++){
        if (is_char(str[i])){
            if (last == 1) continue;
            else n1++, last = 1;
        } else if (is_num(str[i])) {
            if (last == 2) continue;
            else n2++, last = 2;
        } else {
            if (last == 3) continue;
            else n3++, last = 3;
        }
    }
    printf("%d,%d,%d\n", n1, n2, n3);
    return 0;
}
