#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

typedef union {
  unsigned long long i;
  double f;
}u;

int main()
{
    u u1;
    u1.f = 0.25;
    printf("%llx\n", u1.i);
    return 0;
}
