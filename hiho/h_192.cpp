#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

char str[207], p[26];
int i, j, k, k1, len;

int main()
{
    scanf("%s", str);
    len = 0;
    for (i = 0; str[i]; i++) {
        if (str[i] == 'J') 
            str[i] = 'I';
        len++;
    }
    for (i = 0; i < 26; i++)
        p[i] = 0;
    p[9] = 1;
    i = 0, k = 0, k1 = 0;
    while (i < 5) {
        j = 0;
        while (j < 5) {
            if (k < len) {
                if (p[str[k] - 'A'] == 0) {
                    printf("%c", str[k]);
                    j++;
                    p[str[k] - 'A'] = 1;
                }
                k++;
            } else {
                while (p[k1]) k1++;
                printf("%c", k1 + 'A');
                j++;
                p[k1] = 1;
            }
        }
        printf("\n");
        i++;
    }
    return 0;
}
