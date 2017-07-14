#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int t, z;
};

bool cmp(node a, node b)
{
    return a.z < b.z;
}

int calc(int a, int b, int c, int d)
{
    if ((a<2 || (a==2 && b < 4)) && c<6) return (a*10+b)*60+c*10+d;
    return -1;
}

int main()
{
    node t[4];
    int ans[4], maxt = -1, temp;
    for (int i = 0; i < 4; i++) cin >> t[i].t, t[i].z = i;
    do {
        temp = calc(t[0].t, t[1].t, t[2].t, t[3].t);
        if (maxt < temp)
        {
            maxt = temp;
            ans[0] = t[0].t, ans[1] = t[1].t, ans[2] = t[2].t, ans[3] = t[3].t;
        }
    } while ( std::next_permutation(t,t+4,cmp) );
    if (maxt == -1) printf("NOT POSSIBLE\n");
    else printf("%d%d:%d%d\n", ans[0], ans[1], ans[2], ans[3]);
    return 0;
}
