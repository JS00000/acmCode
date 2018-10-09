#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node{
    double x,y;
}nd[500];

struct Point{
    double angle;
    int id;
    bool operator < (const Point& a)const{
        return angle != a.angle ? angle < a.angle : id>a.id;
    }
} p[100000];
int n, s, R;

double dist(Node &a,Node &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int solve(double rr)
{
    int i,j,ans,tot,k,cnt;
    ans=1;
    for(i=0;i<n;i++){
        for(j=k=0;j<n;j++){
            if(j==i || dist(nd[i],nd[j])>2.0*rr)continue;
            double angle=atan2(nd[i].y-nd[j].y,nd[i].x-nd[j].x);  //注意为i-j的向量方向
            double phi=acos(dist(nd[i],nd[j])/2/rr);
            p[k].angle=angle-phi;p[k++].id=1;
            p[k].angle=angle+phi;p[k++].id=-1;
        }
        sort(p,p+k);
        for(tot=1,j=0;j<k;j++){
            tot+=p[j].id;
            ans=max(ans,tot);
        }
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &s);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &nd[i].x, &nd[i].y);
        scanf("%d", &R);
        if (n == 1 && s == 1) {
            printf("%.4f\n", (double)(R));
            continue;
        } else if (s > n) {
            printf("The cake is a lie.\n");
            continue;
        }
        double ma = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                double t = dist(nd[i], nd[j]);
                if (t > ma) 
                    ma = t;
            }
        }
        double l = 0, r = ma * 2.5, mid;
        int tt = 0;
        while ((r - l > 1e-5 || tt != s) && l < ma * 2) {
            mid = (r + l) / 2;
            tt = solve(mid);
            if (tt < s) l = mid;
            else r = mid;
            // printf("%f %f %f %d\n", l, r, mid, tt);
        }
        if (tt == s) printf("%.4f\n", mid + R);
        else printf("The cake is a lie.\n");
    }
    return 0;
}
