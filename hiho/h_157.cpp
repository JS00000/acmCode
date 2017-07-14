#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 10007
using namespace std;

char ans[maxn];

char* solve(char *s)
{
    ans[0] = '0';
    ans[1] = '.';
    int len = strlen(s);
    for (; len > 0 && s[len-1] == '0'; len--) {}
    if (len == 0) {
        ans[1] = '\0';
        return ans;
    }
    int j = 2;
    while (len > 0 && (s[len-1] == '0' || s[len-1] == '5')) {
        ans[j++] = s[0] >= '5'? '1': '0';
        int carry = 0;
        bool flag = 1;
        for (int i = len-1; i >= 0; i--) {
            if (s[i] >= '5') {
                s[i] = '0' + carry + (s[i] - '0')*2 - 10;
                carry = 1;
            } else {
                s[i] = '0' + carry + (s[i] - '0')*2;
                carry = 0;
            }
            if (flag && s[i] == '0') len--, flag = 0;
        }
    }
    ans[j] = '\0';
    if (len > 0 && s[len-1] != '0' && s[len-1] != '5') {
        ans[0] = 'N';
        ans[1] = 'O';
        ans[2] = '\0';
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    char s[200];
    while (T--) {
        scanf("%s", s);
        printf("%s\n", solve(s+2));
    }
    return 0;
}
