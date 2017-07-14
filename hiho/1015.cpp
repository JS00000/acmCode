// KMP
#include <cstdio>
#include <cstring>
#define maxn 1007
using namespace std;


int find_substring(char pattern[], char text[])
{
    int ret = 0;
    int n = strlen(pattern);
    int next[n+1];
    for (int i = 0; i <= n; ++i) next[i] = 0;
    for (int i = 1; i < n; ++i)
    {
        int j = i;
        while(j > 0)
        {
            j = next[j];
            if (pattern[j] == pattern[i])
            {
                next[i+1] = j+1;
                break;
            }
        }
    }
    printf("     i  = ");
    for (int i = 0; i <= n; ++i) printf("%d ", i);
    printf("\n");
    printf("next[i] = ");
    for (int i = 0; i <= n; ++i) printf("%d ", next[i]);
    printf("\n");
    int m = strlen(text);
    for (int i = 0, j = 0; i < m; ++i)
    {
        if (j < n && text[i] == pattern[j]) j++;
        else
        {
            while(j > 0)
            {
                j = next[j];
                if (text[i] == pattern[j])
                {
                    j++;
                    break;
                }
            }
        }
        if (j == n) ret++;
        // text[i-n+1 ~ i] = pattern[0~n-1]
    }
    return ret;
}

int n;
char p[10007], t[1000007];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s%s", p, t);
        printf("%d\n", find_substring(p,t));
    }
    return 0;
}
