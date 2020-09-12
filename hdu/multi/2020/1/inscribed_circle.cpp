#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
 
const double eps=1e-8;
const double inf=1e9;
const int MAXN=210;
int m;//保存多边形的点数
double r;//保存内移距离
int cCnt,curCnt;//此时cCnt为最终切割得到的多边形的顶点数、暂存顶点个数
struct point
{
    double x,y;
};
point points[MAXN],p[MAXN],q[MAXN];//读入的多边形的顶点（顺时针）、p为存放最终切割得到的多边形顶点的数组、暂存核的顶点
void getline(point x,point y,double &a,double &b,double   &c) //两点x、y确定一条直线a、b、c为其系数
{
    a = y.y - x.y;
    b = x.x - y.x;
    c = y.x * x.y - x.x * y.y;
}
void initial()
{
    for(int i = 1; i <= m; ++i)p[i] = points[i];
    p[m+1] = p[1];
    p[0] = p[m];
    cCnt = m;
}
point intersect(point x,point y,double a,double b,double c)
{
    double u = fabs(a * x.x + b * x.y + c);
    double v = fabs(a * y.x + b * y.y + c);
    point pt;
    pt.x=(x.x * v + y.x * u) / (u + v);
    pt.y=(x.y * v + y.y * u) / (u + v);
    return  pt;
}
void cut(double a,double b ,double c)
{
    curCnt = 0;
    for(int i = 1; i <= cCnt; ++i)
    {
        if(a*p[i].x + b*p[i].y + c >= 0)q[++curCnt] = p[i];
        else
        {
            if(a*p[i-1].x + b*p[i-1].y + c > 0)
            {
                q[++curCnt] = intersect(p[i],p[i-1],a,b,c);
            }
            if(a*p[i+1].x + b*p[i+1].y + c > 0)
            {
                q[++curCnt] = intersect(p[i],p[i+1],a,b,c);
            }
        }
    }
    for(int i = 1; i <= curCnt; ++i)p[i] = q[i];
    p[curCnt+1] = q[1];
    p[0] = p[curCnt];
    cCnt = curCnt;
}
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else return x<0?-1:1;
}
void solve()
{
       initial();
      for(int i = 1; i <= m; ++i){
          point ta, tb, tt;
          tt.x = points[i+1].y - points[i].y;
          tt.y = points[i].x - points[i+1].x;
          double k = r / sqrt(tt.x * tt.x + tt.y * tt.y);
          tt.x = tt.x * k;
          tt.y = tt.y * k;
          ta.x = points[i].x + tt.x;
          ta.y = points[i].y + tt.y;
          tb.x = points[i+1].x + tt.x;
          tb.y = points[i+1].y + tt.y;
          double a,b,c;
          getline(ta,tb,a,b,c);
          cut(a,b,c);
      }
}
void GuiZhengHua(){ //规整化方向，逆时针变顺时针，顺时针变逆时针
    for(int i = 1; i < (m+1)/2; i ++)
      swap(points[i], points[m-i]);
}
int main()
{
    while (scanf("%d",&m)!=EOF){
        if (m==0) break;
        for (int i=1;i<=m;i++)
            scanf("%lf%lf",&points[i].x,&points[i].y);
        GuiZhengHua();
        points[m+1]=points[1];
        double left=0,right=inf,mid;
        while ((right-left)>=eps) {//二分求半径
            mid=(left+right)/2.0;
           // cout<<1<<endl;
            r=mid;
            solve();
            if (cCnt<=0) right=mid;
            else left=mid;
        }
        printf("%.6f\n",left);
    }
    return 0;
}
