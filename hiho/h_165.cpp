#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;

char str[maxn];
int what[26];

bool check(int last, int len)
{
    bool ret = 1;
    for (int i = 0; i < 26; i++) 
        if (what[i] > (len + 1) / 2) ret = 0;
    if (last > 0 && what[last] > len / 2) ret = 0;
    return ret;
}

int main()
{
    scanf("%s", str);
    int len = strlen(str);
    int i, j, k;
    for (i = 0; i < 26; i++) what[i] = 0;
    for (i = 0; i < len; i++) what[str[i] - 'a']++;
    bool flag = 1;
    k = -1;
    for (i = 0; i < len; i++) {
        for (j = 0; j < 26; j++) {
            if (what[j] > 0 && j != k) {
                what[j]--;
                if (check(j, len - i - 1)) {
                    str[i] = 'a' + j;
                    k = j;
                    break;
                } else {
                    what[j]++;
                }
            }
        }
        if (j == 26) flag = 0;
    }
    if (!flag) printf("INVALID\n");
    else printf("%s\n", str);
    return 0;
}

