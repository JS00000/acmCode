#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

typedef long long LL;
using namespace std;
const int maxn = 100007;
const double PI = acos(-1.0);

// 3^509
// 111111101
// (3^1) * (3^4) * (3^8) * (3^16) * (3^32) * (3^64) * (3^128) * (3^256)

const unsigned long long mod = 100000007;
unsigned long long qpow(unsigned long long a,unsigned long long b)
{
    unsigned long long ans=1;
    for(int i=b;i;i>>=1,a=a*a%mod)
        if(i&1)ans=ans*a%mod;
    return ans;
}


int main(int argc, char const *argv[])
{
    double a = pow(2, 1./2);
    printf("%f\n", a);
    return 0;
}
