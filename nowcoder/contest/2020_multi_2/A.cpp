#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2000007
using namespace std;

char s[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        scanf("%s", s);
        int f = 0, c = 0;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '0') {
                c++;
            } else if (s[i] == '1') {
                if (c > 0) {
                    c--;
                    f++;
                } else {
                    c++;
                }
            } else {
                f++;
            }
        }
        printf("%d\n", f);
    }
    return 0;
}
