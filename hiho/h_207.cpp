#include <cstdio>
#include <algorithm>
using namespace std;

int a[4];

int check(int n1, int n2, int n3, int n4)
{
    if (n1 * 10 + n2 > 23) return -1;
    if (n3 * 10 + n4 > 59) return -1;
    return (n1 * 10 + n2) * 60 + n3 * 10 + n4;
}

int main()
{
    scanf("%d%d%d%d", a, a+1, a+2, a+3);
    sort(a, a+4);
    int ans = -1, t0, t1, t2, t3;
    do {
        int t = check(a[0], a[1], a[2], a[3]);
        if (ans < t) {
            ans = t;
            t0 = a[0];
            t1 = a[1];
            t2 = a[2];
            t3 = a[3];
        }
    } while ( next_permutation(a,a+4) );
    if (ans == -1)
        printf("NOT POSSIBLE\n");
    else
        printf("%d%d:%d%d\n", t0, t1, t2, t3);
    return 0;
}
