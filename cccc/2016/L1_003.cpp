#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int d[10] = {};

int main()
{
    char st[1008];
    scanf("%s", st);
    int len = strlen(st);
    for (int i = 0; i < len; ++i)
        d[st[i]-'0']++;
    for (int i = 0; i < 10; ++i)
        if (d[i]) printf("%d:%d\n", i, d[i]);
    return 0;
}
