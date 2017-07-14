#include <cstdio>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", max(a, max(b, c)) - min(a, min(b, c)));
    return 0;
}