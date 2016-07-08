#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

typedef long long LL;

double f[60][600];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, n, m, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        memset(f, 0, sizeof(f));
        for (int w = k - 1; w <= m - n + k - 1; w++)
        {
            f[k][w] = (m - w - n + k + 1) / 2.0;
        }
        for (int j = k - 1; j > 0; j--)
        {
            for (int w = j - 1; w <= m - n + j -1; w++)
            {
                double sum = 0;
                for (int i = w + 1; i <= m - n + j; i++) sum += f[j+1][i];
                f[j][w] = sum / (m - w - n + j);
            }
        }
        printf("%.6f\n", f[1][0]);
//        cout << f[1][0] << endl;
    }
    return 0;
}
