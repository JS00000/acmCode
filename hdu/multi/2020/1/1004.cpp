#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n == 1) printf("26\n");
        else if (n == 2) printf("676\n");
        else if (n == 3) printf("17576\n");
        else printf("15600\n");
    }
    return 0;
}
