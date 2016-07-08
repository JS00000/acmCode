#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
using namespace std;

const int MAX_CNT = 3*1e7;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int N, M;
char game[5][5];
int que[MAX_CNT], tot, goal;

const int HASH_MOD = 1e6 + 7;
const int NODE_CNT = 1.1*1e6;
struct Node
{
    int state;
    int next;
    Node(){}
    Node(int s, int n)
    {
        state = s;
        next = n;
    }
};

struct HashTable
{
    int head[HASH_MOD];
    Node node[NODE_CNT];
    int cnt;

    void Clear()
    {
        memset(head, -1, sizeof(head));
        cnt = 0;
    }

    bool Insert(int s)
    {
        int tableID = s%HASH_MOD;
        for(int i = head[tableID]; node[i].state != -1; i = node[i].next)
        {
            if(node[i].state == s)
                return false;
        }
        node[cnt] = Node(s, head[tableID]);
        head[tableID] = cnt++;
        return true;
    }
};
HashTable flag[5][5];

int Encode(int x, int y, int s)
{
    return ((x*M + y) << (N*M)) + s;
}

void Decode(int state, int &x, int &y, int &s)
{
    int temp = 1 << (N*M);
    int man = state/temp;
    x = man/M;
    y = man%M;
    s = state%temp;
}

bool Inside(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

bool HasBox(int s, int x, int y)
{
    int digit = x*M + y;
    return s&(1 << digit);
}

bool Move(int x, int y, int s, int d)
{
    x += dx[d];
    y += dy[d];
    int old = Encode(x - dx[d], y - dy[d], s);
    if(!Inside(x, y) || game[x][y] == '*')
        return false;
    if(HasBox(s, x, y))
    {
        int x2 = x + dx[d], y2 = y + dy[d];
        if(!Inside(x2, y2) || game[x2][y2] == '*' || HasBox(s, x2, y2))
            return false;
        s -= 1 << (x*M + y);
        s += 1 << (x2*M + y2);
    }
    if(s == goal)
        return true;
    if(flag[x][y].Insert(s))
        que[tot++] = Encode(x, y, s);
    return false;
}

void Initial()
{
    tot = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            flag[i][j].Clear();
    }
}

void input()
{
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%s", game[i]);
}

void solve()
{
    goal = 0;
    int start_x = 0, start_y = 0, start_s = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(game[i][j] == 'b' || game[i][j] == '+')
                start_s += 1 << (i*M + j);
            if(game[i][j] == 'w' || game[i][j] == '+')
                goal += 1 << (i*M + j);
            if(game[i][j] == 'm')
            {
                start_x = i;
                start_y = j;
            }
        }
    }
    if(start_s == goal)
    {
        printf("%d\n", 0);
        return;
    }
    Initial();
    if(flag[start_x][start_y].Insert(start_s))
        que[tot++] = Encode(start_x, start_y, start_s);
    int cnt = 0, step = 1;
    while(cnt < tot)
    {
        for(int sz = tot; cnt < sz; cnt++)
        {
            int x, y, s;
            Decode(que[cnt], x, y, s);
            for(int i = 0; i < 4; i++)
            {
                if(Move(x, y, s, i))
                {
                    printf("%d\n", step);
                    return;
                }
            }
        }
        step++;
    }
    printf("-1\n");
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        input();
        solve();
    }
}
