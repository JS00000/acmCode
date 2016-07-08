#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
using namespace std;

const double eps = 1e-6;
const double pi = acos(-1.0);

struct Point
{
    double x;
    double y;
};
typedef Point Vector;

const Point O = {0, 0};

int sgn(double x)
{
    return (x > eps) - (x < -eps);
}

Vector operator +(Vector v1, Vector v2)
{
    v1.x += v2.x;
    v1.y += v2.y;
    return v1;
}

Vector operator -(Vector v1, Vector v2)
{
    v1.x -= v2.x;
    v1.y -= v2.y;
    return v1;
}

Vector operator *(Vector v, double t)
{
    v.x *= t;
    v.y *= t;
    return v;
}

Vector operator /(Vector v, double t)
{
    v.x /= t;
    v.y /= t;
    return v;
}

double operator *(Vector v1, Vector v2)
{
    return v1.x*v2.x + v1.y*v2.y;
}

double operator ^(Vector v1, Vector v2)
{
    return v1.x*v2.y - v2.x*v1.y;
}

double dis2(Vector v)
{
    return v.x*v.x + v.y*v.y;
}

double dis(Vector v)
{
    return sqrt(v.x*v.x + v.y*v.y);
}

Vector Rotation(Vector v, double angle)//计算向量v逆时针旋转angle角度后得到的向量
{
    Vector ans;
    double Sin = sin(angle), Cos = cos(angle);
    ans.x = v.x*Cos - v.y*Sin;
    ans.y = v.y*Cos + v.x*Sin;
    return ans;
}

double n, r;
Point P, C;

void input()
{
    scanf("%lf%lf%lf%lf%lf%lf", &n, &C.x, &C.y, &r, &P.x, &P.y);
}

void solve()
{
    double d = abs(((P - C)^(O - C)))/dis(P - O);
    if(sgn(d - r) > 0)
    {
        if(sgn(P.y) == 0)
            printf("infinite\n");
        else
            printf("0.0000\n");
        return;
    }
    double CPO = acos((dis2(P - C) + dis2(P - O) - dis2(C - O))/(2*dis(P - C)*dis(P - O)));;
    double incident = asin(sin(CPO)*dis(P - C)/r);
    double refractive = asin(sin(incident)/n);
    int flag = sgn((O - P)^(C - P));
    Vector CA = Rotation(P - O, incident*flag)*r/dis(P - O);//A为入射点
    Vector CB = Rotation(CA, pi - 2*refractive*flag);       //B为出射点
    Vector final_light = Rotation(CB, incident*flag);
    Point B = C + CB;
    if(sgn(B.y) == 0)
    {
        if(sgn(final_light.y) == 0)
            printf("infinite\n");
        else
        {
            if(sgn(B.x) == 0)
                printf("0.0000\n");
            else
                printf("%.4f\n", B.x);
        }
        return;
    }
    if(sgn(B.y)*sgn(final_light.y) >= 0)
    {
        printf("bad light\n");
        return;
    }
    double ans = B.x - B.y*final_light.x/final_light.y;
    if(sgn(ans) == 0)
        printf("0.0000\n");
    else
        printf("%.4f\n", ans);
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
    return 0;
}
