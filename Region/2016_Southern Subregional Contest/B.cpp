#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100
using namespace std;

bool cmp(int i, int j)
{
    printf("? %d %d\n", i, j);
    fflush(stdout);
    char c[10];
    scanf("%s", c);
    return c[0]=='<';
}

void solve()
{
    int n;
    scanf("%d", &n);
    if (n == 1){
        printf("! 1 1\n");
        fflush(stdout);
        return;
    }
    int ma, mi;
    if (n&1){
        ma = mi = 1;
    }
    else{
        if (cmp(1, 2)){
            mi = 1, ma = 2;
        }else{
            ma = 1, mi = 2;
        }
    }
    for (int i = n&1?2:3; i<=n; i+=2){
        if (cmp(i, i+1)){
            if (cmp(i, mi)) mi = i;
            if (cmp(ma, i+1)) ma = i+1;
        }else{
            if (cmp(i+1, mi)) mi = i+1;
            if (cmp(ma, i)) ma = i;
        }
    }
    printf("! %d %d\n", mi, ma);
    fflush(stdout);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        solve();
    }
    return 0;
}
