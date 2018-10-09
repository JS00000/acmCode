#include <iostream>
#include <cstdio>
#include <cmath>


int gcd(int a, int b)
{
    return b==0?a:gcd(b, a%b);
}

int main()
{
    printf("%d\n", gcd(10,0));
    return 0;
}