#include <cstdio>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, a[60][10];
    double b[60], c[10];
    // cout.precision(2);
    // cout.setf(ios::fixed);

    while(~scanf("%d%d", &n, &m))
    // while(cin >> n >> m)
    {
        for (int i = 0; i < n; ++i)
        {
            double sum = 0;
            for (int j = 0; j < m; ++j)
            {
                scanf("%d", &a[i][j]);
                // cin >> a[i][j];
                sum += a[i][j];
            }
            b[i] = sum / m;
        }
        for (int j = 0; j < m; ++j)
        {
            double sum = 0;
            for (int i = 0; i < n; ++i)
                sum += a[i][j];
            c[j] = sum / n;
        }
        int ans = n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i][j] < c[j])
                {
                    ans--;
                    break;
                }
        
        for (int i = 0; i < n-1; ++i)
            printf("%.2f ", b[i]);
        printf("%.2f\n", b[n-1]);

        for (int i = 0; i < m-1; ++i)
            printf("%.2f ", c[i]);
        printf("%.2f\n", c[m-1]);

        printf("%d\n\n", ans);

        // for (int i = 0; i < n-1; ++i)
        //     cout << setiosflags(ios::fixed) << setprecision(2) << b[i] << " ";
        // cout << setiosflags(ios::fixed) << setprecision(2) << b[n-1] << endl;

        // for (int i = 0; i < m-1; ++i)
        //     cout << setiosflags(ios::fixed) << setprecision(2) << c[i] << " ";
        // cout << setiosflags(ios::fixed) << setprecision(2) << c[m-1] << endl;

        // cout << ans << endl << endl;

    }
    return 0;
}
