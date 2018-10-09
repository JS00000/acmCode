#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 107
using namespace std;

char s[maxn];
map<pair<int, int>, int> mem;

int get(int l, int r);

int f(int l, int r)
{
    if (r <= l) return 0;
    else if (s[l] == s[r]) {
        return get(l+1, r-1);
    }
    else {
        int mini = 1 + get(l+1, r);
        mini = min(mini, 1 + get(l, r-1));
        mini = min(mini, 1 + get(l+1, r-1));
        return mini;
    }
}

int get(int l, int r)
{
    if (mem.count(make_pair(l, r))) return mem[make_pair(l, r)];
    return mem[make_pair(l, r)] = f(l, r);
}

int main()
{
    mem.clear();
    scanf("%s", s);
    int n = strlen(s);
    printf("%d\n", f(0, n-1));
    return 0;
}
