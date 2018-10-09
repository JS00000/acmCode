#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
using namespace std;

typedef long long ll;

ll a[maxn];
ll z[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lld", a + i);
        int zi = 0;
        ll buysum = 0, sellsum = 0;
        // priority_queue<ll> q;
        priority_queue<int, vector<int>, greater<int> > q;
        for (int i = 0; i < n; i++) {
            if (q.empty()) {
                if (zi == 0 || (zi > 0 && a[i] <= z[zi-1])) {
                    z[zi++] = a[i];
                    // printf("debug %d step 1 store %lld\n", i+1, a[i]);
                } else {
                    zi--;
                    buysum += z[zi];
                    sellsum += a[i];
                    q.push(a[i]);
                    // printf("debug %d step 2 sell %lld\n", i+1, a[i]);
                }
            } else {
                ll t = q.top();
                if (a[i] > t) {
                    q.pop();
                    q.push(a[i]);
                    sellsum += a[i] - t;
                    // printf("debug %d step 3 add %lld\n", i+1, a[i] - t);
                } else {
                    t = a[i];
                }
                if (zi == 0 || (zi > 0 && t <= z[zi-1])) {
                    z[zi++] = t;
                    // printf("debug %d step 4 store %lld\n", i+1, t);
                } else {
                    zi--;
                    buysum += z[zi];
                    sellsum += t;
                    q.push(t);
                    // printf("debug %d step 5 sell %lld\n", i+1, t);
                }
            }
        }
        printf("%lld %lu\n", sellsum - buysum, q.size()*2);
    }
    return 0;
}
