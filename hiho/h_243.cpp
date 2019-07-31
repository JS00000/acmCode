#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;

char s[maxn];

int main()
{
    scanf("%s", s);
    int mini = maxn;
    int l, r = 0;
    int len = strlen(s);
    int pi = 0, po = 0, ph = 0;
    for (int l = 0; l <= len - 4; l++) { 
        if (s[l] == 'i' || s[l] == 'o' || s[l] == 'h') {
            while (r < len) {
                if (s[r] == 'i')
                    pi++;
                if (s[r] == 'o')
                    po++;
                if (s[r] == 'h')
                    ph++;
                r++;
                if (pi == 1 && po == 1 && ph == 2) {
                    mini = min(mini, r - l);
                    break;
                }
                if (pi > 1 || po > 1 || ph > 2)
                    break;
            }
            if (s[l] == 'i')
                pi--;
            if (s[l] == 'o')
                po--;
            if (s[l] == 'h')
                ph--;
        }
    }
    if (mini == maxn) printf("-1\n");
    else printf("%d\n", mini);
    return 0;
}
