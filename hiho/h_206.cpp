#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > f(n + 1, vector<int>(n + 1, 0));
    for (int l = n; l > 0; l--)
        for (int r = l + 1; r <= n; r ++) {
            f[l][r] = 0x7fffffff;
            for (int k = l; k <= r; k++) {
                int s = 0;
                if (k > l) s = max(s, f[l][k - 1]);
                if (k < r) s = max(s, f[k + 1][r]);
                f[l][r] = min(f[l][r], s + k);
            }
        }
    cout << f[1][n] << endl;
    return 0;
}
