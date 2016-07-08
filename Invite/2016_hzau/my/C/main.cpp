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

int main()
{
    int t;
    string color, last;
    LL f[2];
    int pos;
    cin >> t;
    while(t--)
    {
        f[0] = f[1] = 0;
        pos = 0;
        cin >> color;
        last = "";
        while(color != "END")
        {
            if (color != last)
            {
                f[pos]++;
            }
            else
            {
                pos ^= 1;
                f[pos]++;
            }
            last = color;
            cin >> color;
        }
        cout << f[0] * f[1] << endl;
    }
    return 0;
}
