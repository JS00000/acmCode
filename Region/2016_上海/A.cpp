#include <cstdio>
#include <iostream>
#include <cmath>
#define pi acos(-1)
#define eps 1e-3
using namespace std;
int t;
double ax,ay,bx,by,vx,vy,rx,ry,jx,jy,r;
void rotate(double &sx,double &sy,double sita)
{
    double x=sx,  y=sy;
    sx=x*cos(sita)+y*sin(sita);
    sy=y*cos(sita)-x*sin(sita);
}
void move()
{
    ax-=rx;  bx-=rx;
    ay-=ry;  by-=ry;
    rx=ry=0;
    double x,y;
    double sita=atan2(vy,vx);
    rotate(ax,ay,sita);
    rotate(bx,by,sita);
    rotate(vx,vy,sita);
    if (ay<-eps)
    {
        vy=-vy;
        ay=-ay;
        by=-by;
    }
}
bool bounce()
{
    return ay<r&&ax<0;
}
bool shoot()
{
    return fabs(ay-by)<eps && bx>ax;
}
bool equ(double a,double b)
{
    return fabs(sin(a)-sin(b))<eps&&fabs(cos(a)-cos(b))<eps;
}
bool hit()
{
    if (!bounce())
        return shoot();
    //bounce
    if (shoot()) return bx<0;
    jy=ay;
    jx=-sqrt(r*r-ay*ay);
    double sita=atan2(jy,jx);
    sita=pi-sita;
    sita=pi-sita*2;
    return equ(atan2(by-jy,bx-jx),sita);
}
int main()
{
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%lf%lf%lf",&rx,&ry,&r);
        scanf("%lf%lf%lf%lf",&ax,&ay,&vx,&vy);
        scanf("%lf%lf",&bx,&by);
        move();
        //printf("%f %f %f\n",rx,ry,r); printf("%f %f %f %f\n",ax,ay,vx,vy);printf("%f %f\n",bx,by);
        printf("Case #%d: ",++cas);
        if (hit()) printf("Yes\n");else printf("No\n");
    }
}