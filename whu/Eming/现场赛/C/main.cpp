#include <cstdio>
#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.1415926

using namespace std;

int main(int argc, char *argv[])
{
    int T,x,y,z,h,r0;
    double r,ans;
    double theta,theta1,theta2,theta3,theta4,rr;
    cin >> T;
    while(T--)
    {
     cin >> x >> y >> z >> h >> r0;
     r = z*r0/double(h);
     if  (x>=r&&y>=r)
     {
         ans = r*r*PI;
     }
     else if (x>=r&&y<=r)
     {
          theta = acos(y/r);
          ans = r*r*(PI-theta);
          ans += y*sqrt(r*r-y*y);
     }
     else if (x<=r&&y>=r)
     {
          theta = acos(x/r);
          ans = r*r*(PI-theta);
          ans += x*sqrt(r*r-x*x);
     }
     else if (x<=r&&y<=r&&(x*x+y*y)>=r*r)
     {
          theta1 = acos(x/r);
          theta2 = acos(y/r);
          ans = r*r*(PI-theta1-theta2);
          ans += x*sqrt(r*r-x*x)+y*sqrt(r*r-y*y);
     }
     else
     {
         rr = sqrt(x*x+y*y);
         theta1 = acos(x/r);
         theta2 = acos(x/rr);
         theta3 = acos(y/rr);
         theta4 = acos(y/r);
         ans = r*r*(2*PI-theta1-theta2-theta3-theta4)/2;
         ans+= (sqrt(rr*rr-x*x)+sqrt(r*r-x*x))*x/2;
         ans+= (sqrt(rr*rr-y*y)+sqrt(r*r-y*y))*y/2;
     } 
     printf("%.2lf\n",ans);
    }
    return 0;
}
