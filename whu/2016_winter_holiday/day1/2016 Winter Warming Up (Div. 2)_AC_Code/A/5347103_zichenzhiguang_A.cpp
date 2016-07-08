#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    int x, y, z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    int p = 0, q = 0;
    q += (a-x < 0)? 2*(x-a): 0;
    q += (b-y < 0)? 2*(y-b): 0;
    q += (c-z < 0)? 2*(z-c): 0;
    p += (a-x > 0)? ((a-x)/2)*2: 0;
    p += (b-y > 0)? ((b-y)/2)*2: 0;
    p += (c-z > 0)? ((c-z)/2)*2: 0;
    if(p >= q) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
