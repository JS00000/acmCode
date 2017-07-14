#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    char c1, c2, c;
    double t1, t2, t;
    while(cin >> c1 && c1 != 'E')
    {
        cin >> t1 >> c2 >> t2;
        if (c1 > c2) c = c1, c1 = c2, c2 = c, t = t1, t1 = t2, t2 = t;
        if (c1 == 'D' && c2 == 'T') printf("T %.1f D %.1f H %.1f\n", t2, t1, t2 + 0.5555*((6.11 * exp( (5417.7530) * ( (1/273.16) - (1/(t1+273.16)) ) ) ) - 10) );
        if (c1 == 'D' && c2 == 'H') printf("T %.1f D %.1f H %.1f\n", t2 - 0.5555*((6.11 * exp( (5417.7530) * ( (1/273.16) - (1/(t1+273.16)) ) ) ) - 10), t1, t2);
        if (c1 == 'H' && c2 == 'T') printf("T %.1f D %.1f H %.1f\n", t2, 1/((1/273.16)-(log(((t1-t2)/0.5555+10)/6.11)/5417.7530))-273.16, t1);
    }
    return 0;
}
