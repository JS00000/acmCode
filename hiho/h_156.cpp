#include <set>
#include <vector>
#include <cstdio>
#define maxn 55

using namespace std;

int n, m, tot;
int q[maxn*maxn*2];
char mp[maxn][maxn];
bool visit[maxn][maxn];
set<int> area_set;
set<vector<int> > shape_set;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int ii, int jj)
{
    int x, y;
    int area = 1;
    int iq = 0, i = 0;
    vector<int> shape;
    shape.push_back(0);
    visit[ii][jj] = 1;
    q[iq++] = ii;
    q[iq++] = jj;
    while(i < iq)
    {
        x = q[i++];
        y = q[i++];
        for (int k = 0; k < 4; k++)
        {
            if (x + dx[k] >= 0 && x + dx[k] < n && y + dy[k] >= 0 && y + dy[k] < m && !visit[x+dx[k]][y+dy[k]] && mp[x+dx[k]][y+dy[k]] == '#')
            {
                visit[x+dx[k]][y+dy[k]] = 1;
                area++;
                shape.push_back((x+dx[k]-ii)*m+y+dy[k]-jj);
                q[iq++] = x+dx[k];
                q[iq++] = y+dy[k];
            }
        }
    }
    area_set.insert(area);
    shape_set.insert(shape);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", mp[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visit[i][j] = 0;
    tot = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visit[i][j] && mp[i][j] == '#') bfs(i, j), tot++;
    printf("%d %lu %lu\n", tot, area_set.size(), shape_set.size());
    return 0;
}
