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
    LL n, k, last, now;
    while(cin >> n >> k)
    {
        last = -1;
        now = n;
        while(last != now)
        {
            last = now;
            now = now/2 + k;
        }
        cout << now << endl;
    }
    return 0;
}
