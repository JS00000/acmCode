#include<iostream>  
#include<stdio.h>  
#include<cstdio>  
#include<stdlib.h>  
#include<vector>  
#include<string>  
#include<cstring>  
#include<cmath>  
#include<algorithm>  
#include<stack>  
#include<queue>  
#include<ctype.h>  
#include<map>  
#include<time.h>  
#include<bitset>  
using namespace std;  
//hdu 5120  
  
int T;  
double r;  
double R;  
double x[2];  
double y[2];  
double ans;  
const double eps=1e-9;  
class circle  
{  
public:  
    double x;  
    double y;  
    double r;  
    circle(){x=0;y=0;r=0;}  
    circle(double xx,double yy,double rr)  
    {  
        x=xx;  
        y=yy;  
        r=rr;  
    }  
};  
circle cir[25];  
double pi=acos(-1.0);  
double dis(circle r1,circle r2)  
{  
    double xd=r1.x-r2.x;  
    double yd=r1.y-r2.y;  
    //cout<<"dis "<<xd<<" "<<yd<<endl;  
    if(abs(xd)<eps&&abs(yd)<eps) return 0;  
    else return sqrt(xd*xd+yd*yd);  
}  
double intersection(circle c1,circle c2)  
{  
    double d=dis(c1,c2);  
    //cout<<"d: "<<d<<endl;  
    if(d<eps) return min(pi*c1.r*c1.r,pi*c2.r*c2.r);//特判两个圆重合的case  
    else if(d>=(c1.r+c2.r)) return 0;  
    else if(d<fabs(c1.r-c2.r))  
    {  
       // cout<<"haha  "<<d<<" "<<fabs(c1.r-c2.r)<<endl;  
        //cout<<"area: "<<pi*c1.r*c1.r<<" "<<pi*c2.r*c2.r<<endl;  
        return min(pi*c1.r*c1.r,pi*c2.r*c2.r);  
    }  
    else  
    {  
        double h=(c1.r+c2.r+d)/2.0;  
        double s=sqrt(h*(h-c1.r)*(h-c2.r)*(h-d))*2.0;//三角形面积的海伦公式  
        double angle1=acos((c1.r*c1.r+d*d-c2.r*c2.r)/2.0/c1.r/d);//余弦定理  
        double angle2=acos((c2.r*c2.r+d*d-c1.r*c1.r)/2.0/c2.r/d);  
        double s1=angle1*c1.r*c1.r;  
        double s2=angle2*c2.r*c2.r;//求扇形面积  
        return s1+s2-s;//inclusive and declusive principle  
    }  
}  
int main()  
{  
    freopen("input.txt","r",stdin);  
    //freopen("data.txt","r",stdin);  
    //freopen("out1.txt","w",stdout);  
    scanf("%d",&T);  
    for(int ca=1;ca<=T;ca++)  
    {  
        scanf("%lf %lf",&r,&R);  
        scanf("%lf %lf",&x[0],&y[0]);  
        scanf("%lf %lf",&x[1],&y[1]);  
        ans=0;  
        circle c1=circle(x[0],y[0],r);  
        circle c2=circle(x[0],y[0],R);  
        circle c3=circle(x[1],y[1],r);  
        circle c4=circle(x[1],y[1],R);  
        // cout<<"inter: "<<intersection(c2,c4)<<" "<<intersection(c1,c4)<<" "<<intersection(c2,c3)<<" "<<intersection(c1,c3)<<endl;  
        ans=intersection(c2,c4)-intersection(c1,c4)-intersection(c2,c3)+intersection(c1,c3);  
        printf("Case #%d: %.6lf\n",ca,ans);  
    }  
     return 0;  
}  