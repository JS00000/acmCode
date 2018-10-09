#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;



int main()
{
    freopen("in.txt", "w", stdout);
    printf("150\n");
    for (int i = 1; i <= 50; i++)
    {
        printf("%d\n", i*i*i-1);
        printf("%d\n", i*i*i);
        printf("%d\n", i*i*i+1);
    }
    return 0;
}
