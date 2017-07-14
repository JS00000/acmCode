#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100007
#define maxm 1000007
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);

int cmp(double x)
{
    if (fabs(x)<eps) return 0;
    if (x>0) return 1;
    return -1;
}

struct point
{
    double x,y;
    point(){}
    point(double a, double b) : x(a), y(b) {}
    void input()
    {
        scanf("%lf%lf", &x, &y);
    }
    friend point operator+(const point &a, const point &b)
    {
        return point(a.x+b.x, a.y+b.y);
    }
    friend point operator-(const point &a, const point &b)
    {
        return point(a.x-b.x, a.y-b.y);
    }
    friend bool operator==(const point &a, const point &b)
    {
        return cmp(a.x-b.x) == 0 && cmp(a.y-b.y) == 0;
    }
    friend point operator*(const point &a, const double &b)
    {
        return point(a.x*b, a.y*b);
    }
    friend point operator*(const double &a, const point &b)
    {
        return point(a*b.x, a*b.y);
    }
    friend point operator/(const point &a, const double &b)
    {
        return point(a.x/b, a.y/b);
    }
    double norm()
    {
        return sqrt(x*x+y*y);
    }
};
double det(const point &a, const point &b)
{
    return a.x*b.y-a.y*b.x;
}
double dot(const point &a, const point &b)
{
    return a.x*b.x+a.y*b.y;
}
double dist(const point &a, const point &b)
{
    return (a - b).norm();
}
point rotate_point(const point &p, double A)
{
    double tx = p.x, ty = p.y;
    return point(tx*cos(A) - ty*sin(A), tx*sin(A) + ty*cos(A));
}

struct line
{
    point a,b;
    line(){}
    line(point x, point y) : a(x), b(y){}
};
int xyCmp(const double p, const double mini, const double maxi)
{
    return cmp(p-mini)*cmp(p-maxi);
}
int betweenCmp(const point &a, const point &b, const point &c)
{
    if (fabs(b.x-c.x)>fabs(b.y-c.y))
    {
        return xyCmp(a.x, min(b.x,c.x), max(b.x,c.x));
    }
    else
    {
        return xyCmp(a.y, min(b.y,c.y), max(b.y,c.y));
    }
}
double cross(const point &a, const point &b, const point &c)
{
    return det(point(b.x-a.x, b.y-a.y), point(c.x-a.x, c.y-a.y));
}
int segCross(const line &l, const line &m)
{
    double s1,s2,s3,s4;
    int d1,d2,d3,d4;
    d1 = cmp(s1=cross(l.a,l.b,m.a));
    d2 = cmp(s2=cross(l.a,l.b,m.b));
    d3 = cmp(s3=cross(m.a,m.b,l.a));
    d4 = cmp(s4=cross(m.a,m.b,l.b));
    if ((d1^d2)==-2 && ((d3^d4)==-2))
    {
        return 1;
    }
    if ((d1==0 && betweenCmp(m.a, l.a, l.b)<=0)||
        (d2==0 && betweenCmp(m.b, l.a, l.b)<=0)||
        (d3==0 && betweenCmp(l.a, m.a, m.b)<=0)||
        (d4==0 && betweenCmp(l.b, m.a, m.b)<=0))
        return 2;
    return 0;
}

int L, H;
int n, m, edge_idx;
int head[maxn];
struct node
{
    int to, next;
}edges[maxm];

void add_edge(int u, int v)
{
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

line larr[maxn];
int qs[maxn], ieq, q[maxn];
bool qe[maxn];
bool visit[maxn];
void build_graph()
{
    edge_idx = ieq = 0;
    scanf("%d%d", &L, &H);
    scanf("%d", &n);
    memset(head, -1, (n+1)*sizeof(int));
    memset(qe, 0, (n+1)*sizeof(bool));
    memset(visit, 0, (n+1)*sizeof(bool));
    int x1, x2, y1, y2;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        larr[i] = line(point(x1, y1), point(x2, y2));
        if (y1 <= 0 || y2 <= 0 || x1 >= L || x2 >= L) qs[ieq++] = i;
        if (x1 <= 0 || x2 <= 0 || y1 >= H || y2 >= H) qe[i] = 1;
    }
    for (int i = 0; i < n-1; ++i)
        for (int j = i+1; j < n; ++j)
            if (segCross(larr[i], larr[j]) > 0) add_edge(i, j), add_edge(j, i);
}

bool bfs(int u)
{
    if (qe[u]) return 1;
    int iq = 0, i = 0;
    q[iq++] = u;
    visit[u] = 1;
    while(i < iq)
    {
        for (int k = head[q[i]]; k != -1; k = edges[k].next)
        {
            int v = edges[k].to;
            if (!visit[v])
            {
                if (qe[v]) return 1;
                visit[v] = 1;
                q[iq++] = v;
            }
        }
        i++;
    }
    return 0;
}


int main(int argc, char const *argv[])
{
    build_graph();
    for (int i = 0; i < ieq; i++)
        if (bfs(qs[i])) 
        {
            printf("0\n");
            return 0;
        }
    printf("1\n");
    return 0;
}
