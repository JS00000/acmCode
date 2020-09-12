#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int harmony(int x)
{
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main()
{
    // for (int n = 1; n <= 1000; n++) {
    int n = 1000;
        for (int b = 1; b <= n; b++) {
            int cnt = 0;
            for (int a = 1; a < b; a++) {
                if (harmony(a) > harmony(b)) {
                    cnt++;
                }
            }
            printf("%d,", cnt);
        }
        // printf("%d,", harmony(n));
    // }
    printf("\n");
    return 0;
}
