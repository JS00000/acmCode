#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int words[100];

int dfs(int x, int mask)
{
    if (x >= n) return 0;
    int ret = dfs(x+1, mask);
    if ((mask & words[x]) == 0) 
        ret = max(ret, 1 + dfs(x+1, mask|words[x]));
    return ret;
}

int main()
{
    char temp[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", temp);
        words[i] = 0;
        for (int j = 0; temp[j]; j++) 
            words[i] |= (1 << (temp[j] - 'a'));
    }
    printf("%d\n", dfs(0, 0));
    return 0;
}
