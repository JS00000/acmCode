#include <iostream>

using namespace std;
typedef long long LL;
LL ans[160] = {0};

int main()
{
    int n;
    LL ret;
    while(cin >> n, n)
    {
        if(ans[n])
        {
            cout << ans[n] << endl;
            continue;
        }
        for (int m = 2;;m++)
        {
            ret = 0;
            for (int i = 2; i < n; i++)
            {
                ret = (ret+m)%i;
            }
            ret = (ret+1)%n;

            if (ret == 1)
            {
                ans[n] = m;
                cout << m << endl;
                break;
            }
        }
    }
    return 0;
}
