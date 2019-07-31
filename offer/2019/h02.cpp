#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int x[5];
int y[5];
int p[5] = {0, 1, 2, 3, 4};


int main()
{
    for (int i = 0; i < 5; i++) {
        scanf("%d%d", x+i, y+i);
    }
    double ans = 1e19;
    do {
        double sum = sqrt(x[p[0]]*x[p[0]] + y[p[0]]*y[p[0]]) + sqrt(x[p[4]]*x[p[4]] + y[p[4]]*y[p[4]]);
        for (int i = 1; i < 5; i++) {
            sum += sqrt((x[p[i]] - x[p[i-1]])*(x[p[i]] - x[p[i-1]]) + (y[p[i]] - y[p[i-1]])*(y[p[i]] - y[p[i-1]]));
        }
        if (sum < ans) ans = sum;
    } while ( std::next_permutation(p,p+5) );
    printf("%d\n", int(ans));
    return 0;
}
