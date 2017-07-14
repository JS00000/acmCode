#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

unsigned long long calc(char temp[])
{
    unsigned long long ret = 0;
    for (int i = 0; i < 8; ++i)
        ret += (temp[i] - 'a' + 1) * (1<<(i*8));
    return ret;
}

int main()
{
    char S[maxn*maxn], temp[10], T[10];
    scanf("%s", S);
    int len = strlen(S), n, k;
    map<unsigned long long, int> mp;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", temp);
        sort(temp,temp+8);
        k = calc(temp);
        if (!mp.count(k)) mp[k] = 1;
        else mp[k]++;
    }
    for (int i = 0; i < 7; ++i) T[i] = S[i];
    int j = 7, ans = 0;
    for (int i = 7; i < len; ++i)
    {
        T[j] = S[i];
        for (int l = 0; l < 8; ++l) temp[l] = T[l];
        sort(temp,temp+8);
        k = calc(temp);
        if (mp.count(k)) ans += mp[k];
        j = (j+1) % 8;
    }
    printf("%d\n", ans);
    return 0;
}
