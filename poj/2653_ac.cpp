#include<iostream>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int nMax = 100005;
const int mMax = 1005;

struct Point{
    double x, y;
}s[nMax], e[nMax];
 
double mult(Point sp, Point ep, Point op){
    return (sp.x-op.x)*(ep.y-op.y) - (ep.x-op.x)*(sp.y-op.y);
}
 
bool isInter(Point s1, Point e1, Point s2, Point e2){
    if( min(s1.x, e1.x) <= max(s2.x, e2.x) &&
        min(s1.y, e1.y) <= max(s2.y, e2.y) &&
        min(s2.x, e2.x) <= max(s1.x, e1.x) &&
        min(s2.y, e2.y) <= max(s1.y, e1.y) &&
        mult(s2, e2, s1) * mult(s2, e2, e1) <= 0 &&
        mult(s1, e1, s2) * mult(s1, e1, e2) <= 0)
        return true;
    return false;
}

int main(){
    int n, i, j;
    while(scanf("%d", &n) != EOF){
        if(n == 0) break;
        int ans[mMax], m = 0;
        for(m = 0, i = 1; i <= n; i ++){
            scanf("%lf%lf%lf%lf", &s[i].x, &s[i].y, &e[i].x, &e[i].y);
            int pos = -1;
            for(j = 0; j < m; j ++){
                if(ans[j] == -1) pos = j;
                else if(isInter(s[i], e[i], s[ans[j]], e[ans[j]])) ans[j] = -1;
            }
            if(pos == -1) ans[m ++] = i;
            else ans[pos] = i;
        }
        i = 0;
        sort(ans, ans + m);
        while(ans[i] == -1) i ++;
        printf("Top sticks:");
        while(i < m-1) printf(" %d,", ans[i ++]);
        printf(" %d.\n", ans[i]); 
    }
    return 0;
}
