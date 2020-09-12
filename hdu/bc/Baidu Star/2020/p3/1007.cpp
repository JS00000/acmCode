#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int play(int x, int y, int z)
{
    int ret = 10000;
    int ka = 1000 / y + ((1000 % y == 0) ? 0: 1);
    int kb = 1000 / x + ((1000 % x == 0) ? 0: 1);
    int kk = min(ka, kb);
    for (int i = 0; i <= kk; i++) {
        int a = 1000, b = 1000, c = 1000;
        int cnt = i;
        a -= cnt * y;
        b -= cnt * x;
        if (a > 0) {
            int cnta = a / z + ((a % z == 0) ? 0: 1);
            int cntc = c / x + ((c % x == 0) ? 0: 1);
            if (cnta > cntc) {
                continue;
            } else if (cnta == cntc) {
                cnt += cnta;
                ret = min(ret, cnt);
                continue;
            } else {
                cnt += cnta;
                c -= cnta * x;
            }
        }
        if (b > 0) {
            int cntb = b / z + ((b % z == 0) ? 0: 1);
            int cntc = c / y + ((c % y == 0) ? 0: 1);
            cnt += min(cntb, cntc);
        }
        ret = min(ret, cnt);
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int mini = 10000;
        mini = min(mini, play(x, y, z));
        mini = min(mini, play(x, z, y));
        mini = min(mini, play(y, x, z));
        mini = min(mini, play(y, z, x));
        mini = min(mini, play(z, x, y));
        mini = min(mini, play(z, y, x));
        printf("%d\n", mini);
    }
    return 0;
}
