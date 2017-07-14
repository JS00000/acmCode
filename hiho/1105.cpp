#include <queue>
#include <cstdio>
int main()
{
    std::priority_queue<int> q;
    int n, w;
    char s[8];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", s);
        if (s[0] == 'A') scanf("%d", &w), q.push(w);
        else printf("%d\n", q.top()), q.pop();
    }
    return 0;
}
