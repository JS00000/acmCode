#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 107
using namespace std;

int n, l = 0, r = 0, u = 0, d = 0;
char command[maxn];

int main()
{
    scanf("%d", &n);
    scanf("%s", command);
    for (int i = 0; i < n; i++) {
        if (command[i] == 'U') u++;
        else if (command[i] == 'D') d++;
        else if (command[i] == 'L') l++;
        else if (command[i] == 'R') r++;
    }
    printf("%d\n", min(l, r) * 2 + min(u, d) * 2);
    return 0;
}
