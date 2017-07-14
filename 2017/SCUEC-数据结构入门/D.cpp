#include <cmath>
#include <queue>
#include <cstdio>
#include <algorithm>
#define maxn 1000007
#define maxm 1007
using namespace std;

int belong[maxn];
bool hasq[maxm];

int main()
{
    int t, kase = 0;
    scanf("%d", &t);
    while(t)
    {
        int n, id;
        for (int i = 0; i < t; ++i)
        {
            scanf("%d", &n);
            for (int j = 0; j < n; ++j)
            {
                scanf("%d", &id);
                belong[id] = i;
            }
            hasq[i] = 0;
        }
        queue<int> teamq;
        queue<int> memq[maxm];
        printf("Scenario #%d\n", ++kase);
        char cmd[10];
        scanf("%s", cmd);
        while(cmd[0] != 'S')
        {
            scanf("%d", &id);
            if (cmd[0] == 'E')
            {
                if (!hasq[belong[id]])
                {
                    hasq[belong[id]] = 1;
                    teamq.push(belong[id]);
                    memq[belong[id]].push(id);
                }
                else memq[belong[id]].push(id);
            }
            else
            {
                printf("%d\n", memq[teamq.front()].front());
                memq[teamq.front()].pop();
                if (memq[teamq.front()].empty())
                {
                    hasq[teamq.front()] = 0;
                    teamq.pop();
                }
            }
            scanf("%s", cmd);
        }
        printf("\n");
        scanf("%d", &t);
    }
    return 0;
}
