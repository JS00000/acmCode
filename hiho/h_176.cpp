#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
#define maxm 20007
using namespace std;

int n, m, edge_idx;
int head[maxn];
struct node
{
    int to, next, w;
}edges[maxm*2];

inline void add_edge(int u, int v, int w)
{
    edges[edge_idx].w = w;
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

char cons[maxn];
int digit[maxn], id, ass[26];
bool ch[26];

int main()
{
    memset(ch, 0, sizeof(ch));
    memset(ass, 0, sizeof(ass));
    memset(head, -1, sizeof(head));
    edge_idx = 0;
    id = 0;
    int N, T, K = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", cons);
        int d = 0, flag = 0, token = -1, op = -1;
        for (int i = 0; cons[i]; i++) {
            if (isdigit(cons[i])) {
                flag = 1;
                d = d * 10 + cons[i] - '0';
            } else {
                // < or <= or ABC
                if (flag) {
                    if (token != -1) 
                        add_edge(id + 26, token, op);
                    token = id + 26;
                    digit[id++] = d;
                    d = 0;
                    flag = 0;
                }
                if (cons[i] == '<') {
                    if (cons[i+1] == '=') {
                        i++;
                        op = 1;
                    } else {
                        op = 0;
                    }
                } else {
                    if (token != -1) {
                        add_edge(cons[i] - 'A', token, op);
                        token = cons[i] - 'A';
                        if (!ch[cons[i] - 'A']) K++, ch[cons[i] - 'A'] = 1;
                    } else {
                        token = cons[i] - 'A';
                        if (!ch[cons[i] - 'A']) K++, ch[cons[i] - 'A'] = 1;
                    }
                }
            }
        }
        if (flag) {
            add_edge(id + 26, token, op);
            digit[id++] = d;
            d = 0;
            flag = 0;
        }
    }
    scanf("%d", &T);
    char v;
    int temp;
    while (T--) {
        for (int i = 0; i < K; i++) {
            scanf("%s%d", &v, &temp);
            ass[v-'A'] = temp;
        }
        bool p = true;
        for (int i = 0; i < 26 + id; i++) {
            for (int k = head[i]; k != -1; k = edges[k].next) {
                int j = edges[k].to;
                int x = i < 26 ? ass[i]: digit[i - 26];
                int y = j < 26 ? ass[j]: digit[j - 26];
                if ((edges[k].w && x < y) || (!edges[k].w && x <= y)) 
                    p = false;
                // if (edges[k].w) 
                //     printf("debug k[%d]>=k[%d] %d>=%d? %d\n", i, j, x, y, x>=y);
                // if (!edges[k].w) 
                //     printf("debug k[%d]>k[%d] %d>%d? %d\n", i, j, x, y, x>y);
            }
        }
        printf("%s\n", p ? "Yes": "No");
    }
    return 0;
}
